long long int count(int S[], int n, int sum) {
        long long int t[n+1][sum+1];
        memset(t, 0, sizeof(t));
        
        for(int i =0; i<n+1; i++)
        {
            t[i][0] = 1;
        }
        
        for(int i =1; i<sum+1; i++)
        {
            t[0][i] = 0;
        }

        for(int i=1; i<n+1; i++)
        {
            for(int j =1; j<sum+1; j++)
            {
                if(j<S[i-1]) t[i][j] = t[i-1][j];
                
                else t[i][j] = t[i][j-S[i-1]] + t[i-1][j];
            }
        }
        return t[n][sum];
    }
