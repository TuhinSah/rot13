#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * find_rot13(char * original) {
	int i, current_char, len = strlen(original);

	for(i = 0; i < len; i++) {
		current_char = (int) original[i];

		if(current_char >= 'A' && current_char <= 'z') {
			if((current_char > 'm') || (current_char > 'M' && current_char < 'a'))
				current_char-=13;
			else
				current_char+=13;
		}
		original[i] = (char) current_char;
	}

	return original;
}

int main(int argc, char ** argv)
{
	char * rot13;
	int i;

	for(i = 1; i < argc; i++) {
		rot13 = find_rot13 (argv [i]);
		printf("%s ", rot13);
	}

	printf("\n");

	return 0;
}
