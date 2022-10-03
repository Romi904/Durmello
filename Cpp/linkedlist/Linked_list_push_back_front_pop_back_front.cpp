#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* next;
    int data;

    node(int num)
    {
        next=NULL;
        data=num;
    }
};

class LinkedList{
    node* start;
    public:
    LinkedList()
    {
        start=NULL;
    }
    void push_back(int val)
    {
        if(start==NULL)
        {
            start= new node(val);
        }
        else
        {
            node* current=start;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next=new node(val);
        }

    }
    void push_front(int val)
    {
        if(start==NULL)
        {
            start=new node(val);
        }
        else{
            node *new_node=new node(val);
            new_node->next=start;
            start=new_node;
        }
    }
    void pop_back()
    {
        
        node *current=start;
        if(current==NULL)
        {
            cout<<"LIST EMPTY"<<endl;
        }
        else{
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=NULL;
        }
    }
    void pop_front()
    {
        node *current=start;
        if(current==NULL)
        {
            cout<<"LIST EMPTY"<<endl;
        
        }
        else
        {
            start=start->next;
        }
    }
    void print()
    {
        node *current=start;
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

};
int main()
{
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.print();
    l.pop_back();
    l.pop_front();
    l.print();
}
