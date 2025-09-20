#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* create(struct node* h1, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
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

void pr(struct node* h1) {
    struct node* temp = h1;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int getMaxAbs(struct node* head) {
    int max = 0;
    while (head) {
        int absVal = head->data < 0 ? -head->data : head->data;
        if (absVal > max) max = absVal;
        head = head->next;
    }
    return max;
}


struct node* radixSort(struct node* head) {
    if (!head || !head->next) return head;
    int max = getMaxAbs(head);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        struct node* buckets[10] = {NULL}, *tails[10] = {NULL};
        struct node* curr = head;
        while (curr) {
            int digit = (curr->data / exp) % 10;
            if (!buckets[digit]) {
                buckets[digit] = tails[digit] = curr;
            } else {
                tails[digit]->next = curr;
                tails[digit] = curr;
            }
            curr = curr->next;
        }
        head = NULL;
        struct node** lastPtr = &head;
        for (int i = 0; i < 10; ++i) {
            if (buckets[i]) {
                *lastPtr = buckets[i];
                lastPtr = &tails[i]->next;
            }
        }
        *lastPtr = NULL;
    }
    return head;
}


struct node* reverse(struct node* head) {
    struct node* prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* radixSortNeg(struct node* head) {
    
    struct node* curr = head;
    while (curr) {
        curr->data = -curr->data;
        curr = curr->next;
    }
    head = radixSort(head);

    curr = head;
    while (curr) {
        curr->data = -curr->data;
        curr = curr->next;
    }
    return head;
}

struct node* radixSortWithNegatives(struct node* head) {
    struct node *neg = NULL, *pos = NULL;
    struct node *curr = head, *next;

    while (curr) {
        next = curr->next;
        if (curr->data < 0) {
            curr->next = neg;
            neg = curr;
        } else {
            curr->next = pos;
            pos = curr;
        }
        curr = next;
    }

    neg = radixSortNeg(neg);
    neg = reverse(neg);
    pos = radixSort(pos);

    if (!neg) return pos;
    head = neg;
    curr = neg;
    while (curr->next) curr = curr->next;
    curr->next = pos;
    return head;
}

int main() {
    int n, data;
    printf("enter details: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("enter data: ");
        scanf("%d", &data);
        head = create(head, data);
    }
    printf("Original list:\n");
    pr(head);

    head = radixSortWithNegatives(head);

    printf("Sorted list:\n");
    pr(head);

    return 0;
}