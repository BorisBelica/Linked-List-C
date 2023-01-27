#include <stdio.h>

typedef struct node {
	int value; 				// anything - struct, array, etc
	struct node *next; 		//pointer to another struct node
} Node;

void print_list (Node *head);

int main (void) {
	
	// create nodes a b c
	Node a, b, c;
	
	// value of nodes
	a.value = 5;
	b.value = 6;
	c.value = 7;
	
	// point to next node
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	
	// print values
	printf("Node a.value is: %d\n", a.value);
	printf("Node b.value is: %d\n", b.value);
	printf("Node c.value is: %d\n", c.value);
	
	//loop and print linked list, create print list function
	print_list (&a);
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
