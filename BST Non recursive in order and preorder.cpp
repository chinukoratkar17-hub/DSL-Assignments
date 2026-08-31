#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BST
{
private:
    Node *root;
    Node *insert(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            cout << "Duplicate value not inserted.\n";
        }
        return root;
    }
public:
    BST()
    {
        root = NULL;
    }
    void createBST()
    {
        int n, value;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter node values:\n";
        for (int i = 1; i <= n; i++)
        {
            cin >> value;
            root = insert(root, value);
        }
    }
    void inorder()
    {
        stack<Node *> s;
        Node *current = root;
        cout << "Inorder Traversal: ";
        while (current != NULL || !s.empty())
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
        cout << endl;
    }
    void preorder()
    {
        if (root == NULL)
        {
            return;
        }
        stack<Node *> s;
        s.push(root);
        cout << "Non recursive preorder traversal: ";
        while (!s.empty())
        {
            Node *current = s.top();
            s.pop();

            cout << current->data << " ";

            if (current->right != NULL)
            {
                s.push(current->right);
            }
            if (current->left != NULL)
            {
                s.push(current->left);
            }
        }
        cout << endl;
    }
};
int main()
{
    BST tree;

    tree.createBST();
    tree.inorder();
    tree.preorder();

    return 0;
}