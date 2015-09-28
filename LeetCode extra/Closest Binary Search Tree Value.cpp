/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        auto kid = root->val >= target ? root->left : root->right;
        if (kid == nullptr) {
            return root->val;
        } else {
            int kidClosestValue = closestValue(kid, target);
            return abs(kidClosestValue - target) < abs(root->val - target) ? kidClosestValue : root->val;
        }
    }
};
