#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <string>
#include <vector>

using std::vector;

class Graph {
	public:
		vector<Node*> nodes;

		void associate(string word, string next) {
			Node* word_node = get_node(word);
			Node* next_node = get_node(next);
			word_node->add(next_node);
		}

		void print() {
			unsigned int iter; // Iterative variable
			for (iter = 0; iter < this->nodes.size(); iter++) {
				(*this->nodes[iter]).print();
			}
		}
	private:
		int node_index(string word) {
			unsigned int iter; // Iterative variable
			int index = -1; // Index of the node
			// When this loop exits, `index` is either -1 or a
			// number between 0 and the length of `nodes`. If it is
			// -1, the word did not have an existing node. If it is
			// another number, that is the index of the node.
			for (iter = 0; iter < this->nodes.size(); iter++) {
				if (this->nodes[iter]->word == word) {
					index = iter;
					break;
				}
			}
			return index;
		}
		Node* get_node(string word) {
			int index = node_index(word); // -1 or 0<=n<this->nodes.size()
			if (index != -1) { // If the node already exists
				return this->nodes[index];
			}
			else { // If the node must be made
				Node* new_node = new Node(word);
				this->nodes.push_back(new_node);
				return new_node;
			}
		}
};

#endif
