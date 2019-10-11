#include<iostream>

int avail=1;
int start=1;

using namespace std;
struct node
{
    int data;
    int next;
}single[9];

void initialise()
{
    for(int i=1;i<9;i++)
    {
        single[i].next=i+1;
    }
    single[9].next=-1;
}

int getnode()
{
    int p;
    if(avail==9)
    {
        cout<<"Overflow";
    }
    else
    {
        p=avail;
        avail=single[avail].next;
        return p;
    }    
}

void insert(int d)
{
    int temp,p;
    temp=getnode();
    single[temp].data=d;
    if(avail==2)
    {
        start=temp;
        single[start].next=-1;
    }
    else
    {
        p=start;
        while(single[p].next!=-1)
        {
            p=single[p].next;
        }
        single[p].next=temp;
        single[temp].next=-1;   
    }
}

void reverseList(int n)
{
    int temp;
    for(int i=1;i<=(n/2);i++)
    {
        temp=single[i].data;
        single[i].data=single[n-i+1].data;
        single[n-i+1].data=temp;
    }
}

void display()
{
    int temp;
    temp=start;
    while(single[temp].next!=-1)
    {
        cout<<single[temp].data<<" ";
        temp=single[temp].next;
    }
    cout<<single[temp].data<<" NULL";
}

int main()
{
    initialise();
    int n,value;
    cout<<"Enter no. of insertion: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<(i+1)<<"th element: ";
        cin>>value;
        insert(value); 
    }
    display();
    cout<<"\n";
    reverseList(n);
    display();
}