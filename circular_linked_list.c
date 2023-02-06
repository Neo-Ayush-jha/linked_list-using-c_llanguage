//documentation section--------------------------------------->
/* PROGRAM FOR CIRCLULAR LINKED LIST */
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
void insert_after(node *l, node *n);
void del(link_list *l,node *n);

//main function------------------------------------------------>
int main(){
	link_list *l= new_link_list(10);
	
	node *a,*b,*c,*d;
	
	a=new_node(20);
	b=new_node(30);
	c=new_node(40);
	d=new_node(50);
	l->head->next=a;
	a->next=b;
	b->next=c;
	c->next=d;
	show(l);
	
	node *z;
	
	z=new_node(9);
	insert_after(a,z);
	show(l);
	
	z=new_node(99);
	insert_end(l,z);
	show(l);
		
	del(l,c);
	show(l);
}


//SUBPROGRAM SECTION--------------------------------------------->
node *new_node(int data){
	node *z;
	z=malloc(sizeof(struct node));
	z->data=data;
	z->next=z;
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
		int i=1;
	do{
	
		printf("%d=%d\t",i,temp->data);
		temp = temp->next;
		i++;
	}while(temp->next !=temp);
	printf("complet \n");
}

void insert_after(node *l,node *n){
	n->next=l->next;
	l->next=n;
	n->prev=l;
	l->prev=NULL;
}

void insert_end(link_list *l,node *n){
	
	n->next=l->head->next;
	l->head->next=n;
	l->head=n; 
}

void del(link_list *l, node *n){
	node *temp =l->head;
	while(temp->next!=n){
		temp=temp->next;
	}
	if(n==l->head){
		if(n==l->head->next){
			l->head=NULL;
		}
		else{
			temp->next=n->next;
			l->head=temp;
		}
	}
	else{
		temp->next=n->next;
	}
}
