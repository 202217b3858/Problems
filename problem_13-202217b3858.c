#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree (BST)
struct node {
    int data;
    struct node *right_child;
    struct node *left_child;
};

// Function to create a new node
struct node* new_node(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

// Function to search for a value in the BST
struct node* search(struct node *root, int x) {
    if (root == NULL || root->data == x)
        return root;
    else if (x > root->data)
        return search(root->right_child, x);
    else
        return search(root->left_child, x);
}

// Function to insert a new node in the BST
struct node* insert(struct node *root, int x) {
    if (root == NULL)
        return new_node(x);
    else if (x > root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child, x);
    return root;
}

// Function to find the node with the minimum value in the BST
struct node* find_minimum(struct node *root) {
    if (root == NULL)
        return NULL;
    else if (root->left_child != NULL)
        return find_minimum(root->left_child);
    return root;
}

// Function to delete a node from the BST
struct node* delete_node(struct node *root, int x) {
    if (root == NULL)
        return NULL;

    if (x > root->data)
        root->right_child = delete_node(root->right_child, x);
    else if (x < root->data)
        root->left_child = delete_node(root->left_child, x);
    else {
        // Case 1: No child
        if (root->left_child == NULL && root->right_child == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left_child == NULL || root->right_child == NULL) {
            struct node *temp;
            if (root->left_child == NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete_node(root->right_child, temp->data);
        }
    }
    return root;
}

// Function for in-order traversal of the BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 20);
    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);

    printf("Inorder traversal before deletion:\n");
    inorder(root);
    printf("\n");

    root = delete_node(root, 1);
    root = delete_node(root, 40);
    root = delete_node(root, 45);
    root = delete_node(root, 9);

    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    return 0;
}
