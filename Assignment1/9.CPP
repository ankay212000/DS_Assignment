#include<iostream.h>
#include<conio.h>
int size1;
int flag=1;
struct nodetype
{
	int info;
	nodetype *next;
};
nodetype *start=NULL;
void newnode(int elem)
{
	nodetype *temp=new nodetype;
	temp->info=elem;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
void count()
{
	nodetype *temp=start;
	while(temp!=NULL)
	{
		size1++;
		temp=temp->next;
	}
}
void disp1()
{
	int s=0;
	nodetype *temp;
	nodetype *ptr;
	for(int j=1;j<=size1;j++)
	{
	ptr=start;
	temp=start;
	for(int i=1;i<size1-s;i++)
		{
		ptr=ptr->next;
		}
	for(int k=0;k<s;k++)
		{
		temp=temp->next;
		}
	s++;
	if(ptr->info!=temp->info)
	{
		flag=0;
	}
	}
}
void main()
{
	clrscr();
	newnode(1);
	newnode(2);
	newnode(3);
	newnode(2);
	newnode(1);
	count();
	disp1();
	if(flag)
	cout<<"Palindrome";
	else
	cout<<"Not Palindrome";
	getch();
}