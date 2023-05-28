#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to create a new node
int createNode(int data, int tree[], int n) {
    if (n >= MAX_SIZE) {
        printf("Cannot create node. Tree is full!\n");
        return n;
    }

    tree[n] = data;
    return n + 1;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(int tree[], int root, int n) {
    if (root >= n || tree[root] == -1)
        return;

    inorderTraversal(tree, 2 * root + 1, n);
    printf("%d ", tree[root]);
    inorderTraversal(tree, 2 * root + 2, n);
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(int tree[], int root, int n) {
    if (root >= n || tree[root] == -1)
        return;

    printf("%d ", tree[root]);
    preorderTraversal(tree, 2 * root + 1, n);
    preorderTraversal(tree, 2 * root + 2, n);
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(int tree[], int root, int n) {
    if (root >= n || tree[root] == -1)
        return;

    postorderTraversal(tree, 2 * root + 1, n);
    postorderTraversal(tree, 2 * root + 2, n);
    printf("%d ", tree[root]);
}

// Function to search for a value in the binary tree
int search(int tree[], int root, int n, int value) {
    if (root >= n || tree[root] == -1)
        return 0;

    if (tree[root] == value)
        return 1;

    if (search(tree, 2 * root + 1, n, value))
        return 1;

    return search(tree, 2 * root + 2, n, value);
}

// Function to insert a value into the binary tree
int insert(int tree[], int root, int n, int value) {
    if (root >= n) {
        printf("Cannot insert value. Tree is full!\n");
        return n;
    }

    if (tree[root] == -1) {
        tree[root] = value;
        return n;
    }

    if (value < tree[root])
        n = insert(tree, 2 * root + 1, n, value);
    else
        n = insert(tree, 2 * root + 2, n, value);

    return n;
}

// Function to find the minimum value in the binary tree
int findMinValue(int tree[], int root, int n) {
    if (root >= n || tree[root] == -1)
        return -1;

    int left = findMinValue(tree, 2 * root + 1, n);
    if (left != -1)
        return left;

    return tree[root];
}

// Function to delete a value from the binary tree
int deleteValue(int tree[], int root, int n, int value) {
    if (root >= n || tree[root] == -1)
        return n;

    if (value < tree[root])
        n = deleteValue(tree, 2 * root + 1, n, value);
    else if (value > tree[root])
        n = deleteValue(tree, 2 * root + 2, n, value);
    else {
        // Node found, perform deletion
        if (tree[2 * root + 1] == -1 && tree[2 * root + 2] == -1) {
            // Case 1: Node has no children
            tree[root] = -1;
        } else if (tree[2 * root + 1] == -1) {
            // Case 2: Node has only right child
            tree[root] = tree[2 * root + 2];
            n = deleteValue(tree, 2 * root + 2, n, tree[2 * root + 2]);
        } else if (tree[2 * root + 2] == -1) {
            // Case 2: Node has only left child
            tree[root] = tree[2 * root + 1];
            n = deleteValue(tree, 2 * root + 1, n, tree[2 * root + 1]);
        } else {
            // Case 3: Node has both left and right child
            int minValue = findMinValue(tree, 2 * root + 2, n);
            tree[root] = minValue;
            n = deleteValue(tree, 2 * root + 2, n, minValue);
        }
    }

    return n;
}

int main() {
    int tree[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        tree[i] = -1;

    int n = 0;

    n = createNode(10, tree, n);
    n = createNode(5, tree, n);
    n = createNode(15, tree, n);
    n = createNode(3, tree, n);
    n = createNode(7, tree, n);

    printf("Inorder Traversal: ");
    inorderTraversal(tree, 0, n);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(tree, 0, n);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(tree, 0, n);
    printf("\n");

    int searchValue = 7;
    if (search(tree, 0, n, searchValue))
        printf("%d found in the binary tree.\n", searchValue);
    else
        printf("%d not found in the binary tree.\n", searchValue);

    int insertValue = 12;
    n = insert(tree, 0, n, insertValue);
    printf("Inserted %d into the binary tree.\n", insertValue);

    printf("Inorder Traversal after insertion: ");
    inorderTraversal(tree, 0, n);
    printf("\n");

    int deleteValue = 5;
    n = deleteValue(tree, 0, n, deleteValue);
    printf("Deleted %d from the binary tree.\n", deleteValue);

    printf("Inorder Traversal after deletion: ");
    inorderTraversal(tree, 0, n);
    printf("\n");

    return 0;
}
