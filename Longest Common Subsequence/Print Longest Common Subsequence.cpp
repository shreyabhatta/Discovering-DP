vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int t[n+1][m+1];
    memset(t, 0, sizeof(t));
    
    for(int i =1; i<n+1; i++)
    {
        for(int j = 1; j<m+1; j++)
        {
            if(a[i-1]==b[j-1]) t[i][j] = 1 + t[i-1][j-1];
            
            else t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    
    int i = n, j = m;
    vector<int> v;
    
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            v.push_back(a[i-1]);
            i--;
            j--;
        } 
        else
        {
            if(t[i-1][j]>t[i][j-1]) i--;
            else j--;
        }
    }
    
    reverse(v.begin(), v.end());
    return v;
}
