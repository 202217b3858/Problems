#include <stdio.h>
#include <stdlib.h>

// Node structure to define the structure of the node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert nodes
Node* insert(Node* root, int data) {
    // If tree is empty, new node becomes the root
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    // Queue to traverse the tree and find the position to insert the node
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
        Node* temp = queue[front++];

        // Insert node as the left child of the parent node
        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }

        // Insert node as the right child of the parent node
        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

/* Function to delete the given deepest node (d_node) in binary tree */
void deleteDeepest(Node* root, Node* d_node) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    Node* temp;
    while (front != rear) {
        temp = queue[front++];

        if (temp == d_node) {
            temp = NULL;
            free(d_node);
            return;
        }

        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = temp->right;
            }
        }

        if (temp->left) {
            if (temp->lef
