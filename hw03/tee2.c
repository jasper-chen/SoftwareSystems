#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Starting\n");
	char buffer[100];
	char ch;
	int append = 0;
	int count = 0;
	FILE *out_file;

	while ((ch = getopt(argc, argv, "a")) != EOF){
		switch(ch){
			case 'a':
				append = 1;
				break;
			default:
				fprintf(stderr, "Unknown option");
				return 1;
		}
	}

	argv+=optind;
	argc-=optind;	

	if (argv[0] == NULL){
		out_file = fopen("output.txt", "w");
		puts("I don't see an output file");
	}

	else if (!append) {
		out_file = fopen(argv[0], "w");
		puts("I'm writing to the output file");
	}

	else if (append) {
		out_file = fopen(argv[0], "a");
		puts("I'm appending to the output file");
	}

	else {
		return 1;
	}
	
	while (scanf("%s\n", buffer) == 1){
		//copying lines to output file
		fprintf(out_file, "%s\n", buffer);
		printf("%s\n", buffer);
	}

	fclose(out_file);
	return 0;
}
