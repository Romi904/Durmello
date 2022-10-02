// Code By- Romijul Laskar
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int val) //construct
    {
        data = val;
        link = NULL;
    }
};
void display(node *head);
bool search(node *head, int val);
void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = n;
}
void insertBeg(node *&head, int val)
{
    node *n = new node(val);
    n->link = head;
    head = n;
    cout << val << " inserted at the beginning.\n";
    return;
}
void insert(node *&head)
{
    int val, pos;
    cout << "Enter position you wants to insert- ";
    cin >> pos;
    cout << "Enter number - ";
    cin >> val;
    if(pos==1)
    {
        insertBeg(head,val);
        return;
    }
    node *temp = head;
    node *cur = new node(val);
    while (pos != 2)
    {
        temp = temp->link;
        pos--;
    }
    cur->link = temp->link;
    temp->link = cur;
}
void del(node *head)
{
    int val;
    cout << "\nEnter that number you want to delete- ";
    cin >> val;
    if (search(head, val))
    {
        node *temp = head;
        if (temp->data == val)
        {
            temp = temp->link;
            display(temp);
            exit(0);
        }
        while (temp->link->data != val)
        {
            temp = temp->link;
        }
        temp->link = temp->link->link;
    }
    else
    {
        cout << "Key Not Present !!\n";
    }
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->link != NULL)
        {
            cout << " -> ";
        }
        temp = temp->link;
    }
    cout << endl;
    return;
}
bool search(node *head, int val)
{
    int pos = 1;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "At posintion " << pos << endl;
            return true;
        }
        temp = temp->link;
        pos++;
    }
    return false;
}
void searchKey(node *head)
{
    int key;
    cout << "Enter Key To be Search - ";
    cin >> key;
    if (search(head, key))
    {
        cout << " Key Found" << endl;
    }
    else
    {
        cout << "Key Not Found";
    }
}
int main()
{
    system("CLS");
    cout<<"********* LINKED lIST *************\n";
    int n, i, c;
    node *head = NULL;
    cout << "Enter number of node - ";
    cin >> n;
    // random function
    srand(time(0)); // Use current time as seed for random generator
    for (i = 0; i < n; i++)
    {
        insert(head, (rand() % 50));
    }
    display(head);
here:
    cout << "\n1- Insert at the begining\n2- Insert at given position\n3- Search a Key\n4- display\n5- Delete a given key\n0- Exit\n Your Choice -";
    cin >> c;
    switch (c)
    {
    case 1:
        insertBeg(head, (rand() % 50));
        display(head);
        break;
    case 2:
        insert(head);
        break;
    case 3:
        searchKey(head);
        break;
    case 4:
        display(head);
        break;
    case 5:
        del(head);
        display(head);
        break;
    case 0:
        return 0;
    default:
        cout << setw(50) << "Invalid Choice\n";
        break;
    }
    goto here;
}
