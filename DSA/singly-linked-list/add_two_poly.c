#include <stdio.h>
#include <stdlib.h>
struct node {
    int coe;
    int exp;
    struct node* next;
};
struct node* create_node(int coe, int exp) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coe = coe;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}
struct node* insert_end(struct node* head, int coe, int exp) {
    struct node* temp = create_node(coe, exp);
    if (head == NULL)
        return temp;
    struct node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    return head;
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coe, temp->exp);
        if (temp->next != NULL && temp->next->coe >= 0)
            printf("+");
        temp = temp->next;
    }
    printf("\n");
}
struct node* add_poly(struct node* p1, struct node* p2) {
    struct node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = insert_end(result, p1->coe, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = insert_end(result, p2->coe, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coe + p2->coe;
            if (sum != 0)
                result = insert_end(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insert_end(result, p1->coe, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insert_end(result, p2->coe, p2->exp);
        p2 = p2->next;
    }
    return result;
}
struct node* input_poly() {
    int n, coe, exp;
    struct node* head = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coe, &exp);
        head = insert_end(head, coe, exp);
    }
    return head;
}
int main() {
    printf("Enter first polynomial:\n");
    struct node* poly1 = input_poly();
    printf("Enter second polynomial:\n");
    struct node* poly2 = input_poly();

    printf("First polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);

    struct node* sum = add_poly(poly1, poly2);
    printf("Sum: ");
    display(sum);

    return 0;
}
