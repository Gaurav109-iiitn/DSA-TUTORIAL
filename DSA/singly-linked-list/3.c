#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; 

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (low < root->key)
        printRange(root->left, low, high);

    if (root->key >= low && root->key <= high)
        printf("%d ", root->key);

    if (high > root->key)
        printRange(root->right, low, high);
}

void inOrder(struct Node* root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val, low, high;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nIn-order traversal of AVL Tree:\n");
    inOrder(root);
    printf("\n");

    printf("\nEnter range [low high]: ");
    scanf("%d %d", &low, &high);

    printf("Keys in the range [%d, %d]:\n", low, high);
    printRange(root, low, high);
    printf("\n");

    return 0;
}
