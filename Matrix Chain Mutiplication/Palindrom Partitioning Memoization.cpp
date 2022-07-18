//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
static int t[502][502];

class Solution{
public:
    bool isPalindrome(string s, int i, int j)
    {
        if(i==j) return true;
        
        while(j>i)
        {
            if(s[i]!=s[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s, int i, int j)
    {
        if(i>=j) return 0;
        
        if(t[i][j]!=-1) return t[i][j];
        
        if(isPalindrome(s,i,j)==true) return 0;
        
        int mn = INT_MAX, l, r, temp;
        
        for(int k = i; k<j; k++)
        {
            if(t[i][k]!=-1) 
                l = t[i][k];
            else
            {
                l = solve(s, i, k);
                t[i][k] = l;
            }
            
            if(t[k+1][j]!=-1) 
                r = t[k+1][j];
            else
            {
                r = solve(s, k+1, j);
                t[k+1][j] = r;
            }
            
            temp = l+r+1;
            mn = min(temp, mn);
        }
        
        return t[i][j] = mn;
    }
    
    int palindromicPartition(string str)
    {
        memset(t, -1, sizeof(t));
        return solve(str, 0, str.length()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
