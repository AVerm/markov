#include "markovchain.h"
#include <iostream>
#include <string>

int main() {
	char filename[257];
	printf("Enter a filename to be converted to Markov Chain: ");
	scanf("%256s", filename);

	MarkovChain* file_chain = new MarkovChain;
	(*file_chain).generate_from_file(filename);

	(*file_chain).print();

	return 0;
}
