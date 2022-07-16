static int dp[1001][1001];

class Solution {
public:    
    
   int test(int x, int y, string &s1, string &s2)
    {
        if(x == 0 || y == 0)
        {
            return 0;
        }
        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        if(s1[x-1] == s2[y-1])
        {
            return dp[x][y] = 1+test(x-1,y-1,s1,s2);
        }
        else
        {
            return dp[x][y] = max(test(x-1,y,s1,s2),test(x,y-1,s1,s2));
        }
    }
    

    int longestCommonSubsequence(string text1, string text2) {
        int  n = text1.length(), m = text2.length();
        memset(dp,-1,sizeof(dp));
        int p = test(n, m, text1, text2);
        return p;
 
    }
};
