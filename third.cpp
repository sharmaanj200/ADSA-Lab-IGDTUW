/*
Program 3:
WAP to implement two stacks using a single array of size n. Write push and pop operations for both the stacks and it should be allowed to push an element in either of the stacks till there is space in the array. The program should also print the contents of the stack when desired.
*/

#include<bits/stdc++.h>
using namespace std;


class TwoStack {
    int top1;
    int top2;
    int size;
    int *arr;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        top1 = -1;
        top2 = s;
        this->size = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
      if ((top2 - top1) > 1) {
        top1++;
        arr[top1] = num;
      }
    }

    // Push in stack 2.
    void push2(int num) {
        if ((top2 - top1) > 1) {
        top2--;
        arr[top2] = num;
      }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else return -1;
    }

    void print()
    {
        cout<<"Stack 1 contents are: ";
        for(int i=0; i<=top1; i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
        cout<<"Stack 2 contents are: ";
        for(int i=size-1; i>=top2; i--)
        {
            cout<<arr[i]<<" ";
        }
    }
};


int main()
{
    TwoStack ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "
         << ": " << ts.pop1() << endl; 
    ts.push2(40); 
    cout << "Popped element from stack2 is "
         << ": " << ts.pop2() << endl; 

    ts.print();
    return 0; 
}