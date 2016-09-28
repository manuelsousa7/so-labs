#include <stdio.h>

int main(int args,char **argv){
	int c;
	int i;
	FILE *file;
	for(i=1;i<args;i++){
		file = fopen(argv[i], "r");
		if (file) {
    		while ((c = getc(file)) != EOF)
        		putchar(c);
    		fclose(file);
		}
	}
	return 0;
}
