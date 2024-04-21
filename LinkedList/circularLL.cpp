// circular linked list
#include<iostream>
using namespace std;

class Node {
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

void print(Node* &tail) {
    Node* tmp = tail;
    if(tail == NULL) {
        cout<<"empty list";
    }
    // traversal
    do {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while(tmp != tail);
    cout<<endl;
}

void insertAtPos(Node* &tail, int ele, int d) {
    // head : tail->next in circular LL
    // case 1: empty list
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else {
        // assuming ele is present
        // case 2: only 1 node is there
        // case 3: more than 1 node is present
        Node* curr = tail;
        while(curr->data != ele) {
            curr = curr->next;
        }

        // element found
        // curr is the ele
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
    
}

void deleteNode(Node* &tail, int val) {

    Node* prev = tail;
    Node* curr = tail->next;
    // empty list
    if(tail == NULL) {
        return;
    }
    else {
        // only 1 node
        if(curr == prev) {
            tail = NULL;
        }
        // more than 1 node
        else {
            // deletion in circular LL
            while(curr->data != val) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            if(tail == curr) {
                tail = prev;
            }
            curr->next = NULL;
            delete curr;
        }
    }


}

int main() {
    Node* tail = NULL;

    insertAtPos(tail, 5, 3 );
    insertAtPos(tail, 3, 2);
    insertAtPos(tail, 3, 1);
    insertAtPos(tail, 2, 5);

    cout<<"Circular LL: ";
    print(tail);
    // deletion
    deleteNode(tail, 1);
    cout<<"Circular LL: ";
    print(tail);
    deleteNode(tail, 5);
    cout<<"Circular LL: ";
    print(tail);
    deleteNode(tail, 3);
    cout<<"Circular LL: ";
    print(tail);
    deleteNode(tail, 2);
    cout<<"Circular LL: ";
    print(tail);
    return 0;
}