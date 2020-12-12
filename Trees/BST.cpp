/* Chris Cheng
 * 12/11/2020
 * BST.cpp
 */

/* This is an implementation of a BinarySearchTree class with the 
 * common operations (Node insertion, removal, and search) with some other
 * functions (preorder/inorder/postorder traversal applications)
 */

/* A BST's traversal operations always run in O(N) runtime b/c by definition, the 
 * traversal operations visit every node in the tree. This is regardless of whether 
 * the tree is balanced or not. 
 * 
 * The BST's Node insertion, removal and search operations have runtime efficiency 
 * that depends on whether the BST is balanced or not. If BST is balanced, then the 
 * operations have O(logN) runtime. If the BST is unbalanced and in the worst case, 
 * then said BST is no better than a linked list and so the operations have O(N)
 * runtime. 
 * 
 * This variance is explained really well in Carrano; the worst case is that
 * any of these 3 operations need to traverse through the longest path down the BST, 
 * which is also the height of the tree. And as such, the tree's height at minimum
 * is log_2(N+1) and at maximum is N, where N is the number of nodes in the tree.
 */

#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* leftChild;
    BSTNode* rightChild;
    BSTNode(int dataVal) : data(dataVal), leftChild(nullptr), rightChild(nullptr) {} 
};

class BinarySearchTree {
private:
    BSTNode* root;
public:
    void Set_Root(BSTNode* node) {
        root = node;
    }
    BSTNode* Get_Root() {
        return root;
    }
    BSTNode* Insert(BSTNode* root, int data_val) {
        if (root == nullptr) {
            BSTNode* newNode = new BSTNode(data_val);
            newNode->leftChild = newNode->rightChild = nullptr;
            return newNode;
        }
        else if (data_val < root->data) {
            Insert(root->leftChild, data_val);
        }
        else if (data_val > root->data) {
            Insert(root->rightChild, data_val);
        }
        return root;
    }

    void Print_Inorder(BSTNode*root) {
        if (root->leftChild != nullptr) Print_Inorder(root->leftChild);
        cout << "Node value: " << root->data << endl;
        if (root->rightChild != nullptr) Print_Inorder(root->rightChild);
    }

    void Print_Preorder(BSTNode*root) {
        cout << "Node value: " << root->data << endl;
        if (root->leftChild != nullptr) Print_Inorder(root->leftChild);
        if (root->rightChild != nullptr) Print_Inorder(root->rightChild);
    }

    void Print_Postorder(BSTNode*root) {
        if (root->leftChild != nullptr) Print_Inorder(root->leftChild);
        if (root->rightChild != nullptr) Print_Inorder(root->rightChild);
        cout << "Node value: " << root->data << endl;
    }
};