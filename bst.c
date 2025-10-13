#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *left, *right;
};
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    int option, val;

    do {
        printf("\n**** MAIN MENU ****");
        printf("\n1. Inorder Traversal");
        printf("\n2. Insert");
        printf("\n3. Search");
        printf("\n4. Minimum Value");
        printf("\n5. Delete");
        printf("\n6. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val) != NULL)
                    printf("%d found in the tree.\n", val);
                else
                    printf("%d not found in the tree.\n", val);
                break;
            case 4:
                if (root != NULL) {
                    struct Node* minNode = minValueNode(root);
                    printf("Minimum value: %d\n", minNode->key);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 6);
    return 0;
}

