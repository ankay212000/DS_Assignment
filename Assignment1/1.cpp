#include<iostream>

using namespace std;

void find_pairs(int a[],int key,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            if((a[i]+a[j]==key)&&i!=j)
            {
                cout<<"Pair found at index "<<i<<" and "<<j<<"("<<a[i]<<"+"<<a[j]<<")"<<endl;;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int key;
    cout<<"Enter the number to find pairs: ";
    cin>>key;
    find_pairs(a,key,n);
}