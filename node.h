#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>
#include <stdio.h>

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

		void print() {
			printf("%s:\n", this->word.c_str()); // Expects a char[]
			map<Node*, int>::iterator iter;
			for (iter = this->next.begin(); iter != this->next.end(); iter++) {
				printf("\t%s\t: %d\n", iter->first->word.c_str(), iter->second); // Expects a char[]
			}
		}
};

#endif
