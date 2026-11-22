
#include <iostream>
using namespace std;

#define MAX 50

int q[MAX];
int front = -1, rear = -1;

// Check Empty
int isEmpty()
{
    return (front == -1);
}

// Find Size
int size()
{
    if(isEmpty())
        return 0;

    return (rear - front + MAX) % MAX + 1;
}

// Insertion
void insert(int x)
{
    if((rear + 1) % MAX == front)
    {
        cout << "Queue Overflow" << endl;
        return;
    }

    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    q[rear] = x;
}

// Deletion
void deleteElement()
{
    if(isEmpty())
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Deleted element: " << q[front] << endl;

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Display
void display()
{
    if(isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    int i = front;

    cout << "Queue elements: ";

    while(1)
    {
        cout << q[i] << " ";

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    cout << endl;
}

int main()
{
    int choice, x;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Size";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Size: " << size() << endl;
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while(choice != 5);

    return 0;
}
