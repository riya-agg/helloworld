// reverse linked list
#include<iostream>
using namespace std;
//#include "singleLL.cpp"

class Node
{
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

// 1. Iterative approach
void revItr(Node* &head) {

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    if(head == NULL || head->next == NULL) {
        return ;
    }

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
    }

    head = prev;

}

// 2. Recursive approach
void revRec(Node* &head, Node* curr, Node* prev) {

    // base case
    if(curr == NULL) {
        head = prev;
        return;
    }

    // recursion 
    revRec(head, curr->next, curr);
    curr->next = prev;

}

void insertAtHead(Node* &head, int d) {

    // insertion at head
    // new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* &head) {

    Node *temp = head;
    while(temp != NULL) {
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {

    Node* head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);

    cout<< "Original LL: " ;
    print(head);
    cout<<endl;

    //revItr(head);
    cout<< "Iterative Reversed LL: ";
    print(head);
    cout<<endl;
 
    revRec(head, head, nullptr);
    cout<< "Recursive Reversed LL: ";
    print(head);
    cout<<endl;

    return 0;
}
