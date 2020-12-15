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
    BSTNode* root = nullptr;
public:
    BinarySearchTree() { root = nullptr; }
    ~BinarySearchTree() {
        // call the recursive clear() method to delete all the nodes
    }
    void Set_Root(BSTNode* node) {
        root = node;
    }
    BSTNode* Get_Root() {
        return root;
    }

    // recursive Node insertion function
    BSTNode* Insert(BSTNode* root, int data_val) {
        if (root == nullptr) {
            BSTNode* newNode = new BSTNode(data_val);
            newNode->leftChild = newNode->rightChild = nullptr;
            return newNode;
        }
        else if (data_val < root->data) {
            root->leftChild = Insert(root->leftChild, data_val);
        }
        else if (data_val > root->data) {
            root->rightChild = Insert(root->rightChild, data_val);
        }
        return root;
    }

    // recursive Node search function 
    BSTNode* Contains(BSTNode* root, int search_val) {
        // tree is empty or search_val DNE in the BST
        if (root == nullptr) {
            return nullptr;
        }
        // you found the search_val 
        else if (search_val == root->data) {
            return root;
        }
        // search_val is less than current node's val
        else if (search_val < root->data) {
           return Contains(root->leftChild, search_val);
        }
        // search_val is greater than current node's val
        else {
            return Contains(root->rightChild, search_val);
        }
    }
    
    // recursive Node deletion function
    BSTNode* Remove(BSTNode* root, int data) {
        if (root == nullptr) {
            return root;
        }
        else if (data < root->data) {
            // recursively point the current node's left to the return of the call
            // the return may or may not be the same node from pre-deletion
            // same logic as with insertion function; (connect the call's return with
            // the pertinent child pointer)
            root->leftChild = Remove(root->leftChild, data);
        }
        else if (data > root->data) {
            // the return may or may not be the same node from pre-deletion
            root->rightChild = Remove(root->rightChild, data);
        }
        // the value has been found and one of the three deletion steps occurs
        else {
            // 0 child node deletion
            if ((root->leftChild == nullptr) && (root->rightChild == nullptr)) {
                delete root;
                root = nullptr;
            }
            // 1 child node deletion
            else if (root->leftChild == nullptr) {
                BSTNode* temp = root;
                root = root->rightChild;
                delete temp;
            }
            else if (root->rightChild == nullptr) {
                BSTNode* temp = root;
                root = root->leftChild;
                delete temp;
            }
            // 2 child node deletion    
            else {
                // find N's IOP (max val of N's left subtree)
                int IOP = Find_Maximum_Val(root->leftChild)->data;
                // copy IOP to N
                root->data = IOP;
                // delete the IOP val (feeing in N's left child as root)
                root->leftChild = Remove(root->leftChild, IOP);
            }
        }
        return root;
    }

    // return a pointer to min int value in BST or a nullptr if empty tree
    BSTNode* Find_Minimum_Val(BSTNode* root) {
        // empty tree case
        if (root == nullptr) {
            return nullptr;
        }
        // you got to min val in the BST case
        else if (root->leftChild == nullptr) {
            return root;
        }
        // otherwise recurse again with node's left child 
        else {
            return Find_Minimum_Val(root->leftChild);
        }
    }

    // return a pointer to max int value in BST or a nullptr if empty tree
    BSTNode* Find_Maximum_Val(BSTNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        else if (root->rightChild == nullptr) {
            return root;
        }
        else {
            return Find_Maximum_Val(root->rightChild);
        }
    }

    // check if tree is empty 
    bool isEmpty() {
        if (this->Get_Root() != nullptr) {
            return false;
        }
        return true;
    }

    // return the integer sum held in BST
    // takes advantage of inorder traversal logic.
    // 4 different situations possible:
        // current node has both a left and right child, or left and no right,
        // or right and no left, or none 
    int Sum(BSTNode* root) {
        // if you have no child nodes
        if ((root->leftChild == nullptr) && (root->rightChild == nullptr)) {
            return root->data;
        }
        // if you have a left child node and no right child node
        else if ((root->leftChild != nullptr) && (root->rightChild == nullptr)) {
            return Sum(root->leftChild) + root->data;
        }
        // if you have a right child and no left child
        else if ((root->rightChild != nullptr) && (root->leftChild == nullptr)) {
            return root->data + Sum(root->rightChild);
        }
        // if you have both a left and right child 
        else {
            return Sum(root->leftChild) + root->data + Sum(root->rightChild);
        }
    }

    // inorder traversal of the nodes
    void Print_Inorder(BSTNode*root) {
        if (root->leftChild != nullptr) Print_Inorder(root->leftChild);
        cout << "Node value: " << root->data << endl;
        if (root->rightChild != nullptr) Print_Inorder(root->rightChild);
    }

    // opposite of inorder traversal; prints nodes of BST in descending order
    void Print_Descending_Order(BSTNode* root) {
        if (root->rightChild != nullptr) Print_Descending_Order(root->rightChild);
        cout << "Node value: " << root->data << endl;
        if (root->leftChild != nullptr) Print_Descending_Order(root->leftChild);
    }

    // preorder traversal of the nodes
    void Print_Preorder(BSTNode*root) {
        cout << "Node value: " << root->data << endl;
        if (root->leftChild != nullptr) Print_Inorder(root->leftChild);
        if (root->rightChild != nullptr) Print_Inorder(root->rightChild);
    }

    // postorder traversal of the nodes
    void Print_Postorder(BSTNode*root) {
        if (root->leftChild != nullptr) Print_Inorder(root->leftChild);
        if (root->rightChild != nullptr) Print_Inorder(root->rightChild);
        cout << "Node value: " << root->data << endl;
    }
};





void Check_Int_Val_Present_in_BST(BinarySearchTree mytree, int val) {
    if (mytree.Contains(mytree.Get_Root(), val) != nullptr) {
        cout << "The value: " << val << " is present in the BST" << endl;
    }
    else {
        cout << "The value: " << val << " is NOT present in the BST" << endl;
    }
}

void Check_Max_Val(BinarySearchTree mytree) {
    if (mytree.Find_Maximum_Val(mytree.Get_Root()) != nullptr) {
        cout << "Maximum val in the BST is: " 
        << mytree.Find_Maximum_Val(mytree.Get_Root())->data << endl;
    }
    else {
        cout << "Tree is empty." << endl;
    }
}
void Check_Min_Val(BinarySearchTree mytree) {
    if (mytree.Find_Minimum_Val(mytree.Get_Root()) != nullptr) {
        cout << "Minimum val in the BST is: " 
         << mytree.Find_Minimum_Val(mytree.Get_Root())->data << endl;
    }
    else {
        cout << "Tree is empty." << endl;
    }
}

int main() {
    BinarySearchTree mytree;
    int test_array[] = {14, 10, 20, 3, 13, 19};

    // I forgot that you gotta use vector to get the size()/length() methods.
    // For array you gotta use the sizeof() operator trick.
    for (int i = 0; i < sizeof(test_array)/sizeof(test_array[0]); ++i) {
        mytree.Set_Root(mytree.Insert(mytree.Get_Root(),test_array[i]));
    }
    // mytree.Set_Root(mytree.Insert(mytree.Get_Root(),14));
    // mytree.Set_Root(mytree.Insert(mytree.Get_Root(),10));
    // mytree.Set_Root(mytree.Insert(mytree.Get_Root(),20));
    // mytree.Set_Root(mytree.Insert(mytree.Get_Root(),3));
    // mytree.Set_Root(mytree.Insert(mytree.Get_Root(),13));
    // mytree.Set_Root(mytree.Insert(mytree.Get_Root(),19));

    mytree.Print_Inorder(mytree.Get_Root());
    cout << endl << endl;
    // mytree.Print_Descending_Order(mytree.Get_Root());

    int check_array[] = {2, 14, 3, 8, 20, 19};
    for (int i = 0; i < sizeof(check_array)/sizeof(check_array[0]); ++i) {
        Check_Int_Val_Present_in_BST(mytree, check_array[i]);
    }
    cout << endl;

    Check_Max_Val(mytree);
    Check_Min_Val(mytree);

    if (!mytree.isEmpty()) {
        cout << "Total Sum is: " << mytree.Sum(mytree.Get_Root()) << endl;
    }
    else {
        cout << "Empty tree has no elements to sum." << endl;
    }
    
    
    return 0;
} 