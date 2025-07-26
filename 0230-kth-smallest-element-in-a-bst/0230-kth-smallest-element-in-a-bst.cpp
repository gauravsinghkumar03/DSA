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
    // void Inorder(TreeNode* root,vector<int>&v){
    //     if(root==NULL) return;
    //     Inorder(root->left,v);
    //     v.push_back(root->val);
    //     Inorder(root->right,v);
    // }
    int Inorder(TreeNode* root,int &i,int k){
        if(root==NULL) return -1;
        int left= Inorder(root->left,i,k);
        if(left!=-1){
            return left;
        }
        i++;
        if(i==k){
            return root->val;
        }
        return Inorder(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return Inorder(root,i,k);
    }
};