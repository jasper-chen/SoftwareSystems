#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char buffer[100];
	char ch;
	int append = 0;

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

	FILE *outputFiles[argc - 1];

	int i;	
	for (i=0; i < argc; i++){
		if (append == 0){
			outputFiles[i] = fopen(argv[i], "w");
		}
		else if (append == 1){
			outputFiles[i] = fopen(argv[i], "a");
		}
	}

	while (fscanf(stdin,"%99s", buffer) == 1){
		for (int i = 0; i < argc; i++){		
			fprintf(stdout, "%s\n", buffer);
			fprintf(outputFiles[i], "%s\n", buffer);
		}	
	}
	for (int i = 0; i < argc; i++){
		fclose(outputFiles[i]);
	}
	return 0;
}
