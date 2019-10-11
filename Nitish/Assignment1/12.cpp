#include <iostream>
using namespace std;

class stacks
{

    int arr[5];
    int top = -1;

public:
    void push(int element)
    {
        if (top == 4)
        {
            cout << "Overflow";
        }

        arr[++top] = element;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow \n";
            return -1;
        }
        top = top - 1;
        return (arr[top + 1]);
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Empty";
            return ' ';
        }
        return arr[top];
    }
    int isempty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    int size()
    {
        return(top+1);
    }
    int min()
    {
        int min;
        for (int i=0;i<=top;i++){
            if(arr[i]<min){
                min = arr[i];
            }
        }
        return min;
    }
};
int main()
{
    stacks s1;
    int o, c;
    cout << "\n1.Push Element.\n2.Pop Element.\n3.Peek Element.\n"
            "4.Size.\n5.Min.\n6.Exit\n";
    while (1)
    {
        cout << "\nEnter no. of option - ";
        cin >> o;
        switch (o)
        {
        case (1):
            cout << "Enter value to push = ";
            cin >> c;
            s1.push(c);
            cout << c << " pushed." << endl;
            break;
        case (2):
            c = s1.pop();
            if (c != -1)
                cout << c << " popped." << endl;
            break;
        case (3):
            c = s1.peek();
            cout << c << endl;
            break;
        case (4):
            c = s1.size();
            cout <<"Size=> "<< c << endl;
            break;
        case (5):
            c = s1.min();
            cout <<"Min=> "<< c << endl;
            break;
        case (6):
            exit(1);
        }
    }
}
