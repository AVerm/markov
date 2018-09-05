#include "markovchain.h"
#include <stdio.h>
#include <string>

int main() {
	char filename[257];
	printf("Enter a filename to be converted to Markov Chain: ");
	fgets(filename, 256, stdin);

	MarkovChain* file_chain = new MarkovChain;
	(*file_chain).generate_from_file(filename);

	printf("\n");
	(*file_chain).print();

	return 0;
}
