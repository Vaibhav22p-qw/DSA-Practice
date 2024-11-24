#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

node* Top;

void push(int x){
	node* new;
	new=(node*)malloc(sizeof(node));
	new->val=x;
	new->next=Top;
	Top=new;
}

void traverse(){
	if(Top==NULL){
		printf("Empty\n");
		return;
	}
	node* temp=Top;
	while(temp!=NULL){
		printf("%d->",temp->val);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main(){
	int choice, value;
	while(1){
		printf("				1.Insert\n				2.display\n				3.Exit\n				>>>");
		scanf("%d",&choice);
		switch (choice){
			case 1: printf("Enter the Value : ");
					scanf("%d",&value);
					push(value); break;
			case 2: traverse(); break;
			case 3: exit(0);
		}
	}
	
	return 0;
}
