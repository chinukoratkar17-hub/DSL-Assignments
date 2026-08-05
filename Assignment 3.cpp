#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }

    void createList()
    {
        int n, value;
        cout << "\nEnter number of nodes:";
        cin >> n;
        if (n <= 0)
        {
            cout << "Invalid number of nodes.";
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << "enter value" << i << ":";
            cin >> value;
            insertEnd(value);
        }
        cout << "\nLinkedList Created.\n";
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked list is Empty.\n";
            return;
        }
        Node *temp = head;
        cout << "\nLiked List:";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "\nList is Empty.\n";
            return;
        }
        Node *temp = head;
        Node *previous = NULL;
        if (head->data == value)
        {
            head = head->next;
            delete temp;
            cout << "\nNode Deleted.\n";
            return;
        }
        while (temp != NULL && temp->data != value)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Value not found.\n";
            return;
        }
        previous->next = temp->next;
        delete temp;
        cout << "\nNode Deleted.\n";
    }
};

int main()
{
    LinkedList L;
    int value;
    L.createList();
    L.display();
    cout << "\nEnter a value:";
    cin >> value;
    L.insertEnd(value);
    L.display();

    cout << "\nEnter the value you want to delete:";
    cin >> value;
    L.deleteNode(value);
    L.display();

    return 0;
}