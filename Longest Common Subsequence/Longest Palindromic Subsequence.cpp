class Solution {
public:
    
    int LPS(string x, string y, int n)
    {
        int t[n+1][n+1];
        memset(t, 0, sizeof(t));
        
        for(int i =1; i<n+1; i++)
        {
            for(int j =1; j<n+1; j++)
            {
                if(x[i-1]==y[j-1]) t[i][j] = 1 + t[i-1][j-1];
                
                else t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        return t[n][n];
    }
    
    int longestPalindromeSubseq(string s) {
        string s_rev = s;
        reverse(s.begin(), s.end());
        return LPS(s, s_rev, s.length());
    }
};
