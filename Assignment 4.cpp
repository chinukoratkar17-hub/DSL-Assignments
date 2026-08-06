#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Binary
{
    Node *root;
public:
    Binary()
    {
        root=NULL;
    }
    Node* create()
    {
        int value;
        cout<<"\nEnter node value (-1 for No Node): ";
        cin>>value;

        if(value==-1)
            return NULL;

        Node *newNode=new Node;
        newNode->data=value;

        cout<<"Enter Left Child of "<<value<<": ";
        newNode->left=create();

        cout<<"Enter Right Child of "<<value<<": ";
        newNode->right=create();

        return newNode;
    }
    void build()
    {
        cout<<"\nCreate Binary Tree\n";
        root=create();
    }
    void inorder(Node *temp)
    {
        if(temp==NULL)
            return;

        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
    void preorder(Node *temp)
    {
        if(temp==NULL)
            return;

        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(Node *temp)
    {
        if(temp==NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
    void menu()
    {
        int choice;
        do
        {
            cout<<"\n\n1. Inorder Traversal";
            cout<<"\n2. Preorder Traversal";
            cout<<"\n3. Postorder Traversal";
            cout<<"\n4. Exit";
            cout<<"\nEnter your choice: ";
            cin>>choice;

            switch(choice)
            {
                case 1:
                    cout<<"\nInorder Traversal: ";
                    inorder(root);
                    break;

                case 2:
                    cout<<"\nPreorder Traversal: ";
                    preorder(root);
                    break;

                case 3:
                    cout<<"\nPostorder Traversal: ";
                    postorder(root);
                    break;

                case 4:
                    cout<<"\nProgram Ended.";
                    break;

                default:
                    cout<<"\nInvalid Choice!";
            }

        }while(choice!=4);
    }
};
int main()
{
    Binary b;

    b.build();

    b.menu();

    return 0;
}