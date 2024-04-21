#include<iostream>
using namespace std;
/*

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
private:
    void insertNode(Node* &head, Node* &tail, int val) {
        Node* tmp = new Node(val);
        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
    }
public:
    Node* copyRandomList(Node* head) {

        // step1: create a clone list using next ptr
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL) {
            insertNode(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // step2: add cloneNodes in between the original list
        Node* original = head;
        Node* clone = cloneHead;

        while(original != NULL && clone != NULL) {

            Node* nxt = original->next;
            original->next = clone;
            original = nxt;
            
            nxt = clone->next;
            clone->next = original;
            clone = nxt;

        }

        // step3: copy random pointers
        temp = head;
        while(temp != NULL) {
            if(temp->next != NULL) {
                if(temp->random != NULL)
                    temp->next->random = temp->random->next;
                else
                    temp->next->random = NULL;
            }
            temp = temp->next->next;
        }

        // step4: revert the changes done in step 2
        original = head;
        clone = cloneHead;
        while(original != NULL && clone != NULL) {

            original->next = clone->next;
            original = original->next;

            if(original != NULL)
                clone->next = original->next;
            clone = clone->next;

        }

        return cloneHead;        
        
    }
};
*/

int main() {
    cout<< "Clone list with random pointers!"<<endl;
    cout<< "Leetcode: 138";
    return 0;
}