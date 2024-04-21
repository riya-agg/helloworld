#include<iostream>
#include<stack>
using namespace std;

class Stack {
    // properties
    public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int val) {
        if(size - top > 0) {
            top++;
            arr[top] = val;
        }
        else {
            cout<< "\nStack Overflow!" ;
        }
    }

    void pop() {
        if(top == -1) {
            cout<< "\nStack Underflow!";
        }
        else {
            top--;
        }
    }

    int peek() { // top
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout<<"\nStack is empty";
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }

};

void pushAtBottom(stack<int>& s, int x) {
    // base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    pushAtBottom(s, x);

    s.push(num);

}

void reverseStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    reverseStack(s);

    pushAtBottom(s, num);
}

void sortedInsert(stack<int> &s, int num) {
    // base case
    if(s.empty() || s.top() < num) {
        // push num on the stack
        s.push(num);
        return;
    }

    int x = s.top();
    s.pop();

    sortedInsert(s, num);
    s.push(x);
}

void sortStack(stack<int> &s) {

    // concept of sortedInsert
    if(s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);
    sortedInsert(s, num);
}

void print(stack<int> s) {
    cout<< "\n";
    while(!s.empty()) {
        cout<< " " <<s.top();
        s.pop();
    }
    
}

int main() {

    /*Stack s(6);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"\nTop: "<< s.peek();
    s.push(4);
    s.push(5);
    cout<<"\nTop: "<< s.peek();
    s.pop();
    cout<<"\nTop: "<< s.peek();
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    cout<<"\nTop: "<< s.peek();*/
    
    // insert an element at the bottom in a given stack
    stack<int> s1;
    pushAtBottom(s1, 1);
    cout<<"\nS1 Top: "<< s1.top();
    pushAtBottom(s1, 5);
    cout<<"\nS1 Top: "<< s1.top();
    pushAtBottom(s1, 4);
    cout<<"\nS1 Top: "<< s1.top();
    
    print(s1);
    // reverse stack using recursion
    reverseStack(s1);
    cout<<"\nRev S1 Top: "<< s1.top();
     
    pushAtBottom(s1,7);
    pushAtBottom(s1,6);
    print(s1);

    // sort a stack
    cout<<"\nSorting the stack...";
    sortStack(s1);
    print(s1);

    return 0;
}