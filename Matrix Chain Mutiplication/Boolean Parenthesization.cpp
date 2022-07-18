//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
unordered_map<string,int> mp;

class Solution{
public: 
    int noOfWays(string S,int i,int j , bool isTrue)
    {
        if(i>j)
        return 0;
        if(i==j)
        {
            if(isTrue)
            return S[i]=='T'?1:0;
            else return S[i]=='F'?1:0;
        }
         string temp=to_string(i)+' '+to_string(j)+' '+to_string(isTrue);
        if(mp.find(temp)!=mp.end())
        return mp[temp];
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int LT=noOfWays(S,i,k-1,true);
            int RT=noOfWays(S,k+1,j,true);
            int LF=noOfWays(S,i,k-1,false);
            int RF=noOfWays(S,k+1,j,false);
            
            if(S[k]=='&')
            {
                if(isTrue)
                ans+=(LT*RT)%1003;
                else ans+=(LT*RF+LF*RT+LF*RF)%1003;
            }
            else  if(S[k]=='|')
            {
                if(isTrue)
                ans+=(LT*RT+LT*RF+LF*RT)%1003;
                else ans+=(LF*RF)%1003;
            }
            else
            {
                 if(isTrue)
                ans+=(LT*RF+LF*RT)%1003;
                else ans+=(LF*RF+LT*RT)%1003;
            }
        }
        
        return mp[temp]=ans%1003;
    }
    
    int countWays(int N, string S){
        mp.clear();
       return noOfWays(S,0,S.size()-1,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
