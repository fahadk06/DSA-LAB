#include <iostream>
#include <fstream>
using namespace std;

template<class T>
struct treenode
{
    T info;
    treenode<T>* left;
    treenode<T>* right;
};

template <class T>
class treetype
{
public:
    treetype();
    ~treetype();

    bool isempty() const;
    bool isfull() const;

    int noofnodes() const;
    void insertitem(T item);
    void retrieveitem(T& item, bool& found) const;
    void printtree(ofstream& outfile) const;

private:
    treenode<T>* root;

    void insert(treenode<T>*& tree, T item);
    void retrieve(treenode<T>* tree, T& item, bool& found) const;
    void destroy(treenode<T>*& tree);
    void print(treenode<T>* tree, ofstream& outfile) const;
    int countnodes(treenode<T>* tree) const;
};

template<class T>
treetype<T>::treetype()
{
    root = nullptr;
}

template<class T>
treetype<T>::~treetype()
{
    destroy(root);
}

template<class T>
bool treetype<T>::isempty() const
{
    return (root == nullptr);
}

template<class T>
bool treetype<T>::isfull() const
{
    treenode<T>* location;

    try
    {
        location = new treenode<T>;
        delete location;
        return false;
    }
    catch (bad_alloc exceptionobject)
    {
        return true;
    }
}

template<class T>
void treetype<T>::destroy(treenode<T>*& tree)
{
    if (tree != nullptr)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
        tree = nullptr;
    }
}

template<class T>
int treetype<T>::noofnodes() const
{
    return countnodes(root);
}

template<class T>
int treetype<T>::countnodes(treenode<T>* tree) const
{
    if (tree == nullptr)
        return 0;

    return 1 + countnodes(tree->left) + countnodes(tree->right);
}

template<class T>
void treetype<T>::insertitem(T item)
{
    insert(root, item);
}

template<class T>
void treetype<T>::insert(treenode<T>*& tree, T item)
{
    if (tree == nullptr)
    {
        tree = new treenode<T>;
        tree->info = item;
        tree->left = tree->right = nullptr;
    }
    else if (item < tree->info)
    {
        insert(tree->left, item);
    }
    else
    {
        insert(tree->right, item);
    }
}

template <class T>
void treetype<T>::retrieveitem(T& item, bool& found) const
{
    retrieve(root, item, found);
}

template <class T>
void treetype<T>::retrieve(treenode<T>* tree, T& item, bool& found) const
{
    if (tree == nullptr)
    {
        found = false;
    }
    else if (item < tree->info)
    {
        retrieve(tree->left, item, found);
    }
    else if (item > tree->info)
    {
        retrieve(tree->right, item, found);
    }
    else
    {
        item = tree->info;
        found = true;
    }
}

template <class T>
void treetype<T>::printtree(ofstream& outfile) const
{
    print(root, outfile);
}

template <class T>
void treetype<T>::print(treenode<T>* tree, ofstream& outfile) const
{
    if (tree != nullptr)
    {
        print(tree->left, outfile);
        outfile << tree->info << " ";
        print(tree->right, outfile);
    }
}

int main()
{
    treetype<int> bst;

    if (bst.isempty())
        cout << "Tree is empty\n";
    else
        cout << "Tree is not empty\n";

    if (bst.isfull())
        cout << "Tree is full\n";
    else
        cout << "Tree is not full\n";

    int values[] = { 45, 25, 60, 15, 30, 50, 75, 10, 28, 48, 85 };

    for (int v : values)
        bst.insertitem(v);

    int arr[] = { 48, 30, 90 };

    for (int i = 0; i < 3; i++)
    {
        bool found;
        int item = arr[i];

        bst.retrieveitem(item, found);

        if (found)
            cout << item << " found\n";
        else
            cout << item << " NOT found\n";
    }

    ofstream outFile("output.txt");
    bst.printtree(outFile);
    outFile.close();

    cout << "Total nodes: " << bst.noofnodes() << endl;

    return 0;
}