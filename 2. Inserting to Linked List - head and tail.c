#include <stdio.h>
#include <stdlib.h>

// definiton of struct node
typedef struct node {
	int value; 				// anything - struct, array, etc
	struct node *next; 		//pointer to another struct node
} Node;

// prototypes of functions
void print_list (Node *head);
Node *insert_at_head (Node *head, int);
Node* insert_at_tail (Node *head, int);

int main (void) {
	
	// create empty list
	Node *list1_head = NULL;
	
	// inserting nodes at head
	list1_head = insert_at_head(list1_head, 9);
	list1_head = insert_at_head(list1_head, 16);
	list1_head = insert_at_head(list1_head, 23);
	list1_head = insert_at_head(list1_head, 28);
	
	// insert at tail
	list1_head = insert_at_tail(list1_head, 100);
	
	// prit nodes
	print_list (list1_head);
}

// insert a new node at head
Node *insert_at_head (Node *head, int new_value) {
	
	// alocate space for node
	Node *new_node = calloc (1, sizeof(Node));
	new_node->value = new_value;
	
	// is list / node empty?
	if (head == NULL) {
		return new_node;
	}
	
	// list is not empty
	else {
		// new head points to old head
		new_node->next = head;
		return new_node;
	}
}

Node* insert_at_tail (Node *head, int new_value) {
	
	// alocate space for node
	Node *new_node = calloc (1, sizeof(Node));
	new_node->value = new_value;
	
	// is list empty?
	if (head == NULL) {
		return new_node;
	}
	
	// list is not empty, insert at end, traverse list
	else {
		Node *current;
		current = head;
		
		// traverse wehre NEXT node is null
		while (current->next != NULL) {
			current = current->next;
		}
		
		// we are at the end of list, append new node
		current->next = new_node;
		return head;
	}
}

void print_list (Node *head) {
	Node *current;
	current = head;
	int i = 0;
	
	printf("\nNode values are:\n");
	while (current != NULL) {
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
