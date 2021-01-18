/*
Sliding Window: 

Step 1 : We compute the sum of first k elements out of n terms using a linear loop and store the sum in variable curr_sum.
Step 2 : Then we will graze linearly over the array till it reaches the end and simultaneously keep track of maximum sum.
Step 3: To get the current sum of block of k elements just subtract the first element from the previous block and add the last element of the current block .

/*
Given an array of integers of size ‘n’. Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maximum_sum(vector<int> &vobj, int k)
{
	int max_sum = INT_MIN, curr_max = 0;
	
	for(int i = 0; i < k; i++)
	{
		curr_max += vobj[i];
	}
	
	max_sum = curr_max;
	
	for(int i = k; i < vobj.size(); i++)
	{
		curr_max += vobj[i] - vobj[i - k];
		max_sum = max(curr_max, max_sum);
	}
	
	return max_sum;
}
int main()
{
	vector<int> vobj;
	int num = 0, ele = 0, k = 0;
	
	cout << "Enter the number of elements : " << endl;
	cin >> num;
	
	cout << "Enter the size of subarray : " << endl;
	cin >> k;
	
	if(k > num){
		cout << "Invalid\n";
		return -1;
	}
	for(int i = 0; i < num; i++)
	{
		cout << "Enter "<< i+1 << " Element : \n";
		cin >> ele;
		vobj.push_back(ele);
	}
	
	cout << "Elements from vector : \n";
	for(int i = 0; i < num; i++)
	{
		cout << vobj[i] << " ";
	}
	
	cout << "\nMaximum Sum by Adding subarray of given vector : " << maximum_sum(vobj, k) << endl;
	return 0;
}
