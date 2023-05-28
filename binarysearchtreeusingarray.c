#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Binary Search Tree (BST) node structure
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Global array to represent the binary search tree
int BST[MAX_SIZE];
int count = 0;

// Function to initialize the binary search tree
void initializeBST() {
    count = 0;
}

// Function to check if the binary search tree is empty
bool isBSTEmpty() {
    return count == 0;
}

// Function to check if the binary search tree is full
bool isBSTFull() {
    return count == MAX_SIZE;
}

// Function to insert a value into the binary search tree
void insertBST(int value) {
    if (isBSTFull()) {
        printf("Binary Search Tree is full. Cannot insert any more values.\n");
        return;
    }

    // If the binary search tree is empty, insert the value at the root
    if (isBSTEmpty()) {
        BST[0] = value;
        count++;
        printf("%d inserted into the Binary Search Tree.\n", value);
        return;
    }

    // Find the appropriate position to insert the value
    int currentIndex = 0;
    while (true) {
        if (value <= BST[currentIndex]) {
            // If value is less than or equal to the current node's value, move to the left child
            if (2 * currentIndex + 1 >= count)
                break;  // Left child does not exist, so break the loop
            currentIndex = 2 * currentIndex + 1;
        } else {
            // If value is greater than the current node's value, move to the right child
            if (2 * currentIndex + 2 >= count)
                break;  // Right child does not exist, so break the loop
            currentIndex = 2 * currentIndex + 2;
        }
    }

    // Insert the value at the appropriate position
    if (value <= BST[currentIndex]) {
        BST[2 * currentIndex + 1] = value;  // Insert as the left child
    } else {
        BST[2 * currentIndex + 2] = value;  // Insert as the right child
    }

    count++;
    printf("%d inserted into the Binary Search Tree.\n", value);
}

// Function to search for a value in the binary search tree
bool searchBST(int value) {
    if (isBSTEmpty()) {
        printf("Binary Search Tree is empty. Cannot perform search.\n");
        return false;
    }

    // Start the search from the root
    int currentIndex = 0;
    while (currentIndex < count) {
        if (value == BST[currentIndex]) {
            printf("%d found in the Binary Search Tree.\n", value);
            return true;
        } else if (value < BST[currentIndex]) {
            // Move to the left child
            currentIndex = 2 * currentIndex + 1;
        } else {
            // Move to the right child
            currentIndex = 2 * currentIndex + 2;
        }
    }

    printf("%d not found in the Binary Search Tree.\n", value);
    return false;
}

// Function to delete a value from the binary search tree
void deleteBST(int value) {
    if (isBSTEmpty()) {
        printf("Binary Search Tree is empty. Cannot perform deletion.\n");
        return;
    }

    // Find the node to delete
    int currentIndex = 0;
    int parentIndex = -1;
    bool isLeftChild = false;

    while (currentIndex < count) {
        if (value == BST[currentIndex]) {
            // Node found, so break the loop
            break;
        } else if (value < BST[currentIndex]) {
            // Move to the left child
            parentIndex = currentIndex;
            currentIndex = 2 * currentIndex + 1;
            isLeftChild = true;
        } else {
            // Move to the right child
            parentIndex = currentIndex;
            currentIndex = 2 * currentIndex + 2;
            isLeftChild = false;
        }
    }

    if (currentIndex >= count) {
        printf("%d not found in the Binary Search Tree. Deletion failed.\n", value);
        return;
    }

    // Node to delete found, perform deletion
    if (currentIndex == 0) {
        // Deleting the root node
        if (count == 1) {
            count = 0;
        } else {
            // Replace root with the maximum value from the left subtree
            int maxIndex = -1;
            for (int i = 2 * currentIndex + 1; i < count; i = 2 * i + 2) {
                maxIndex = i;
            }
            BST[currentIndex] = BST[maxIndex];
            currentIndex = maxIndex;

            // Shift all nodes below the deleted node to the left
            for (int i = maxIndex; i < count - 1; i++) {
                BST[i] = BST[i + 1];
            }
            count--;
        }
    } else {
        // Deleting a non-root node
        if (2 * currentIndex + 1 >= count) {
            // Node to delete has no left child
            if (2 * currentIndex + 2 >= count) {
                // Node to delete has no left or right child
                if (isLeftChild) {
                    BST[parentIndex * 2 + 1] = -1;
                } else {
                    BST[parentIndex * 2 + 2] = -1;
                }
            } else {
                // Node to delete has a right child
                if (isLeftChild) {
                    BST[parentIndex * 2 + 1] = BST[2 * currentIndex + 2];
                } else {
                    BST[parentIndex * 2 + 2] = BST[2 * currentIndex + 2];
                }
            }
        } else {
            // Node to delete has a left child
            if (2 * currentIndex + 2 >= count) {
                // Node to delete has no right child
                if (isLeftChild) {
                    BST[parentIndex * 2 + 1] = BST[2 * currentIndex + 1];
                } else {
                    BST[parentIndex * 2 + 2] = BST[2 * currentIndex + 1];
                }
            } else {
                // Node to delete has both left and right children
                int successorIndex = 2 * currentIndex + 2;
                while (2 * successorIndex + 1 < count) {
                    successorIndex = 2 * successorIndex + 1;
                }

                BST[currentIndex] = BST[successorIndex];
                currentIndex = successorIndex;

                // Shift all nodes below the deleted node to the left
                for (int i = successorIndex; i < count - 1; i++) {
                    BST[i] = BST[i + 1];
                }
                count--;
            }
        }
    }

    printf("%d deleted from the Binary Search Tree.\n", value);
}

// Function to perform inorder traversal of the binary search tree
void inorderTraversal(int currentIndex) {
    if (currentIndex < count) {
        inorderTraversal(2 * currentIndex + 1);  // Traverse left subtree
        printf("%d ", BST[currentIndex]);
        inorderTraversal(2 * currentIndex + 2);  // Traverse right subtree
    }
}

// Function to perform preorder traversal of the binary search tree
void preorderTraversal(int currentIndex) {
    if (currentIndex < count) {
        printf("%d ", BST[currentIndex]);
        preorderTraversal(2 * currentIndex + 1);  // Traverse left subtree
        preorderTraversal(2 * currentIndex + 2);  // Traverse right subtree
    }
}

// Function to perform postorder traversal of the binary search tree
void postorderTraversal(int currentIndex) {
    if (currentIndex < count) {
        postorderTraversal(2 * currentIndex + 1);  // Traverse left subtree
        postorderTraversal(2 * currentIndex + 2);  // Traverse right subtree
        printf("%d ", BST[currentIndex]);
    }
}

int main() {
    initializeBST();

    insertBST(50);
    insertBST(30);
    insertBST(70);
    insertBST(20);
    insertBST(40);
    insertBST(60);
    insertBST(80);

    printf("\nInorder Traversal: ");
    inorderTraversal(0);

    printf("\nPreorder Traversal: ");
    preorderTraversal(0);

    printf("\nPostorder Traversal: ");
    postorderTraversal(0);

    printf("\n\nSearching for 30:\n");
    searchBST(30);

    printf("\nSearching for 90:\n");
    searchBST(90);

    printf("\nDeleting 30:\n");
    deleteBST(30);

    printf("\nInorder Traversal after deletion: ");
    inorderTraversal(0);

    return 0;
}
