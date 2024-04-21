// middle of linked list
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

Node* middle(Node* head) {
    
}

int main() {


    return 0;
}