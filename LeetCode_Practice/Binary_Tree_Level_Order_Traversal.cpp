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

/* Chris Cheng
 * 12/16/2020
 * cpp implementation of level-order traversal (a BFS) of a binary tree 
 * result is returned as a list of lists of ints
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //initialize the return vector of vector of ints
        vector<vector<int>>return_vector;
        // empty tree just returns empty vector
        if (root == nullptr) { return return_vector; }
        // initialize the queue of Node ptrs
        queue<TreeNode*> my_q;
        // enqueue the root node
        my_q.push(root);
        while (!my_q.empty()) {
            // find num elements in queue
            int q_size = my_q.size();
            // initialize temp vector of ints
            vector<int> temp_vector;
            // do for each Node in this SAME LEVEL
            for (int i = 0; i < q_size; ++i) {
                // append queue front's int val to temp vector
                temp_vector.push_back(my_q.front()->val);
                // enqueue ANY child Nodes if they exist (setting up the NEXT level)
                if (my_q.front()->left != nullptr) {
                    my_q.push(my_q.front()->left);
                }
                if (my_q.front()->right != nullptr) {
                    my_q.push(my_q.front()->right);
                }
                // dequeue the front Node*
                my_q.pop();
            }
            // append temp vector to return vector before moving to next level
            return_vector.push_back(temp_vector);
        }
        return return_vector;
    }
};