/* Example code for Software Systems at Olin College.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(Node **head) {
    int retval;
    Node *next_node;
    

    if (head == NULL) {
        return -1;
    }

    Node *first = *head;

    next_node = first->next;
    retval = first->val;
    free(first);
    *head = next_node; //different behavior here

    return retval;
}

// Add a new element to the beginning of the list.
void push(Node **head, int val) {
    Node *first = make_node(val, *head);
    *head = first;
}

// Remove the first element with the given value; return the number
// of nodes removed.
int remove_by_value(Node **head, int val) {
    Node *prev = NULL;
    Node *curr = *head;
    int count = 0;

    if (curr == NULL) {
        return 0;
    }
    while (curr != NULL){
        if (curr->val == val){
            if (curr->next != NULL){
                prev->next = curr->next;
                prev = curr;
                curr = curr->next;
                count++;
            }
            else {
                prev->next = NULL;
                count++;
                break;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return count;
}

// Reverse the elements of the list without allocating new nodes.
void reverse(Node **head) {
    Node *last = NULL;
    Node *curr = *head;

    while (curr != NULL){
        Node *next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }

    *head = last;
}

int main() {
    Node *test_list = make_node(1, NULL);
    test_list->next = make_node(2, NULL);
    test_list->next->next = make_node(3, NULL);
    test_list->next->next->next = make_node(4, NULL);
    test_list->next->next->next->next = make_node(3, NULL);

    int retval = pop(&test_list);
    push(&test_list, retval+10);

    int total = remove_by_value(&test_list, 3);
    printf("nodes removed: %d\n\n",total);
    remove_by_value(&test_list, 7);

    reverse(&test_list);

    print_list(test_list);
}
