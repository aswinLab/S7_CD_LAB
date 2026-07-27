#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc < 3){
		printf("Usage : ./readme count name");
	}

	int count = atoi(argv[1]);
	char *name = argv[2];

	printf("Hello Mr/Miss %s, Your entered count is %d\n", name, count);
	exit(0);
}
