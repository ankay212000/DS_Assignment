#include<iostream>

using namespace std;

void shuffle(int arr[],int n,int i)
{
    int temp;
    for(int j=i;j<n-1;j++)
    {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
    }
    for(int j=0;j<n;j++) cout<<arr[j]<<" ";
    cout<<"\n";
}



int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    char decision='y';
    int i=0;
    while(decision=='y')
    {
        if(i==n-1)
        i=0;
        shuffle(arr,n,i);
        i++;
        cout<<"Do you want to shuffle one more time? ";
        cin>>decision;
    }

}