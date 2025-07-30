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
    void Inorder(TreeNode* root,vector<int>&arr){
        if(root==NULL) return;
        Inorder(root->left,arr);
        arr.push_back(root->val);
        Inorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        Inorder(root,arr);

        int i=0,j=arr.size()-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==k){
                return true;
            }else if(sum>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};