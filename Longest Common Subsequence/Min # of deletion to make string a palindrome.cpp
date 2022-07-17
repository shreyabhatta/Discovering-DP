//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
        string x = str;
        reverse(str.begin(), str.end());
        string y = str;
        
        int n = str.length();
        
        int t[n+1][n+1];
        memset(t, 0, sizeof(t));
        
        for(int i =1; i<n+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(x[i-1]==y[j-1]) t[i][j] = 1 + t[i-1][j-1];
                
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return n - t[n][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
