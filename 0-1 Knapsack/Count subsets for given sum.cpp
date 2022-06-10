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
			if (j==0) t[i][j] = 1;
			
			else if (i==0 ) t[i][j] = 0;
				
			else if (arr[i-1]> j) t[i][j] = t[i-1][j];
			
			else t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j] ;
		}
		
	}
	return t[n][sum];
}

int main() {
	int set[] = {2,3,5,6,8,10};
    int sum = 10;
    int n = sizeof(set) / sizeof(set[0]);
    cout << CountSubsetSum(set, n, sum);
    return 0;
}
