#include<iostream>

using namespace std;

void sort(int ar1[],int size)
{
    int temp;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(ar1[i]>ar1[j])
            {
                temp=ar1[i];
                ar1[i]=ar1[j];
                ar1[j]=temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter no. element: ";
    cin>>n;
    int arr[n],temp;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,n);
    for(int i=1;i<n;i=i+2)
    {
        if(n%2==0&&i==n-1)
        continue;
        else
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
                                                
    
}