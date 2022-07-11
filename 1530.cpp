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
    unordered_map<TreeNode *, TreeNode *> parentNodes;
    vector<TreeNode *> leafNodes;
    
    void populateParent(TreeNode *root, TreeNode *parent) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            leafNodes.push_back(root);                 
        }
        parentNodes[root] = parent;
        
        populateParent(root->left, root);
        populateParent(root->right, root);
    }
    
    int dfs(TreeNode* root, TreeNode *last, int distance) {          
        if (distance < 0 || root == NULL) {
            return 0;
        }
        if (root != NULL && last != NULL && root == last) {
            return 0;
        }        
        if (root != NULL && root->left == NULL && root->right == NULL) {            
            if (distance >= 0) {
                return 1;
            } else {
                return 0;
            }
        }
        // cout << root->val << " " << last->val << " " << distance << endl;
        int leftNumberOfNodes = 0;
        if (root->left != NULL && last != root->left) {
            leftNumberOfNodes = dfs(root->left, root, distance - 1);
        }            
        int rightNumberOfNodes = 0;
        if (root->right != NULL && last != root->right) {
            rightNumberOfNodes = dfs(root->right, root, distance - 1);   
        }        
        int parentNumberOfNodes = 0;
        if (parentNodes[root] != NULL && last != parentNodes[root]) {
            parentNumberOfNodes = dfs(parentNodes[root], root, distance - 1);   
        }        
        
        return leftNumberOfNodes + rightNumberOfNodes + parentNumberOfNodes;
    }
    
    int countPairs(TreeNode* root, int distance) {        
        populateParent(root, NULL);
        int finalAnswer = 0;
        for (TreeNode *node : leafNodes) {            
            int answer = dfs(parentNodes[node], node, distance-1);
            // cout << node->val << " " << answer << endl;
            finalAnswer += answer;            
        }
        
        return finalAnswer / 2;
    }
};