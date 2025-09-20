#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int priority;
} Task;

typedef struct {
    Task* heap_array;
    int capacity;     
    int size;         
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* new_heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (new_heap == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_heap->size = 0;
    new_heap->capacity = capacity;
    new_heap->heap_array = (Task*)malloc(capacity * sizeof(Task));
    if (new_heap->heap_array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    return new_heap;
}

void swap_tasks(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void sift_up(MaxHeap* max_heap, int i) {
    int parent_index = (i - 1) / 2;
    while (i > 0 && max_heap->heap_array[parent_index].priority < max_heap->heap_array[i].priority) {
        swap_tasks(&max_heap->heap_array[i], &max_heap->heap_array[parent_index]);
        i = parent_index;
        parent_index = (i - 1) / 2;
    }
}

void sift_down(MaxHeap* max_heap, int i) {
    int largest_index = i;
    int left_child_index = 2 * i + 1;
    int right_child_index = 2 * i + 2;

    if (left_child_index < max_heap->size && max_heap->heap_array[left_child_index].priority > max_heap->heap_array[largest_index].priority) {
        largest_index = left_child_index;
    }

    if (right_child_index < max_heap->size && max_heap->heap_array[right_child_index].priority > max_heap->heap_array[largest_index].priority) {
        largest_index = right_child_index;
    }

    if (largest_index != i) {
        swap_tasks(&max_heap->heap_array[i], &max_heap->heap_array[largest_index]);
        sift_down(max_heap, largest_index);
    }
}

void insertTask(MaxHeap* max_heap, Task new_task) {
    if (max_heap->size == max_heap->capacity) {
        printf("Priority queue is full. Cannot insert task: %s\n", new_task.name);
        return;
    }

    max_heap->size++;
    int i = max_heap->size - 1;
    max_heap->heap_array[i] = new_task;

    sift_up(max_heap, i);
}

Task extractMax(MaxHeap* max_heap) {
    if (max_heap->size <= 0) {
        Task empty_task = {"", -1}; 
        return empty_task;
    }
    Task max_task = max_heap->heap_array[0];
    max_heap->heap_array[0] = max_heap->heap_array[max_heap->size - 1];
    max_heap->size--;
    sift_down(max_heap, 0);
    return max_task;
}

void printHeap(MaxHeap* max_heap) {
    printf("Current tasks in the priority queue (heap order):\n");
    for (int i = 0; i < max_heap->size; i++) {
        printf(" - Task: %s, Priority: %d\n", max_heap->heap_array[i].name, max_heap->heap_array[i].priority);
    }
    if (max_heap->size == 0) {
        printf("  (Queue is empty)\n");
    }
    printf("\n");
}

int main() {
    int initial_capacity = 10;
    MaxHeap* task_queue = createMaxHeap(initial_capacity);
    printf("--- Priority Queue System Simulation ---\n\n");
    printf("Inserting tasks with different priorities:\n");
    Task tasks[] = {
        {"Fix critical bug", 100},
        {"Write documentation", 20},
        {"Run server backups", 95},
        {"Review pull request", 50},
        {"Update website content", 30},
        {"User support ticket", 75}
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);
    for (int i = 0; i < num_tasks; i++) {
        printf("Inserting task: %s (Priority: %d)\n", tasks[i].name, tasks[i].priority);
        insertTask(task_queue, tasks[i]);
    }
    printf("\n--- All tasks inserted ---\n");
    printHeap(task_queue);
    printf("--- Processing tasks in order of priority (Highest first) ---\n\n");
    while (task_queue->size > 0) {
        Task high_priority_task = extractMax(task_queue);
        printf("--> Processing task: %s (Priority: %d)\n", high_priority_task.name, high_priority_task.priority);
        printHeap(task_queue);
    }
    printf("--- All tasks processed. Priority queue is empty. ---\n");
    free(task_queue->heap_array);
    free(task_queue);
    return 0;
}
