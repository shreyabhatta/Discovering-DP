//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
            int n = str.length();
            int t[n+1][n+1];
            memset(t, 0, sizeof(t));
    
            for(int i =1; i<n+1; i++)
            {
                for(int j=1; j<n+1; j++)
                {                
                    if(str[i-1]==str[j-1] && i!=j) t[i][j] = 1 + t[i-1][j-1];
    
                    else t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
            return t[n][n-1];

		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
