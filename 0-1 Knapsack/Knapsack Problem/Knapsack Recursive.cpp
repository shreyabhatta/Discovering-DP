#include<bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int n, int W)
{
    if(n==0 || W ==0)
    {
        return 0;
    }
    
    else
    {
        if(W<wt[n-1]) 
            return knapsack(wt, val, n-1, W);
        
        else 
            return max((val[n-1] + knapsack(wt, val, n-1, W-wt[n-1])), knapsack(wt, val, n-1, W));
    }
}
    
int main() {
	int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
	cout << knapsack(wt, val, n, W);
	return 0;
}
