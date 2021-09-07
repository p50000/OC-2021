#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void init_node(int data, struct node **node) 
{
	(*node) = malloc(sizeof(struct node));
	(*node)->data = data;
	(*node)->next = NULL;
}

void print_list(struct node *head) 
{
	struct node* current = head->next;
	printf("Printing list of size %d \n", head->data);
	while(current) 
	{
		printf("%d \n", current->data);
		current = current->next;
	}
}

void insert_node(struct node *head, struct node *newnode, struct node *prevnode) 
{
	head->data++;
	struct node* tmp = prevnode->next;
	prevnode->next = newnode;
	newnode->next = tmp;
}

void delete_node(struct node *head, struct node *delnode)
{
	struct node* prev = head;
	struct node* current = head->next;
	while(current && current->data != delnode->data) 
	{
		prev = current;
		current = current->next;
	}
	if(current) 
	{
		struct node *next = current->next;
		free(prev->next);
		prev->next = next;

		head->data--;
	}
}

int main() {
	struct node *head, *first, *second, *third, *fourth;
	init_node(0, &head);
	init_node(1, &first);
	init_node(2, &second);
	init_node(3, &third);
	init_node(4, &fourth);

	print_list(head);

	printf("Insert node1 into empty list\n");
	insert_node(head, first, head);
	printf("Insert node3 after node1\n");
	insert_node(head, third, first);

	print_list(head);

	printf("Insert node2 after node1\n");
	insert_node(head, second, first);

	print_list(head);
	printf("Delete node2\n");
	delete_node(head, second);

	print_list(head);
	printf("Insert node4 after node3\n");
	insert_node(head, fourth, third);

	print_list(head);
}