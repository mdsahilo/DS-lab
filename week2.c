#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Push (enqueue)
void push(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d inserted into queue\n", value);
}

// Pop (dequeue)
void pop(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is Empty! Nothing to delete\n");
        return;
    }
    struct Node* temp = q->front;
    printf("%d deleted from queue\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Peek (front element)
void peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element = %d\n", q->front->data);
    }
}

// Display queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Push (Enqueue)\n");
        printf("2. Pop (Dequeue)\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                push(q, value);
                break;
            case 2:
                pop(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

