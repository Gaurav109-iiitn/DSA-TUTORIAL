#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    int level;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Node* insert(Node* node, int key);
Node* newNode(int key);
int height(Node* node);
int getBalance(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
void printLevelsWithBalance(Node* root);

Queue* createQueue();
void enqueue(Queue* q, Node* treeNode, int level);
QueueNode* dequeue(Queue* q);
int isQueueEmpty(Queue* q);

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node* node) {
    if (!node) return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node->height = 1 + (height(node->left) > height(node->right) ?
                        height(node->left) : height(node->right));

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

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* treeNode, int level) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->level = level;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

QueueNode* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;
    return temp;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void printLevelsWithBalance(Node* root) {
    if (!root) return;

    Queue* q = createQueue();
    enqueue(q, root, 0);

    int currentLevel = 0;
    printf("Level %d: ", currentLevel);

    while (!isQueueEmpty(q)) {
        QueueNode* qNode = dequeue(q);
        Node* node = qNode->treeNode;
        int level = qNode->level;

        if (level > currentLevel) {
            currentLevel = level;
            printf("\nLevel %d: ", currentLevel);
        }

        printf("%d(BF=%d)  ", node->key, getBalance(node));

        if (node->left)
            enqueue(q, node->left, level + 1);
        if (node->right)
            enqueue(q, node->right, level + 1);

        free(qNode);
    }
    printf("\n");
    free(q);
}
int main() {
    Node* root = NULL;
    int keys[] = {30, 20, 40, 10, 25, 35, 50, 5, 15};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Level-order traversal with balance factors:\n");
    printLevelsWithBalance(root);

    return 0;
}
