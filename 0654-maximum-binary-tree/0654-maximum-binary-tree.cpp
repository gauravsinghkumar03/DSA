/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& nums,int st,int end){
        if(st>end) return NULL;

        int idx=st;
        for(int i=st+1; i<=end;i++){
            if(nums[i]>nums[idx]){
                idx=i;
            }
        }
        TreeNode* root=new TreeNode(nums[idx]);

        root->left=build(nums,st,idx-1);
        root->right=build(nums,idx+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()){
            return NULL;
        }
        return build(nums,0,nums.size()-1);
    }

};