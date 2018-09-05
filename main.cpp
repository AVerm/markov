#include "markovchain.h"
#include <iostream>
#include <string>

bool arg_present(int, char* [], string);

int main(int argc, char* argv[]) {
	char filename[257];
	MarkovChain* file_chain = new MarkovChain;

	// Handle command line arguments
	if (argc <= 1 || arg_present(argc, argv, "-h") || arg_present(argc, argv, "--help")) {
		printf("\
Usage: markov [OPTION]... [FILE]... [WORDS]\n\
Creates a markov chain from a file and prints some text made from it\n\
  -h, --help               display this help and exit\n\
  -v, --version            display version information and exit\n\
  -d, --dump               print all associations after generating chain\n\
");
		return 0;
	}
	else if (arg_present(argc, argv, "-v") || arg_present(argc, argv, "--version")) {
		printf("Little markov chain toy v0.01\n");
		return 0;
	}
	else {
		int gen_status;
		gen_status = (*file_chain).generate_from_file(filename);
		if (gen_status != 0) {
			printf("Problem generating chain.\nExiting\n");
			return gen_status;
		}
	}

	if (arg_present(argc, argv, "-d") || arg_present(argc, argv, "--dump")) {
		(*file_chain).print();
		return 0;
	}

	return 0;
}

bool arg_present(int argc, char* argv[], string argument) {
	int iter; // Iterative variable
	for (iter = 0; iter < argc; iter++) {
		if (argv[iter] == argument) {
			return true;
		}
	}
	return false;
}
