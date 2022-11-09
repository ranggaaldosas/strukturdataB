// RANGGA ALDO SASTROWARDOYO
// 5027211059
// ETS STRUKTUR DATA
#include <iostream>
using namespace std;

// Fungsi Node
struct Node
{
    string family;
    Node *left, *right, *parent;
};
// Global Pointer
Node *node, *root, *Nodenew;

// Fungsi untuk membuat ROOT
void create(string family)
{
    if (root != NULL)
    {
        cout << "\nTree sudah dibuat" << endl;
    }
    else
    {
        root = new Node();
        root->family = family;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }
}

// LEFT CHILD
Node *lchild(string family, Node *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree dulu" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->family << " Left Child Sudah Penuh" << endl;
            return NULL;
        }
        else
        {
            Nodenew = new Node();
            Nodenew->family = family;
            Nodenew->left = NULL;
            Nodenew->right = NULL;
            Nodenew->parent = node;
            node->left = Nodenew;
            return Nodenew;
        }
    }
}

// RIGHT CHILD
Node *rchild(string family, Node *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree dulu" << endl;
        return NULL;
    }
    else
    {
        if (node->right\90\ != NULL)
        {
            cout << "\nNode " << node->family << " Right Child sudah penuh" << endl;
            return NULL;
        }
        else
        {
            Nodenew = new Node();
            Nodenew->family = family;
            Nodenew->left = NULL;
            Nodenew->right = NULL;
            Nodenew->parent = node;
            node->right = Nodenew;
            return Nodenew;
        }
    }
}

// PRE ORDER
void preOrder(Node *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << node->family << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// IN ORDER
void inOrder(Node *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->family << ", ";
            inOrder(node->right);
        }
    }
}

// POST ORDER
void postOrder(Node *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->family << ", ";
        }
    }
}

// UPDATE
void update(string family, Node *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            string temp = node->family;
            node->family = family;
            cout << "\nUpdating " << temp << " into a new name: " << family << endl;
        }
    }
}

int main()
{
    // CREATE ROOT
    create("Buyut");

    Node *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *node10, *node11, *node12, *node13, *node14, *node15, *node16, *node17, *node18, *node19, *node20, *node21, *node22, *node23;

    node2 = lchild("MOYANG 1", root);
    node3 = rchild("MOYANG 2", root);
    node4 = lchild("KAKEK 1", node2);
    node5 = rchild("KAKEK 2", node2);
    node6 = lchild("KAKEK 3", node3);
    node7 = rchild("KAKEK 4", node3);
    node8 = lchild("PARENT 1", node4);
    node9 = lchild("PARENT 2", node5);
    node10 = lchild("PARENT 3", node6);
    node11 = rchild("PARENT 4", node6);
    node12 = rchild("PARENT 5", node7);
    node13 = lchild("ANAK 1", node8);
    node14 = rchild("ANAK 2", node8);
    node16 = lchild("CUCU", node13);

    cout << "======= PRE ORDER =======" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "======= In Order =======" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "======= Post Order =======" << endl;
    postOrder(root);
    cout << "\n"
         << endl;

    update("UpdateAnak", node13);

    cout << "\n####### Setelah direname #######" << endl;
    cout << "======= Pre Order =======" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "======= In Order =======" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "======= Post Order =======" << endl;
    postOrder(root);
}