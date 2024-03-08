
//1. Remove Duplicate Element from Sorted Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    printf("Input:\n");
    printList(head);

    removeDuplicates(head);

    printf("\nOutput:\n");
    printList(head);

    return 0;
}

//2. Rotate a Doubly Linked List by N nodes:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateDoublyLinkedList(struct Node* head, int N) {
    if (head == NULL || N <= 0) {
        return head;
    }

    struct Node* current = head;
    int count = 1;

    
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return head;
    }

    
    struct Node* newHead = current->next;
    current->next = NULL;

    
    current = newHead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;
    head->prev = current;

    return newHead;
}

void printDoublyLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = createNode('a');
    head1->next = createNode('b');
    head1->next->prev = head1;
    head1->next->next = createNode('c');
    head1->next->next->prev = head1->next;
    head1->next->next->next = createNode('d');
    head1->next->next->next->prev = head1->next->next;
    head1->next->next->next->next = createNode('e');
    head1->next->next->next->next->prev = head1->next->next->next;

    struct Node* head2 = createNode('a');
    head2->next = createNode('b');
    head2->next->prev = head2;
    head2->next->next = createNode('c');
    head2->next->next->prev = head2->next;
    head2->next->next->next = createNode('d');
    head2->next->next->next->prev = head2->next->next;
    head2->next->next->next->next = createNode('e');
    head2->next->next->next->next->prev = head2->next->next->next;
    head2->next->next->next->next->next = createNode('f');
    head2->next->next->next->next->next->prev = head2->next->next->next->next;
    head2->next->next->next->next->next->next = createNode('g');
    head2->next->next->next->next->next->next->prev = head2->next->next->next->next->next;
    head2->next->next->next->next->next->next->next = createNode('h');
    head2->next->next->next->next->next->next->next->prev = head2->next->next->next->next->next->next;

    printf("Input (N=2):\n");
    printDoublyLinkedList(head1);

    struct Node* rotatedHead1 = rotateDoublyLinkedList(head1, 2);

    printf("\nOutput:\n");
    printDoublyLinkedList(rotatedHead1);

    printf("\nInput (N=4):\n");
    printDoublyLinkedList(head2);

    struct Node* rotatedHead2 = rotateDoublyLinkedList(head2, 4);

    printf("\nOutput:\n");
    printDoublyLinkedList(rotatedHead2);

    return 0;
}

//3. Sort Elements of a Queue in Ascending Order

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1; 
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

void sortQueue(struct Queue* queue) {
    int size = 0;
    struct Node* current = queue->front;

    
    while (current != NULL) {
        size++;
        current = current->next;
    }


    for (int i = 0; i < size - 1; i++) {
        struct Node* minNode = queue->front;
        struct Node* prevMin = NULL;
        struct Node* current = queue->front->next;

        
        while (current != NULL) {
            if (current->data < minNode->data) {
                minNode = current;
                prevMin = prevMin;
            }
            prevMin = current;
            current = current->next;
        }

        
        if (minNode != queue->front) {
            prevMin->next = minNode->next;
            minNode->next = queue->front;
            queue->front = minNode;
            if (prevMin->next == NULL) {
                queue->rear = prevMin;
            }
        }
    }
}

void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 4);
    enqueue(queue, 2);
    enqueue(queue, 7);
    enqueue(queue, 5);
    enqueue(queue, 1);

    printf("Input:\n");
    printQueue(queue);

    sortQueue(queue);

    printf("\nOutput:\n");
    printQueue(queue);

    return 0;
}

//4. Queue Function Operations in C
enqueue(Q, item)
dequeue(Q)
front(Q)
isEmpty(Q)
isFull(Q)


//5. Reverse a String using Stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char* array;
    int top;
    unsigned capacity;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isStackEmpty(stack))
        return '\0'; 
    return stack->array[stack->top--];
}

void reverseString(char* input) {
    int length = strlen(input);
    struct Stack* stack = createStack(length);

   
    for (int i = 0; i < length; i++) {
        push(stack, input[i]);
    }

    
    for (int i = 0; i < length; i++) {
        input[i] = pop(stack);
    }
}

int main() {
    char input[] = "LetsLearn";

    printf("Input (string): %s\n", input);

    reverseString(input);

    printf("Output (string): %s\n", input);

    return 0;
}

//6. Insert Value in Sorted Way in a Sorted Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
               *head = newNode;
    } else if (value < (*head)->data) {
        
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
       
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }

       
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    
    insertSorted(&head, 2);
    insertSorted(&head, 4);
    insertSorted(&head, 6);
    insertSorted(&head, 8);

    printf("Initial doubly linked list:\n");
    printList(head);

    
    insertSorted(&head, 9);

    printf("\nDoubly Linked List after insertion of 9:\n");
    printList(head);

    return 0;
}
