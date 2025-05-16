#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *head = NULL;

/* Insert new node to start of the list */
void insert_node_front(int data) {
	struct list *ptr = (struct list *) malloc(sizeof(struct list));
	ptr->data = data;
	ptr->next = NULL;

	if(head == NULL) {
		head = ptr;
	} else {
		ptr->next = head->next;
		head->next = ptr;	
	}
}

/* Print all the elements in the list */
void print_list(void){
	struct list *tmp;
	tmp = head;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/* Reverse the linked list */
void reverse_list(void) {
	struct list *p, *q, *r;
	q = head;
	p = NULL;
	r = NULL;

	while(q != NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	head = p;
}

/* Insert a loop for loop detection linked list */
void insert_loop(void) {
	int i=1;
	struct list *ptr = head;
	for(i; i<5; i++){
		ptr = ptr->next;
	}
	ptr->next = head;
}

void detect_loop(void) {
	struct list *j, *k;
	j = k = head;

	while(j != NULL && k != NULL && k->next != NULL) {
		j = j->next;
		k = k->next->next;
		if(j == k) {
			printf("loop detected\n");
			return;
		}
	}
	printf("No loop detected\n");
}

int main(void) {
	struct list *p, *q, *r;
	struct list *tmp;
	int i;
	/* Create a list of 5 nodes */
	for(i=1; i<=5; i++){
		insert_node_front(i*10);
	}
	/* print list */
	print_list();
	/* reverse linked list */
	reverse_list();
	/* print list */
	print_list();

	/* check loop detection without a loop int the list */
	detect_loop();
	/* create a loop in the linked list and detect this loop */
	printf("Inserting a loop in list\n");
	insert_loop();
	detect_loop();
}
