#include "pch.h"
#include <iostream>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;

	for (i = 0; i < numsSize; i++) {
		for (j = i+1; j < numsSize; j++) {
			if ((nums[i] + nums[j]) == target) {
				returnSize[0] = i;
				returnSize[1] = j;
				return returnSize;
			}
		}
	}
	return returnSize;
}

int main()
{
	int input[] = { 2, 7, 11, 15 };
	int* nums = input;

	int numsSize = sizeof(nums);

	int target = 9;

	int* returnSize = (int *)malloc(2 * sizeof(int));

	int* output = twoSum(nums, numsSize, target, returnSize);

	int i;
	for (i = 0; i < 2; i++) {
		printf("%d", output[i]);
	}
	
	free(returnSize);
    
	return 0;
}
