//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int t[n+1][m+1];
        memset(t, 0, sizeof(t));
        
        int count = 0;
        
        for(int i =0; i<n+1; i++)
        {
            for(int j =0; j<m+1; j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j] = 0;
                    continue;
                }
                if(S1[i-1]==S2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                    count = max(count, t[i][j]);
                }
                
                else t[i][j]=0;
            }
        }
        return count;
    }
    
    
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
