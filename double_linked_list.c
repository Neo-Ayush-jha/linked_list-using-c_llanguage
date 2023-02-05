//documentation section--------------------------------------->
/* PROGRAM FOR DOUBLE LINKED LIST */
//link section------------------------------------------------>
#include<stdio.h>
#include<stdlib.h>
//global declearation section--------------------------------->
typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;
typedef struct link_list{
	struct node *head;
}link_list;
//definition section------------------------------------------>
node *new_node(int data);
link_list *new_link_list(int data);
void show(link_list *l);
void insert_frount(link_list *l, node *n);
void insert_after(node *n,node *a);
void del(link_list *l,node *n);

int main(){
	link_list *l= new_link_list(10);
	
	node *a,*b,*c;
	
	a=new_node(20);
	b=new_node(30);
	c=new_node(40);
	
	l->head->next=a;
	a->next=b;
	b->next=c;
	
	node *z;
	
	z=new_node(9);
	insert_frount(l,z);
	show(l);
	
	z=new_node(99);
	insert_end(l,z);
	show(l);
	
	z=new_node(999);
	insert_after(z,a);
	show(l);
		
	del(l,b);
	show(l);
}
//SUBPROGRAM SECTION--------------------------------------------->
node *new_node(int data){
	node *z;
	z=malloc(sizeof(struct node));
	z->data=data;
	z->next=NULL;
	return z;
}

link_list *new_link_list(int data){
	node *a;
	a=new_node(data);
	link_list *l = malloc(sizeof(link_list));
	l->head=a;
	return l;	
}

void show(link_list *l){
	node *temp =l->head;
	while(temp !=NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}	
	printf("\n");
}

void insert_frount(link_list *l, node *n){
	n->next= l->head;
	l->head->prev =n;
	l->head=n;
}

void insert_end(link_list *l,node *n){
	node *temp = l->head;
	while(temp->next!= NULL){
		temp = temp->next;
	}
	temp->next=n;
	n->prev=temp;
}

void insert_after(node *n,node *a){
	n->next = a->next;
	a->next->prev=n;
	a->next=n;
	n->prev=a;
}

void del(link_list *l,node *n){
	if(n->prev!=NULL){
		n->prev->next=n->next;
	}
	else if(n->next!=NULL){
		n->next->prev =n->prev;
	}
	else{
		l->head=n->next;
	}
}
