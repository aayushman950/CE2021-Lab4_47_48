#include "bst.h"
#include "linkedBST.h"
#include<iostream>
using namespace std;

void LinkedBST::addBST(int data) {
    cout << "Adding " << data << endl;
    this->root = add(this->root, data);
}

Node* LinkedBST::add(Node* root, int data) {
    if (root == NULL)
        root = getNewNode(data);
    else if (root->data > data) {
        root->left = add(root->left, data);
    }
    else {
        root->right = add(root->right, data);
    }
    return root;
}

Node* LinkedBST::getNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool LinkedBST::isEmpty() {
    return this->root == NULL;
}

bool LinkedBST::searchBST(int data) {
    if (search(this->root, data) == true) {
        cout << "Search result for " << data << ": " << search(this->root, data) << endl;
        return true;
    }
    else {
        return false;
    }
}

bool LinkedBST::search(Node* root, int data) {
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (root->data > data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

void LinkedBST::max(int& output) {
    if (!isEmpty()) {
        Node* temp = this->root;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        output = temp->data;
    }
    else {
        cout << "The tree is empty" << endl;
    }
}

void LinkedBST::min(int& output) {
    if (!isEmpty()) {
        Node* temp = this->root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        output = temp->data;
    }
    else {
        cout << "The tree is empty" << endl;
    }
}

void LinkedBST::inorder() {
    cout << "The traversal yields" << endl;
    inorder(this->root);
}

void LinkedBST::inorder(Node* root) {
    if (root == NULL)
        return;
    else {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

void LinkedBST::removeBST(int data) {
    cout << "Removing " << data << endl;
    this->root = Delete(this->root, data);
}

Node* LinkedBST::Delete(Node* root, int data) {
    if (root == NULL)
        return root;
    else if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            int output;
            this->min(output);
            root->data = output;
            root->right = Delete(root->right, output);
        }
    }
    return root;
}