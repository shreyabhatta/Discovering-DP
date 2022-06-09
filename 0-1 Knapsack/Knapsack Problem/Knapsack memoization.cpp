#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > t (102, vector <int> (1002, -1) );

int knapsack(int wt[], int val[], int n, int W)
{
	if(n==0 || W==0) return 0;

	if (t[n][W]!=-1)
	{
		return t[n][W];
	}

	else
	{
		if(wt[n-1]<=W)
		{
			return t[n][W] = max((val[n-1] + knapsack(wt, val, n-1, W - wt[n-1])),knapsack(wt, val, n-1, W));
		}

		else
		{
			return t[n][W] = knapsack(wt, val, n-1, W);
		}
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
