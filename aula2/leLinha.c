#include <stdio.h>

char *le_linha(){
	char *line = NULL;
    size_t n = 0;
    ssize_t result = getline(&line, &n, stdin);
    return line;
}

int main(){
	printf("%s",le_linha());
	return 0;
}
