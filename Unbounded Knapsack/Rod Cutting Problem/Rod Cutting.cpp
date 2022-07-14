class Solution{
  public:
    int cutRod(int price[], int n) {
        int t[n+1][n+1];
    	memset(t, 0, sizeof(t));
    	
    	for(int i =0; i<n+1; i++)
    	{
    		for(int j=0; j<n+1; j++)
    		{
    			if(i==0 || j==0) 
    			{
    				t[i][j]=0;
    				continue;
    			}
    			
    			if(i>j) t[i][j] = t[i-1][j];
    			
    			else t[i][j] = max((price[i-1] + t[i][j-i]), t[i-1][j]);
    		}
    	}
    	return t[n][n];
    }
};
