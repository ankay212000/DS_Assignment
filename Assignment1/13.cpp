#include <iostream>
using namespace std;

class MinQueue
{
    int size = 5;
    int arr[5];
    int front = -1, rear = -1;

public:
    void add(int x)
    {
        if (isfull())
        {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
    }
    int remove()
    {
        //Queue is Empty
        if (isempty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        int element = arr[front];
        //Queue have only 1 element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        cout << "Deleted element => " << element << endl;
        return (element);
    }
    void disp()
    {
        if(isempty()){
            cout<<"Queue Empty"<<endl;
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[i] << " ";
        cout << endl;
    }
    int isempty()
    {
        if (front == -1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if ((front == rear + 1) || (front == 0 && rear == size - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int min(){
        int i = front;
        int min;
        while (i != rear)
        {
            if(arr[i]<min){
                min=arr[i];
            }
            i = (i + 1) % size;
        }
        //Last case when i=rear ->
        if (arr[i] < min)
        {
            min=arr[i];
        }
        return min;
    }
    int QueueSize(){
        int s=(size-front+rear)%size +1;
        return s;
    }
};

int main()
{
    MinQueue q1;
    int o, n;
    cout << "\n1.Add Element.\n2.Remove Element.\n3.Display Queue"
            "\n4.Minimum Element\n5.Size of Queue\n6.Exit\n";
    while (1)
    {
        cout << "\nEnter no. of option - ";
        cin >> o;
        switch (o)
        {
        case (1):
            if (q1.isfull())
            {
                cout << "Queue Full" << endl;
                break;
            }
            cout << "Enter value to add = ";
            cin >> n;
            q1.add(n);
            cout << n << " added." << endl;
            break;
        case (2):
            n = q1.remove();
            if (n != -1)
                cout << n << " removed." << endl;
            break;
        case (3):
            q1.disp();
            break;
        case (4):
            n=q1.min();
            cout <<"Min => "<< n << endl;
            break;
        case (5):
            n = q1.QueueSize();
            cout << "Size => " << n << endl;
            break;
        case (6):
            exit(1);
        }
    }
}