#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *head = NULL;
int arr[100] = {0};
/* Insert new node to start of the list */
void insert_node_front(int data) {
	struct list *ptr = (struct list *) malloc(sizeof(struct list));
	ptr->data = data;
	ptr->next = NULL;

	if(head == NULL) {
		head = ptr;
	} else {
		ptr->next = head;
		head = ptr;	
	}
}

void insert_node_last(int data){
	struct list *ptr = (struct list *) malloc(sizeof(struct list));
	struct list *tmp;
	ptr->next = NULL;
	ptr->data = data;

	if(head == NULL) {
		head = ptr;
	} else {
		tmp = head;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = ptr;
	}
}

/* Delete a node from the list */
void delete_node(int data) {
	struct list* ptr, *prev;
	ptr = head;
	if(head->data == data) {
		head = head->next;
		free(ptr);
		printf("Node with data=%d deleted\n", data);
		return;
	}
	while(ptr != NULL) {
		if(ptr->data == data) {
			prev->next = ptr->next;
			free(ptr);
			printf("Node with data=%d deleted\n", data);
			return;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	printf("Node with data=%d not found\n", data);
}

/* Delete duplicate nodes in a list
 * This solution has complexity O(n * n)
 */

void delete_duplicates(void) {
	struct list *ptr1, *ptr2, *prev;
	ptr1 = head;

	while(ptr1->next != NULL) {
		prev = ptr1;
		ptr2 = ptr1->next;
		while(ptr2 != NULL) {
			if(ptr1->data == ptr2->data) {
				prev->next = ptr2->next;
				free(ptr2);
				ptr2 = prev->next;
				printf("dup found data=%d!!\n",ptr1->data);
				continue;
			}
			prev = ptr2;
			if(ptr2 != NULL) {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

/* Delete duplicate nodes in a list
 * This solution uses hashmap and has complexity O(n)
 */

void delete_duplicates2(void) {
	struct list *ptr1 = head;
	struct list *prev = ptr1;

	while(ptr1 != NULL) {
		printf("ptr1->data = %d\n", ptr1->data);
		printf("prev->data = %d\n", prev->data);
		if(arr[ptr1->data] == 0) {
			arr[ptr1->data] = 1;
		} else {
			printf("dup found data=%d!!\n",ptr1->data);
			prev->next = ptr1->next;
			free(ptr1);
			ptr1 = prev->next;
			continue;
		}
		prev = ptr1;
		if(ptr1 != NULL) {
			ptr1 = ptr1->next;
		}
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

	/*
	//check loop detection without a loop int the list 
	detect_loop();
	// create a loop in the linked list and detect this loop 
	printf("Inserting a loop in list\n");
	insert_loop();
	detect_loop();
	*/
	
	// Delete node
	delete_node(20);
	delete_node(40);
	delete_node(100);
	print_list();

        // Insert duplicate nodes for duplicate detection and deletion
	
	insert_node_front(10);
	insert_node_front(20);
	insert_node_last(10);
	insert_node_last(20);
	print_list();
	
	// Delete duplicates int the list
	delete_duplicates();
	print_list();
	

        // Insert duplicate nodes for duplicate detection and deletion
	
	insert_node_front(30);
	insert_node_front(80);
	insert_node_last(30);
	insert_node_last(80);
	print_list();
	// Delete duplicates int the list
	delete_duplicates2();
	print_list();
}
