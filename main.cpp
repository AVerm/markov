#include "markovchain.h"
#include <iostream>
#include <string>
#include <string.h>

bool arg_present(int, char* [], string);

int main(int argc, char* argv[]) {
	MarkovChain* file_chain = new MarkovChain;

	// Handle command line arguments
	if (argc < 3 || arg_present(argc, argv, "-h") || arg_present(argc, argv, "--help")) {
		printf("\
				Usage: markov [OPTION] [FILE] [WORDS]\n\
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
		gen_status = (*file_chain).generate_from_file(argv[argc - 2]);
		if (gen_status != 0) {
			printf("Problem generating chain.\nExiting\n");
			return gen_status;
		}
	}

	if (arg_present(argc, argv, "-d") || arg_present(argc, argv, "--dump")) {
		(*file_chain).print();
		return 0;
	}

	int n;
	n = 0;
	int current_digit;
	char current_char;
	int digit;
	for (digit = 0; argv[argc - 1][digit] != '\0'; digit++) {
		n *= 10;
		current_char = argv[argc - 1][digit];
		sscanf(&current_char, "%d", &current_digit);
		n += current_digit;
	}
	string* output;
	output = new string[n];
	output = (*file_chain).read_n_words(n);

	int iter;
	for (iter = 0; iter < n; iter++) {
		printf("%s ", output[iter].c_str());
	}
	printf("\n");

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
