#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree 
{
    Node* root;
public:
    BinaryTree();
    Node* createNode(int value);
    void buildTree();
    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    int countNodes(Node* root);
    int height(Node* root);
    int leafNodes(Node* root);
    Node* getRoot();
};

BinaryTree::BinaryTree() 
{
    root = NULL;
}

Node* BinaryTree::createNode(int value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void BinaryTree::buildTree() 
{
    root = createNode(1);
    root->left = createNode(12);
    root->right = createNode(9);
    root->left->left = createNode(2);
    root->left->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(10);
}

void BinaryTree::preorder(Node* root) 
{
    if (root != NULL) 
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BinaryTree::inorder(Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void BinaryTree::postorder(Node* root) 
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int BinaryTree::countNodes(Node* root) //function to count the total number of nodes
{
    if (root == NULL)
    return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int BinaryTree::height(Node* root) //function to calculate the height of the tree
{
    if (root == NULL)
    return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

int BinaryTree::leafNodes(Node* root) //This function will tell us about the leafnodes in the tree
{
    if (root == NULL)
    return 0;
    if (root->left == NULL && root->right == NULL) 
    {
        cout << root->data << " ";
        return 1;
    }
    return leafNodes(root->left) + leafNodes(root->right);
}

Node* BinaryTree::getRoot() 
{
    return root;
}

int main() 
{
    BinaryTree tree;
    tree.buildTree();

    cout << "Preorder: ";
    tree.preorder(tree.getRoot());

    cout << "\nInorder: ";
    tree.inorder(tree.getRoot());

    cout << "\nPostorder: ";
    tree.postorder(tree.getRoot());

    cout << "\n\nTotal Nodes: " << tree.countNodes(tree.getRoot());
    cout << "\nHeight of Tree: " << tree.height(tree.getRoot());
    cout << "\nLeaf Nodes: " << tree.leafNodes(tree.getRoot());

    return 0;
}