#include <iostream>
using namespace std;

//Defining Linked list Structure
struct nodetype{
    int info;
    struct nodetype* next;
};

//Getnode function
struct nodetype* getnode(){
    nodetype *p;
    p =new nodetype; 
    return p;
}

//Global Declarations
nodetype *start1,*start2,*start3;
int size1 = 0, size2 = 0;

//Freenode function
void freenode(nodetype *p){
    delete p;
}

//Display the linked list
void display(){
    nodetype *ptr = start1;
    cout<<"\nLinked list => | ";
    while(ptr!=NULL){
        cout<<ptr->info<<" | ";
        ptr=ptr->next;
    }    
    ptr = start2;
    cout << "\nLinked list => | ";
    while (ptr != NULL)
    {
        cout << ptr->info << " | ";
        ptr = ptr->next;
    }
    cout << "\n";
}

//Insert a node at end of list 1
void insert1(int n)
{
    nodetype *ptr=start1;
    if(ptr==NULL){
        start1=getnode();
        start1->info=n;
        start1->next=NULL;
        return;
    }
    nodetype *p=getnode();
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    ptr->next=p;
    p->info=n;
    p->next=NULL;
}
//Insert a node at end of list 2
void insert2(int n)
{
    nodetype *ptr = start2;
    if (ptr == NULL)
    {
        start2 = getnode();
        start2->info = n;
        start2->next = NULL;
        return;
    }
    nodetype *p = getnode();
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->info = n;
    p->next = NULL;
}

//Insert a node at beginning of list 3
void insert3(int n)
{
    nodetype *p = getnode();
    p->info = n;
    p->next = start3;
    start3 = p;
}

void add()
{
    //Keeping the second list shorter always
    if(size2>size1){
        int temp = size1;
        size1=size2;
        size2=temp;
        nodetype *tempp = start1;
        start1 = start2;
        start2 = tempp;
    }
    int s = 0,n1,n2,cy=0,sum;
    nodetype *ptr1,*ptr2;
    for (int j = 1; j <= size1; j++)
    {
        ptr1 = start1;
        ptr2 = start2;
        for (int i = 1; i < size1 - s; i++)
        {
            ptr1 = ptr1->next;
        }
        for (int i = 1; i < size2 - s; i++)
        {
            ptr2 = ptr2->next;
        }
        s++;
        n1=ptr1->info;
        n2=ptr2->info;
        if(s>size2){
            n2=0;
        }
        sum = n1 + n2+cy;
        insert3(sum%10);
        if (sum >= 10)
        {
            cy = 1;
        }
        else{
            cy=0;
        }
    }
}
//Output List
void display3(){
    nodetype *ptr = start3;
    cout<<"\nOutput => ";
    while(ptr!=NULL){
        cout<<ptr->info;
        ptr=ptr->next;
    }    
    cout<<"\n";
}


//Driver code
int main()
{
    start1=NULL;
    start2=NULL;
    start3=NULL;
    int o,x,y,n,ind;
    cout << "\n1.Insert in List 1\n2.Insert in List 2\n3.Calculate Sum\n";
    while (1)
    {
        cout << "\nEnter no. of option - ";
        cin >> o;
        switch (o)
        {
        case (1):
            cout<<"Enter value to insert in List1= "; cin>>n;
            size1++;
            insert1(n); //Insert element in linked list at beginning.
            display();
            break;
        case (2):
            cout << "Enter value to insert in List2= "; cin >> n;
            size2++;
            insert2(n); //Insert element in linked list at beginning.
            display();
            break;
        case (3):
            add();
            display3(); //Display Linked list.
            exit(1);
        }
    }
    return 0;
}
