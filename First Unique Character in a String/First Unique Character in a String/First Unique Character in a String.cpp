
#include "pch.h"
#include <iostream>

int firstUniqChar(char * s) {
	if (*s == '\0'){
		return -1;
	}

	int ch[26] = { 0 };
	int index = -1;
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		ch[s[i] - 'a']++;
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (ch[s[i] - 'a'] == 1) {
			index = i;
			return index;
		}
	}

	return index;
}


int main()
{
	char input[] = "leetcode";
//	char input[] = "loveleetcode";
//	char input[] = "cc";
	
	char * s = input;

	int index = firstUniqChar(s);
	printf("%d", index);
    
	return 0;
}

