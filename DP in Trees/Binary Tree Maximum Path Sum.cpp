int solve(TreeNode* root,int& ans)
{
    if(root==nullptr)
    {
        return 0;
    }
    
    int l=max(0,solve(root->left,ans));
    int r=max(0,solve(root->right,ans));
    
    ans=max(ans,l+r+root->val);
    
    return root->val+max(l,r);
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
    int res=INT_MIN;
    solve(root,res);
    return res;
        
    }
};
