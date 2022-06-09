#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int n, int W)
{
	vector <vector <int> > t (n+1, vector <int> (W+1, 0));
	
	for(int i =1; i< n+1; i++)
	{
		for(int j=1; j<W+1; j++)
		{
			if (wt[i-1]> j) t[i][j] = t[i-1][j];
			
			else t[i][j] = max((val[i-1]+ t[i-1][j-wt[i-1]]), t[i-1][j]);
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
