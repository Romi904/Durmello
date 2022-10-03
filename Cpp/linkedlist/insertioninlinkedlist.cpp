#include<iostream>
using namespace std;
class node
{
   public:
   int data;
   node* next;


   node(int val)
   {
      data=val;
     next=NULL;
   }


};




void insert_at_start(node* &head,int val)
{
    node *n=new node(val);
    n->next=head;
    head=n;

}
void insert_after_node(int val,node*& p)
{
    node *n=new node(val);
    n->next=p->next;
    p->next=n;



}

void insert_at_tail(node* &head ,int val)
{
    node* n=new node(val);
   if(head==NULL)
   {
       head=n;
       return;

   }
   node *temp=head;
   while(temp->next!=NULL)
   {
      temp=temp->next;

   }
   temp->next=n;
   n->next=NULL;
}
void display(node *head)
{

     node *temp=head;
     while(temp!=NULL)
     {
         cout<<temp->data<<"->";
         temp=temp->next;
     }
     cout<<"null"<<endl;
}
int main()
{

   node *head=NULL;
   node *p;
   int n;
   int s,key;
   int val;
   int element;
   cout<<"enter the no of elements in list";
   cin>>s;
   for(int i=0;i<s;i++)
   {
       cout<<"enter element "<<i+1<<" : ";
       cin>>n;
      insert_at_tail(head,n);
      cout<<endl;

   }
   cout<<endl;
    cout<<"The List is:"<<endl;
    display(head);
   cout<<"enter element u want to insert at start";
   cin>>val;
   insert_at_start(head,val);
   cout<<endl;
    cout<<"The List is:"<<endl;
    display(head);
    cout<<"enter the node position after which u want to insert new  node :";
    p=head;
    int i=1;
    int pos;
    cin>>pos;
    cout<<endl;
    cout<<"Enter the element u want to insert after "<<pos<<" :";
    cin>>element;
    while(i!=pos)
    {
         p=p->next;
         i++;
    }
    insert_after_node(element,p);
    cout<<endl;
    cout<<"The List is:"<<endl;
    display(head);
    return 0;
}






