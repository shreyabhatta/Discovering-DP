// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int inf = INT_MAX - 1;
	public:
	int minCoins(int coins[], int n, int V) 
	{ 
	    int t[n+1][V+1];
	    memset(t, 0, sizeof(t));
	    
	    for(int i=0; i<n+1; i++)
	    {
	        t[i][0] = 0;
	    }
	    
	    for(int i=1; i<V+1; i++)
	    {
	        t[0][i] = inf;
	    }
	    
	    for(int i=1; i<n+1; i++)
	    {
	        for(int j=1; j<V+1; j++)
	        {
	            if(coins[i-1]>j) t[i][j] = t[i-1][j];
	            
	            else t[i][j] = min((1 + t[i][j-coins[i-1]]), t[i-1][j]);
	        }
	    }
	    if(t[n][V]==inf) return -1;
	    else return t[n][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
