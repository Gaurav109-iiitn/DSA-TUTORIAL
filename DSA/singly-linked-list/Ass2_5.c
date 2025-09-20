#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row, col, val;
    struct Node* next;
} Node;

Node* createNode(int row, int col, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


void insertNode(Node** head, int row, int col, int val) {
    if (val == 0) return;
    Node* newNode = createNode(row, col, val);
    if (*head == NULL || (*head)->row > row || ((*head)->row == row && (*head)->col > col)) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next && (curr->next->row < row || (curr->next->row == row && curr->next->col < col))) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}


Node* addSparseMatrices(Node* a, Node* b) {
    Node* result = NULL;
    Node *pa = a, *pb = b;
    while (pa && pb) {
        if (pa->row < pb->row || (pa->row == pb->row && pa->col < pb->col)) {
            insertNode(&result, pa->row, pa->col, pa->val);
            pa = pa->next;
        } else if (pb->row < pa->row || (pb->row == pa->row && pb->col < pa->col)) {
            insertNode(&result, pb->row, pb->col, pb->val);
            pb = pb->next;
        } else {
            int sum = pa->val + pb->val;
            if (sum != 0)
                insertNode(&result, pa->row, pa->col, sum);
            pa = pa->next;
            pb = pb->next;
        }
    }
    
    while (pa) {
        insertNode(&result, pa->row, pa->col, pa->val);
        pa = pa->next;
    }
    while (pb) {
        insertNode(&result, pb->row, pb->col, pb->val);
        pb = pb->next;
    }
    return result;
}

void printSparseMatrix(Node* head, int rows, int cols) {
    Node* curr = head;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (curr && curr->row == i && curr->col == j) {
                printf("%d ", curr->val);
                curr = curr->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}


void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {

    Node* A = NULL;
    insertNode(&A, 0, 0, 1);
    insertNode(&A, 1, 2, 2);
    insertNode(&A, 2, 1, 3);

    
    Node* B = NULL;
    insertNode(&B, 0, 0, 4);
    insertNode(&B, 1, 2, 5);
    insertNode(&B, 3, 3, 6);


    int maxRows = 4, maxCols = 4;

    printf("Matrix A:\n");
    printSparseMatrix(A, maxRows, maxCols);

    printf("\nMatrix B:\n");
    printSparseMatrix(B, maxRows, maxCols);

    Node* C = addSparseMatrices(A, B);

    printf("\nA + B:\n");
    printSparseMatrix(C, maxRows, maxCols);

    freeList(A);
    freeList(B);
    freeList(C);
    return 0;
}