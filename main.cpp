#include "markovchain.h"
#include <iostream>
#include <string>

int main() {
	string filename;
	printf("Enter a filename to be converted to Markov Chain: ");
	std::cin >> filename;

	MarkovChain* file_chain = new MarkovChain;
	(*file_chain).generate_from_file(filename);

	(*file_chain).print();

	return 0;
}
