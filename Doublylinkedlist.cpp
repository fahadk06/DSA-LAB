#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; // only have to add this for doubly linked list rest is same as singlr linked list
};

Node* head = NULL;

// Function Prototypes
void insert(int value);
void deleteNode(int value);
void traverse();
void search(int value);

// Sorted Insertion
void insert(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Insert at beginning
    if (value < head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

// Deletion
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    // Delete first node
    if (temp == head)
    {
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node deleted" << endl;
}

// Traversal
void traverse()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Search
void search(int value)
{
    Node* temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found at position " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found" << endl;
}

// Main Function
int main()
{
    int choice, value;

    do
    {
        cout << "\n----------- Doubly Linked List -----------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 3:
                traverse();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}