#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char ch;
	int count = 0;
	/* Appends the output to the end of File instead of writing over it*/
	while ((ch = getopt(argc, argv, "a")) != EOF){
		switch(ch){
			case 'a':
				puts("Test");
				break;
			default:
				fprintf(stderr, "Unknown option");
				return 1;
		}
	}
	argv+=optind;
	argc-=optind;

	for(count = 0; count < argc; count++){
		printf(stdout, *file);
	}
	return 0;
}