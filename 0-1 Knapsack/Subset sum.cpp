#include <bits/stdc++.h>

using namespace std;

bool SubsetSum(int arr[], int n, int sum)
{
    int t[n+1][sum+1];
    
    for(int i =0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(j==0) t[i][j] = false;
            else if(i==0) t[i][j] = true;
            else if(arr[i-1]> j) t[i][j] = t[i-1][j];
            else t[i][j] =t[i-1][j-arr[i-1]] || t[i-1][j];
        }
    }
    return t[n][sum];	
}

int main()
{
	int arr[] = {1,6,11,5};
    int sum= 6;
	int n = sizeof(arr)/ sizeof(arr[0]);
    if(SubsetSum(arr,n,sum)) cout << "TRUE";
    else cout<<"FALSE";
}
