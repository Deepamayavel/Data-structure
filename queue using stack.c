#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

typedef struct {
    Stack s1, s2;
} Queue;

void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}


void enqueue(Queue *q, int item) {
    push(&q->s1, item);
}


int dequeue(Queue *q) {
    if (isEmpty(&q->s2)) {

        while (!isEmpty(&q->s1)) {
            int x = pop(&q->s1);
            push(&q->s2, x);
        }
    }

    if (isEmpty(&q->s2)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(&q->s2);
}

int front(Queue *q) {
    if (isEmpty(&q->s2)) {

        while (!isEmpty(&q->s1)) {
            int x = pop(&q->s1);
            push(&q->s2, x);
        }
    }
    if (isEmpty(&q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->s2.data[q->s2.top];
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", front(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    printf("Front element: %d\n", front(&q));

    return 0;
}
