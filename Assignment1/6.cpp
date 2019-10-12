#include<iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
}*start=NULL;

node* getnode()
{
    struct node *temp;
    temp=new(struct node);
    return temp;
}

void insert(int d)
{
    struct node *temp;
    temp=getnode();
    temp->data=d;
    if(start==NULL)
    {
        start=temp;
        start->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
    
}

void display()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL";
}

int secondLast()
{
    struct node *temp;
    temp=start;
    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
        if(temp==NULL)
          break;
    }
    if(temp!=NULL)
      return temp->data;
    else 
      return -42;  
}

int main()
{
    int insertions,value;
    cout<<"Enter no. of insertions: ";
    cin>>insertions;
    for(int i=0;i<insertions;i++)
    {
        cout<<"Enter "<<(i+1)<<" element ";
        cin>>value;
        insert(value);
    }
    display();
    int c;
    c=secondLast();
    if(c==-42)
      cout<<"No second last element";
    else  
      cout<<"\n"<<c<<" ";
}