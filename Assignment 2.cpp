#include <iostream> 
using namespace std;
class Cat
{
private:
    int queue[5]; 
    int front;
    int rear;
    int size;
public:
    Cat()
    {
        size = 5;
        front = -1;
        rear = -1;
    }
    void insert(int value)
    {
        if (rear == size - 1)
        {
            cout << "\n Cat is Full.\n";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        cout << "\nElement Inserted\n";
    }
    void dequeue() 
    {
        if (front == -1 || front > rear) 
        {
            cout << "Cat is Empty.\n";
            front = rear = -1;
            return;
        }
        cout << "\nDeleted Element: " << queue[front] << "\n";
        front++;
    }
    void peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nCat is Empty. No element to peek.\n";
            return;
        }
        cout << "\nFront Element is: " << queue[front] << "\n";
    }
}; 
int main()
{
    Cat fan;
    int value;
    cout << "Enter 1st digit: ";
    cin >> value; 
    fan.insert(value); 
    fan.peek();   
    fan.dequeue();
    fan.peek();    
    return 0;
}