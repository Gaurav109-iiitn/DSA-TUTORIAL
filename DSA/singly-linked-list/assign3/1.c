#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *down;
} Node;

Node* createNode(int data) {
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = data;
    newnode->right = newnode->down = NULL;
    return newnode;
}

void printRowMajor(Node* rowHeads[], int rows) {
    for (int i = 0; i < rows; i++) {
        Node* curr = rowHeads[i];
        while (curr) {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    Node* rowHeads[rows];
    Node* matrix[rows][cols];

    printf("Enter matrix elements row-wise:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val;
            scanf("%d", &val);
            matrix[i][j] = createNode(val);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j < cols - 1)
                matrix[i][j]->right = matrix[i][j + 1];
            if (i < rows - 1)
                matrix[i][j]->down = matrix[i + 1][j];
        }
        rowHeads[i] = matrix[i][0];
    }
    printf("\nMatrix (row-wise):\n");
    printRowMajor(rowHeads, rows);

    return 0;
}
