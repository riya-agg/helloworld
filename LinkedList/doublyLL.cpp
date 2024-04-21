#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //ctor
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    //dtor
    ~Node() {
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
            this->prev = NULL;
        }
        cout << "Memory Freed!" << endl;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

// get length of the LL
int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, int d) {
    if(head ==  NULL) {
        Node* temp = new Node(d);
        head = temp;
        // tail =  temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtPos(Node* &tail, Node* &head, int d, int pos) {

    // insert at the beginning
    if(pos == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* newnode = new Node(d);
    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1) {
        temp = temp->next;
        cnt++;
    }

    // insert at the end
    if(temp->next == NULL) {
        // insertAtTail(tail, d);
        // return;
    }

    Node* ins = new Node(d);
    ins->next = temp->next;
    ins->prev = temp->next->prev;
    temp->next->prev = ins;
    temp->next = ins;

}

void deleteNode(int pos, Node* &head) {

    // deleting first node
    if(pos == 1) {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < pos) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete curr;

    }
}

int main() {    

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    //print(head);
    
    // insert at head
    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);

    // insert at position
    insertAtPos(tail, head, 14, 2);
    insertAtPos(tail, head, 15, 1);

    // delete
    deleteNode(2, head);

    cout << "LL: ";
    print(head);
    
    cout << "Length of LL: " << getLength(head);
    return 0;
}