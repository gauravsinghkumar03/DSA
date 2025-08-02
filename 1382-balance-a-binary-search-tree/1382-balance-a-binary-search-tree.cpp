/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void Inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return;
        }
        Inorder(root->left, arr);
        arr.push_back(root->val);
        Inorder(root->right, arr);
    }
    TreeNode* buildBSTFromInorder(const vector<int>& inorder, int start,
                                  int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBSTFromInorder(inorder, start, mid - 1);
        root->right = buildBSTFromInorder(inorder, mid + 1, end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        Inorder(root, arr);
        return buildBSTFromInorder(arr, 0, arr.size() - 1);
    }
};