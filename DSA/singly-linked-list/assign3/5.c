#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int timestamp;
    int eventType;
    int priority;
    struct Node* next;
} Node;


Node* newEvent(int ts, int type, int pr) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->timestamp = ts;
    node->eventType = type;
    node->priority = pr;
    node->next = NULL;
    return node;
}


Node* pushEvent(Node* head, int ts, int type, int pr) {
    Node* temp = newEvent(ts, type, pr);

    
    if (!head || head->priority < pr ||
        (head->priority == pr && head->timestamp > ts)) {
        temp->next = head;
        return temp;
    }

    
    Node* cur = head;
    while (cur->next &&
           (cur->next->priority > pr ||
           (cur->next->priority == pr && cur->next->timestamp <= ts))) {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
    return head;
}


Node* popEvent(Node* head) {
    if (!head) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


void processEvents(Node* head) {
    while (head) {
        printf("EventType: %d, Timestamp: %d, Priority: %d\n",
               head->eventType, head->timestamp, head->priority);
        head = popEvent(head);
    }
}


int main() {
    Node* eventQueue = NULL;

    eventQueue = pushEvent(eventQueue, 10, 1, 2);
    eventQueue = pushEvent(eventQueue, 5, 2, 3);
    eventQueue = pushEvent(eventQueue, 15, 3, 2);
    eventQueue = pushEvent(eventQueue, 8, 4, 3);
    eventQueue = pushEvent(eventQueue, 12, 5, 1);

    printf("Processing Events in Priority Order:\n");
    processEvents(eventQueue);

    return 0;
}
