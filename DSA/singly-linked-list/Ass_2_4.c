#include<stdio.h>
#include<stdlib.h>

struct node {
    int row;
    int col;
    int value;
    struct node* next;
};

struct node* head = NULL;

struct node* create(struct node* h1, int row, int col, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->value = value;
    temp->next = NULL;
    if (h1 == NULL) {
        return temp;
    } else {
        struct node* curr = h1;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    return h1;
}

void display(struct node* head) {
    struct node* temp = head;
    printf("Row\tCol\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}
    
    int main() {

        int n, row, col, value;
        printf("Enter the number of non-zero elements for initial list: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            printf("Enter row, column, and value for element %d: ", i + 1);
            scanf("%d %d %d", &row, &col, &value);
            head = create(head, row, col, value);
        }
        display(head);
    
        printf("Enter the number of non-zero elements: ");
        scanf("%d", &n);

        struct node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        head = NULL;
        for (int i = 0; i < n; i++) {
            printf("Enter row, column, and value for element %d: ", i + 1);
            scanf("%d %d %d", &row, &col, &value);
            head = create(head, row, col, value);
        }
        printf("The sparse matrix in linked list form is:\n");
        display(head);
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    
        return 0;
    }
