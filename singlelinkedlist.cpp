#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; //only have to add this for double linked liat rest is same as single linked list
};

Node* head = NULL;

void insert(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Case 1: Empty list
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    // Case 2: Insert at beginning
    if(value < head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }


    newNode->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

void deletenode(int value)
{
    if(head == NULL)
    {
        cout<<"List is empty "<<endl;
        return;
    }

    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"Node deleted "<<endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        cout<<"Node not found"<<endl;
        return;
    }
    else
    {
        Node* del= temp->next;
        temp->next = del->next;
        delete del;
        cout<<"NOde deleted "<<endl;
    }
}

void traverse()
{
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;
    cout<<"List: ";

    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

void search(int value)
{
    Node* temp = head;
    int position = 1;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            cout<<"Node found"<<endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout<<"Node not found"<<endl;
}

int main()
{
    int choice, value;

    do
    {
        cout<<"-----------Linked List-----------"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Delete "<<endl;
        cout<<"3. Traverse "<<endl;
        cout<<"4. Search "<<endl;
        cout<<"5. Exit "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Enter value to insert: ";
            cin>>value;
            insert(value);
            break;

            case 2:
            cout<<"Enetr value to delete: ";
            cin>>value;
            deletenode(value);
            break;

            case 3:
            traverse();
            break;

            case 4:
            cout<<"Enter value to search: ";
            cin>>value;
            search(value);
            break;

            case 5:
            cout<<"Exiting..."<<endl;
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }

        }while (choice != 5);

        return 0;
}