#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *back;
}*start=NULL,*last=NULL;

node* getnode()
{
    struct node *temp;
    temp=new(struct node);
    return temp;
}

void insert(int d)
{
    struct node* temp;
    temp=getnode();
    temp->data=d;
    if(start==NULL)
    {
        start=temp;
        start->next=NULL;
        last=start;
        last->next=start;
        last->back=start;
        start->back=last;
    }
    else
    {
        last->next=temp;
        temp->back=last;
        temp->next=start;
        last=temp;
        start->back=last;
    }
}

void displayfront()
{
    struct node* temp;
    temp=start;
    while(temp->next!=start)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}

void displayback()
{
    struct node* temp;
    temp=last;
    while(temp->back!=last)
    {
        cout<<temp->data<<" ";
        temp=temp->back;
    }
    cout<<temp->data<<" ";
}

void reverseList(int n)
{
    struct node *i,*j;
    i=start;
    j=last;
    int temp;
    for(int p=1;p<=(n/2);p++)
    {
        temp=i->data;
        i->data=j->data;
        j->data=temp;

        i=i->next;
        j=j->back;
    }
}

int main()
{
    int n,value;
    cout<<"Enter no. of insertion: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<(i+1)<<"th element: ";
        cin>>value;
        insert(value);
    }
    displayfront();
    cout<<"\n after reversing\n";
    reverseList(n);
    displayfront();

}