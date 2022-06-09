#include <bits/stdc++.h>

using namespace std;

bool EqualPartition(int arr[], int n)
{
	int sum =0;
	for(int i =0; i<n; i++)
	{
		sum+= arr[i];
	}
	
	if (sum%2!=0) return false;
	
	else
	{
		sum/=2;
		int t[n+1][ sum+1];
		
		for(int i =0; i< n+1;i++)
		{
			for(int j=0; j<sum+1; j++)
			{
				if (i==0) t[i][j] = false;
				
				if (j==0) t[i][j] = true;
				
				if(arr[i-1]> j) t[i][j]=t[i-1][j];
				
				else t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j] ;
			}
		}
		return t[n][sum];
	}
}

int main() {
	int set[] = { 1,5,11,5 };
    int n = sizeof(set) / sizeof(set[0]);
    if (EqualPartition(set, n) == true)
         cout <<"possible";
    else
        cout <<"not possible";
    return 0;
}
