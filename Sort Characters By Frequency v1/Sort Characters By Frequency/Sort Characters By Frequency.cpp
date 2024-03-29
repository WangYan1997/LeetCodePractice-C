#include "pch.h"
#include <iostream>

int CompareTo(int * ch, char a, char b) {
	int f_a = ch[a];
	int f_b = ch[b];

	if (f_a < f_b) {
		return 1;
	}
	else if (f_a == f_b) {
		if (a < b) {
			return 1;
		}
		else if (a == b) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

int Partition(char * str, int * ch, int left, int right) {
	int l = left;
	int r = right;
	//判断大小时要注意，按照ch中的值去判断
	char temp = str[r];

	while (l != r) {
		while (CompareTo(ch, str[l], temp) <= 0 && r > l) {
			l++;
		}
		if (l < r) {
			str[r] = str[l];
			r--;
		}

		while (CompareTo(ch, str[r], temp) >= 0 && r > l) {
			r--;
		}

		if (l < r) {
			str[l] = str[r];
			l++;
		}

	}
	str[l] = temp;
	return l;
}

char * swap(char * str, int i, int j) {
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	return str;
}

char * sort(char * str, int * ch, int left, int right) {
	if (right <= left) {
		return str;
	}

	int pivot = (left + right) / 2;
	swap(str, pivot, right);
	pivot = Partition(str, ch, left, right);
	sort(str, ch, left, pivot - 1);
	sort(str, ch, pivot + 1, right);

	return str;
}

char * frequencySort(char * s) {
	int ch[128] = { 0 };
	int left = 0;
	int length = 0;

	char *q;
	for (q = s; *q != '\0'; q++) {
		ch[*q]++;
		length++;
	}

	//sort it in decreasing order based on the frequency of characters
	sort(s, ch, left, length - 1);
	return s;
}

int main()
{
	//char input[] = "tree";
	//char input[] = "Aabb";
	char input[] = "cccaaa";
	
	char * s = input;

	char * output = frequencySort(s);

	printf("%s", output);
}


