#include<bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int n, int W)
{
    int t[n+1][W+1];
    memset(t, 0, sizeof(t));
    
    for(int i =0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
                continue;
            }
            
            if(j < wt[i-1]) t[i][j] = t[i-1][j];
            else t[i][j] =  max((val[i-1] + t[i-1][j-wt[i-1]]), t[i-1][j]);
        }
    }
    return t[n][W];
}

int main() {
	int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
	cout << knapsack(wt, val, n, W);
	return 0;
}
