// basics of binary tree
#include<iostream>
#include<queue>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int n) {
        this->data = n;
        this->right = NULL;
        this->left = NULL;
    }
};

// create or build a binary tree
Node* buildTree(Node* root) {

    cout << "\nEnter data: ";
    int data;
    cin >> data;
    // create root node
    root = new Node(data);

    if(data == -1) 
        return NULL;
    
    // left part
    cout << "\nInsert data for left of "<<data;
    root->left = buildTree(root->left);

    // right part
    cout << "\nInsert data for right of "<<data;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTrav(Node* root) {
    // Level Order Traversal
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* tmp = q.front();
        q.pop();

        if(tmp == NULL) {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else 
        {
            cout<<tmp->data<<" ";
            if(tmp->left)
                q.push(tmp->left);
            
            if(tmp->right)
                q.push(tmp->right);
        }
    
    }
}


int main() { 

    Node* root = NULL;
    // create a tree
    root = buildTree(root);
    // 1 3 5 -1 -1 -1 2 6 -1 -1 7 -1 -1
    //     1
    //    / \
    //   3   2
    //  /   / \
    // 5   6   7

    // level order traversal
    cout<<"\nLevel Order Traversal: \n";
    levelOrderTrav(root);

    return 0;
}