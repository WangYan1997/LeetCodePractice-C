#include "pch.h"
#include <iostream>

bool backspaceCompare(char * S, char * T) {
	int lengthS = 0;
	int lengthT = 0;
	int indexS, indexT;

	for (int i = 0; S[i] != '\0'; i++) {
		lengthS++;
	}

	for (int j = 0; T[j] != '\0'; j++) {
		lengthT = 0;
	}

	//indexS和indexT为字符串S和T的索引
	//初始值是S和T最后一个元素的索引值
	//从后往前，对S和T进行比较
	indexS = lengthS - 1;
	indexT = lengthT - 1;

	//skipS和skipT是对已扫描过的字符中是否包含‘#’
	//‘#’所代表的backspace功能是否被执行情况的记录
	int skipS = 0;
	int skipT = 0;

	for (indexS = ) {

	}

}

int main()
{
	//char inputS[] = "ab#c";
	//char inputT[] = "ad#c";

	//char inputS[] = "ab##";
	//char inputT[] = "c#d#";

	//char inputS[] = "a##c";
	//char inputT[] = "#a#c";

	char inputS[] = "a#c";
	char inputT[] = "b";

	char * S = inputS;
	char * T = inputT;

	bool equal = backspaceCompare(S, T);

	printf("%d", equal);
}
