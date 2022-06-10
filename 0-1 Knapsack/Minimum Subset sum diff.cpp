#include <bits/stdc++.h>

using namespace std;

int MinSubsetDiff(int arr[], int n)
{
	int sum1=0;
	for(int k = 0; k<n; k++)
	{
		sum1+=arr[k];
	}
	int sum= sum1/2;
	
	int t[n+1][sum+1];
	memset(t, 0 , sizeof(t));

	while(sum)
	{
		for(int i =0; i<n+1; i++)
		{
			for(int j=0; j<sum+1; j++)
			{
                if (j==0) t[i][j] = 1;
			
                if(i==0) continue;
                
                if(arr[i-1]> j) t[i][j] = t[i-1][j];
                
                else t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j] ;
			}
		}
		if(t[n][sum] == true) return sum1 -2*sum;
		sum--;			
	}

}

int main()
{
	int arr[] = {1,2,7};
	int n = sizeof(arr)/ sizeof(arr[0]);
	cout << MinSubsetDiff(arr, n);
}
