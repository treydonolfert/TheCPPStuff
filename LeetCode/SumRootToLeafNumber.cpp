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
    vector<int> rootToLeaf;
    string tempRoot = "";
    int loopNumber = 0;
    int sumNumbers(TreeNode* root) {
        // return stoi(to_string(root -> val) + to_string(root -> left -> val))
        // + stoi(to_string(root -> val) + to_string(root -> right -> val));
        search(root);
        int sum = 0;
        for (int i = 0; i < rootToLeaf.size(); i++) {
            sum += rootToLeaf[i];
        }
        return sum;
    }

    void search(TreeNode* root) {
        loopNumber++;
        tempRoot += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            rootToLeaf.push_back(stoi(tempRoot));
        }
        else {
            if (root->left != nullptr) {
                search(root->left);
            }
            if (root->right != nullptr) {
                search(root->right);
            }
        }
        tempRoot = tempRoot.substr(0, loopNumber - 1);
        loopNumber--;
    }
};