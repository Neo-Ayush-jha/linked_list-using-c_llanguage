#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
typedef struct linked_list{
	struct node *head;
}linked_list;

node* new_node(int data){
	node *z;
	z= malloc(sizeof(struct node));
	z->data=data;
	z->next=NULL;
	return z;
}
linked_list *new_linked_list(int data){
	node *a;
	a= new_node(data);
	linked_list *l=malloc(sizeof(linked_list));
	l->head=a;
	return l;
}
//show linked list
	void traversal(linked_list *l){
		node *temp = l->head;
		int i=0;
		while(temp != NULL){
			printf("%d\t %d\n",temp->data,i);
			i++;
			temp = temp->next;
		}
		printf("\n");
	}
//add extra node
	void insert_at_beginning(linked_list *l,node *n){
		n->next=l->head;
		l->head=n;
	}
	void insert_at_end(linked_list *l, node *n){
		node *temp = l->head;
		while(temp -> next != NULL){
			temp = temp->next;
		}
		temp->next= n;
	}
	void insert_at_after(node *n,node *a){
		n->next=a->next;
		a->next=n;
	}
//delete node
	void del(linked_list *l,node *n){
		node *temp=l->head;
		if(temp ==n){
			l->head=n->next;
			free(n);
		}else{
			while(temp != NULL){
				if(temp->next==n){
					temp->next=n->next;
					free(n);
					break;
				}
				temp = temp->next;
			}
		}
	}

int main(){
	linked_list *l=new_linked_list(10);
	node *a,*b,*c;
	a=new_node(20);
	b=new_node(30);
	c= new_node(40);
	l->head->next=a;
	a->next=b;
	b->next= c;
	
	node *z;
//	inserting from starting side
	z=new_node(60);
	insert_at_beginning(l,z);
//	inserting from end side
	z=new_node(88);
	insert_at_end(l,z);
	
	z=new_node(55);
	insert_at_end(l,z);
//	inserting from any where 
	z= new_node(-55);
	insert_at_after(z,c->next->next);
	printf("\n-----------------first calling =>\n");
	traversal(l);
	del(l,l->head);
	printf("\n-----------------after delete calling =>\n");
	traversal(l);
	del(l,z);
	printf("\n-----------------after 2 delete calling =>\n");
	traversal(l);
}
