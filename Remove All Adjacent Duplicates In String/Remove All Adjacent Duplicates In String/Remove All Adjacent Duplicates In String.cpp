#include <stdio.h>
#include <stdlib.h>


char * removeDuplicates(char * S) {
	char *stack;
	stack = (char*)malloc(20001 * sizeof(char));
	int top = -1;

	while(*S != '\0') {
		char c = *S;

		if (top != -1) {
			char temp = stack[top];
			if (stack[top] == c) {
				top--;
				S++;
				continue;
			}
		}
		top++;
		stack[top] = c;
		S++;
	}

	stack[top + 1] = '\0';

	return stack;
}

int main()
{
	char * str;
	char s[] = "abbaca";
	str = s;

	int size = sizeof(str);

	char * newstr;
	newstr = removeDuplicates(str);

	while (*newstr != '\0')
	{
		printf("%c", *newstr);
		newstr++;
	} 

	return 0;
}
