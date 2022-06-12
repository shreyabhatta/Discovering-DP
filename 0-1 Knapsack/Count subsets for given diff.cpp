#include <bits/stdc++.h>

using namespace std;

int CountSubsetdiff(int arr[], int n, int diff)
{
	int sum = 0;
	
	for(int k=0; k<n; k++)
	{
		sum+=arr[k];
	}
	
	int t[n+1][sum+1];
	memset(t, 0, sizeof(t));
	
	for(int i =0; i<n+1; i++)
	{
		for(int j=0; j<sum+1; j++)
		{			
			if (j==0) t[i][j] = 1;
			if (i==0) continue;
			
			if (t[i-1][j]>sum) t[i][j] = t[i-1][j];
			
			else t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
		}
	}
	int count =0;
	for(int l=0; l<n+1; l++)
	{
		if(t[l][(sum - diff)/2]) count ++;
	}
	return count;
	
}

int main()
{
	int arr[] = {1,1,2,3};
	int diff = 1;
	int n = sizeof(arr)/ sizeof(arr[0]);
	cout << CountSubsetdiff(arr, n, diff);
}
