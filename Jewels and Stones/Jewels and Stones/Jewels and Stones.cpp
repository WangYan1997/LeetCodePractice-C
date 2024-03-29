#include <stdio.h>

int numJewelsInStones(char* J, char* S) {
	int count = 0;
	char* tempj = J;

	while (*S != '\0')
	{
		while (*J != '\0')
		{
			if (*S == *J) {
				count++;
			}
			J++;
		}
		J = tempj;
		S++;
	}

	return count;
}

int main() {
	char j[] = "aA";
	char * J = j;

	char s[] = "aAAbbbb";
	char * S = s;

	int ans = numJewelsInStones(J, S);

	printf("%d", ans);
}