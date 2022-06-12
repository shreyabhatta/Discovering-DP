#include <bits/stdc++.h>

using namespace std;

int MinSubsetdiff(int arr[], int n)
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
	
	int l=sum/2;	
	while(!t[n][l])
	{
		l--;
	}
	
	return sum-2*l;
	
}

int main()
{
	int arr[] = {1,2,7};
	int n = sizeof(arr)/ sizeof(arr[0]);
	cout << MinSubsetdiff(arr, n);
}
