#ifndef MARKOVCHAIN_H
#define MARKOVCHAIN_H

#include "graph.h"
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>

class MarkovChain {
	public:
		Graph graph;

		int generate_from_file(char filename[]) {
			std::ifstream infile;
			infile.open(filename); // Expects a char[]
			if (infile.is_open()) { // Error avoidance
				string previous_word;
				string word;
				while (infile >> word) { // While words remain
					if (!previous_word.empty()) {
						this->graph.associate(previous_word, word);
					}
					previous_word = word;
				}
				infile.close(); // Close the file to avoid memory leak
				return 0;
			}
			else {
				printf("Error opening %s!\n", filename);
				return 1;
			}
		}

		string* read_n_words(int number) {
			string* output;
			output = new string[number];
			srand(time(nullptr));
			Node* current = this->graph.rand_node();
			int iter;
			for (iter = 0; iter < number; iter++) {
				output[iter] = current->word;
				current = current->get_next();
			}
			return output;
		}

		void print() {
			this->graph.print();
		}
};

#endif
