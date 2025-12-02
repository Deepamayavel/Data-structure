#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node* getnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return newnode;
}
void insertatbegin() {
    int elt;
    printf("Enter value: ");
    scanf("%d", &elt);

    struct node* newnode = getnode(elt);

    if (head == NULL) {
        newnode->next = newnode->prev = newnode;
        head = newnode;
        return;
    }

    struct node* last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}
void insertatend() {
    int elt;
    printf("Enter value: ");
    scanf("%d", &elt);

    struct node* newnode = getnode(elt);

    if (head == NULL) {
        newnode->next = newnode->prev = newnode;
        head = newnode;
        return;
    }

    struct node* last = head->prev;

    last->next = newnode;
    newnode->prev = last;
    newnode->next = head;
    head->prev = newnode;
}
void insertatpos() {
    int pos, elt;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &elt);

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertatbegin();
        return;
    }

    struct node* newnode = getnode(elt);
    struct node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count < pos - 1) {
        insertatend();
        return;
    }

    struct node* nextnode = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = nextnode;
    nextnode->prev = newnode;

    printf("%d inserted at position %d\n", elt, pos);
}
void deleteatbegin() {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }
    struct node* temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }

    struct node* last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
}
void deleteatend() {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }
    struct node* last = head->prev;

    if (head->next == head) {
        head = NULL;
        free(last);
        return;
    }
    struct node* second_last = last->prev;
    second_last->next = head;
    head->prev = second_last;
    free(last);
}
void deleteatpos() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos <= 0 || head == NULL) {
        printf("Invalid position or list empty!\n");
        return;
    }
    if (pos == 1) {
        deleteatbegin();
        return;
    }
    struct node* temp = head;
    int count = 1;

    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->next == head) {
        deleteatend();
        return;
    }

    struct node* prevnode = temp->prev;
    struct node* nextnode = temp->next;

    prevnode->next = nextnode;
    nextnode->prev = prevnode;

    free(temp);

    printf("Node deleted at position %d\n", pos);
}
void traversal() {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }

    struct node* temp = head;

    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertatbegin(); break;
            case 2: insertatend(); break;
            case 3: insertatpos(); break;
            case 4: deleteatbegin(); break;
            case 5: deleteatend(); break;
            case 6: deleteatpos(); break;
            case 7: traversal(); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
