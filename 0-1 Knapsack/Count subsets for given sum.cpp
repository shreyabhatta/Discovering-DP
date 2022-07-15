int perfectSum(int nums[], int size, int target)
	{   
	    int n = size+1;
        int m = target+1;
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<m;i++)
            dp[0][i] = 0;
        
        for(int idx = 1;idx<n;idx++){
            for(int sum = 0;sum<m;sum++){
                
                if(sum>=nums[idx-1])
                    dp[idx][sum] = (dp[idx-1][sum - nums[idx-1]]% mod + dp[idx-1][sum]% mod) % mod;
                else
                    dp[idx][sum] = dp[idx-1][sum] % mod;
            }
        }
        
        return dp[n-1][m-1];
	}
