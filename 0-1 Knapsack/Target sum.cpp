#include <bits/stdc++.h>

using namespace std;

int CountSubsetSum(int arr[], int n, int sum)
{
	int t[n+1][sum+1];
	memset(t, 0, sizeof(t));
	
	for(int i =0; i<n+1;i++)
	{
		for(int j=0; j<sum+1; j++)
		{			
			if(j==0) t[i][j] = 1;
			
			if(i==0 ) continue;
				
			if(arr[i-1]> j) t[i][j] = t[i-1][j];
			
			else t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j] ;
		}
		
	}
	return t[n][sum];
}

int TargetSum(int arr[], int n, int diff)
{
	int sum = 0;
	for(int i =0; i<n; i++)
	{
		sum+=arr[i];
	}
	
	sum = (sum+diff)/2;
	
	return CountSubsetSum(arr, n, sum);
}

int main()
{
	int arr[] = {1,1,2,3};
	int diff = 1;
	int n = sizeof(arr)/ sizeof(arr[0]);
	cout << Targetsum(arr, n, diff);
}
