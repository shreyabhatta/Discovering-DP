string print_lcs(string x, string y, int n, int m)
{
    int t[n+1][m+1];
    memset(t, 0, sizeof(t));
    
    for(int i =1; i<n+1; i++)
    {
        for(int j=1; j<m+1; j++)
        {                
            if(x[i-1]==y[j-1]) t[i][j] = 1 + t[i-1][j-1];
            
            else t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    
    int i=n, j=m;
    string s ="";
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1]) i--;
            else j--;
        }
    }
  reverse(s.begin(), s.end());
  return s;
}
