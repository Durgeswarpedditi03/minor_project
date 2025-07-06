#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    const int MAX = 100;
    int arr[MAX];

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values (top of stack first):\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Push all elements into stack (last element will be root)
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        s.push(arr[i]);
    }

    // Pop from stack and create tree manually in full binary form
    Node* nodes[MAX];
    int index = 0;
    while (!s.empty()) {
        nodes[index++] = newNode(s.top());
        s.pop();
    }

    // Link children like a complete binary tree
    for (int i = 0; 2 * i + 1 < index; ++i) {
        if (2 * i + 1 < index) nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < index) nodes[i]->right = nodes[2 * i + 2];
    }

    Node* root = nodes[0];

    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
