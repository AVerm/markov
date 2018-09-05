#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using std::map;
using std::string;

class Node {
	public:
		string word;
		map<Node*, int> next;

		Node(string word) {
			this->word = word;
		}

		void add(Node* next) {
			this->next[next] ++;
		}

		Node* get_next() {
			int weight = this->total_weight();
			if (weight == 0) {
				return NULL;
			}
			// Do some math to even out the probabilities
			int end;
			end = (RAND_MAX / weight) * weight;
			int r;
			((r = rand()) >= end);
			int n = r % weight;
			return get_node_n(n); // May be nullptr!!!

		}

		void print() {
			printf("%s:\n", this->word.c_str()); // Expects a char[]
			map<Node*, int>::iterator iter;
			for (iter = this->next.begin(); iter != this->next.end(); iter++) {
				printf("\t%s\t: %d\n", iter->first->word.c_str(), iter->second); // Expects a char[]
			}
		}
	private:
		int total_weight() {
			int weight;
			weight = 0;
			map<Node*, int>::iterator iter;
			for (iter = this->next.begin(); iter != this->next.end(); iter++) {
				weight += iter->second;
			}
			return weight;
		}
		Node* get_node_n(int n) {
			map<Node*, int>::iterator iter;
			for (iter = this->next.begin(); iter != this->next.end(); iter++) {
				n -= iter->second;
				if (n <= 0) {
					return iter->first;
				}
			}
			return NULL;
		}
};

#endif
