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
    TreeNode* minVal(TreeNode* root) {
        if (root == NULL) return NULL;
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == NULL) return NULL;

        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->val) {
            root->right = deleteNode(root->right, val);
        }
        else {

            if (root->left ==NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode* succ = minVal(root->right);
                if (succ) {
                    root->val = succ->val;
                    root->right = deleteNode(root->right, succ->val);
                }
            }
        }
        return root;
    }
};
