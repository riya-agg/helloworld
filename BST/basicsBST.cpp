// Binary Search Tree Basics
#include<iostream>
#include<queue>
using namespace std;

class Node {

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTrav(Node* &root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* tmp = q.front();
        q.pop();

        if(tmp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout<< tmp->data << " ";
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }

    }

}

Node* insertIntoBST(Node* root, int data) {

    // base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);

    return root;
}

void takeInput(Node* &root) {

    // take input until user enters -1
    int data;
    cout<<">> ";
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout<<">> ";
        cin >> data;
    }
}

Node* minVal(Node* root) {
    Node* tmp = root;
    while(tmp->left != NULL) 
        tmp = tmp->left;

    return tmp;
}

Node* maxVal(Node* root) {
    Node* tmp = root;
    while(tmp->right != NULL) 
        tmp = tmp->right;

    return tmp;
}

int main() {

    Node* root = NULL;

    cout<<" \nEnter data to create BST: \n";
    takeInput(root);

    cout<<"\n\nLevel Order Traversal of BST: \n";
    levelOrderTrav(root);

    Node* min = minVal(root);
    Node* max = maxVal(root);
    cout<<"\nMin: " << min->data;
    cout<<"\nMax: " << max->data;
    return 0;
}