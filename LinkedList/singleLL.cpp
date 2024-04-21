// single linked list
#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed!"<<endl;
    }
};

void insertAtHead(Node* &head, int d) {

    // insertion at head
    // new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {

    // insertion at tail
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node* &head, int d, int pos) {

    // insertion at a given position
    Node* temp = new Node(d);
    Node* flg = head;
    int c = 1;
    while(c < pos-1) {
        c++;
        flg = flg->next;
    }
    temp->next = flg->next;
    flg->next = temp;

}

void deleteAtPos(Node* &head, int pos) {

    // deletion at given position
    // first node
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* prev = NULL;
        Node* curr = head;

        int c = 1;
        while(c < pos) {
            prev = curr;
            curr = curr->next;
            c++;
        }
        prev->next = curr->next;
        //if(curr->next == NULL) {
        //    tail = prev;
        //}
        curr->next = NULL;
        delete curr;
    }
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

    Node* node1 = new Node(5);
    Node* node2 = new Node(5);
    cout << node1->data<<endl;
    cout << node1->next<<endl;

    // head pointed to Node 1
    Node* head = node1;

    //tail
    Node* tail = node2;
    Node* head2 = node2;

    // insert 3 new nodes in the LL at head
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);

    // print the LL
    cout<<"Insertion at Head with Head = 5"<<endl;
    print(head);

    // insert 3 new nodes in the LL at tail
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);

    // print the LL
    //cout<<"Insertion at Tail with Head2 = 5"<<endl;
    //print(head2);

    // insert at 2nd position
    insertAtPos(head, 4, 2);
    cout<<"Insertion at 2nd pos with Head = 5"<<endl;
    print(head);

    insertAtPos(head2, 4, 2);
    //cout<<"Insertion at 2nd pos with Head2 = 5"<<endl;
    //print(head2);

    // deletion at pos 2
    cout<<"Deletion at 2nd pos with Head = 5"<<endl;
    deleteAtPos(head, 2);
    print(head);
}
