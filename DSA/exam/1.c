#include <stdio.h>
#include <stdlib.h>

struct node {
    float coe;
    int exp;
    struct node* next;
};

struct node* head = NULL;

struct node* create(struct node* h, float coe, int exp) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coe = coe;
    temp->exp = exp;
    temp->next = NULL;

    if (h == NULL || h->exp < exp) {
        temp->next = h;
        h = temp;
    } else {
        struct node* curr = NULL;
        struct node* tail = h;
        while (tail != NULL && tail->exp >= exp) {
            if (tail->exp == exp) {
                tail->coe += coe;
                free(temp);
                return h;
            }
            curr = tail;
            tail = tail->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    return h;
}
struct node* add(struct node* h1,struct node* h2){

}

void print(struct node* h) {
    struct node* curr = h;
    int first = 1;
    while (curr != NULL) {
        if (curr->coe != 0) {
            if (!first)
            printf(" + ");
            printf("%.1fx^%d", curr->coe, curr->exp);
            first = 0;
        }
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter each term (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        float coe;
        int exp;
        scanf("%f %d", &coe, &exp);
        head = create(head, coe, exp);
    }
    printf("Polynomial: ");
    print(head);

    return 0;
}
