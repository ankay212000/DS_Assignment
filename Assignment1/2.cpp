#include <iostream>

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
    for(int i=0;i<size;i++)  cout<<ar1[i]<<" ";
    cout<<"\n";
}

int main()
{
    int size1,size2,temp;
    cout<<"Enter the size of array 1: ";
    cin>>size1;
    cout<<"Enter the size of array 2: ";
    cin>>size2;
    int min,maxim;
    min=size1>size2?size2:size1;
    maxim=size1>size2?size1:size2;
    int ar1[size1],ar2[size2];
    cout<<"Enter array 1: \n";
    for (int i=0;i<size1;i++) cin>>ar1[i];
    cout<<"Enter array 2: \n";
    for (int i=0;i<size2;i++) cin>>ar2[i]; 
    for (int i=maxim-min;i<maxim;i++)
    {
        for(int j=0;j<min;j++)
        {
            if(size1==maxim)
            {
                temp=ar1[i];
                ar1[i]=ar2[j];
                ar2[j]=temp;
            }
            else if(size2==maxim)
            {
                temp=ar2[i];
                ar2[i]=ar1[j];
                ar1[j]=temp;
            }
        }
    }
    for(int i=0;i<maxim;i++)
    {
        for(int j=0;j<min;j++)
        {
            if(size1==maxim)
            {
                if(ar1[i]>ar2[j])
                {
                    temp=ar1[i];
                    ar1[i]=ar2[j];
                    ar2[j]=temp;
                }
            }
            else if(size2==maxim)
            {
                if(ar2[i]>ar1[j])
                {
                    temp=ar1[i];
                    ar1[i]=ar2[j];
                    ar2[j]=temp;
                }
            }
        }
    }
    cout<<"array1: \n";
    sort(size1==maxim?ar1:ar2,maxim);
    cout<<"array2: \n";
    sort(size1==min?ar1:ar2,min);     
}