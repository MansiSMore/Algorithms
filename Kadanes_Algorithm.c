/*
Kadane’s Algorithm:

Initialize:
    max_sum = 0
    curr_sum = 0

Loop for each element of the array
  (a) curr_sum = curr_sum + a[i]
  (b) if(max_sum < curr_sum)
            max_sum = curr_sum
  (c) if(curr_sum < 0)
            curr_sum = 0
return max_sum
*/ 

//Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

#include <stdio.h>
#include <stdlib.h>

//Display Array elements.
void printArray(int *arr, int len)
{
	int i = 0;
	for(i = 0; i < len ; i++)
	{
		printf("Element : %d\n", arr[i]);
	}
}

int Kadanes_algorithm(int *arr, int len)
{
	int max_sum = 0, curr_sum = 0;
	
	for(int i = 0; i < len; i++)
	{
		curr_sum += arr[i];
		if(curr_sum < 0)
			curr_sum = 0;
		if(max_sum < curr_sum)
			max_sum = curr_sum;
	}
	
	return max_sum;
}
int main()
{
	int *arr = NULL, num = 0, i = 0;
	printf("Enter number of elements : ");
	scanf("%d", &num);
	
	arr = (int*)malloc(sizeof(int) * num);
	for(i = 0; i < num ; i++)
	{
		printf("Enter %d element : ", i+1);
		scanf("%d", &arr[i]);
	}
	//printf("Elements from array are : \n");
	//printArray(arr, num);
	
	printf("Maximum Subarray Sum : %d\n", Kadanes_algorithm(arr, num));
	return 0;
}
