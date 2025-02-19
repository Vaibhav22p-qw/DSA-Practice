#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node* create(node *head, int value){
    node* p;
    p=(node*)malloc(sizeof(node));
    p->val=value;
    p->next=head;
    return p;
}
node *end(node *head, int value){
    node*p,*temp;
    p=(node*)malloc(sizeof(node));
    p->val=value;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
        temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
}

void print(node* head){
    node* t;
        t=head;
    while(t!=NULL){
        printf("%d -> ",t->val);
        t=t->next;
    }
    
    printf("NULL\n");
}

 void menu(){
 printf("1. Insert at Begning\n");
 printf("2. Insert at End\n");
 printf("3. Exit\n");
} 

int main(){
    int n;
    node* head =NULL;
    menu();
    int ch;
     do {
        printf("=> ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
            printf("Enter Value : ");
                 scanf("%d",&n);
                head=create(head, n);
                print(head);
                break;
            case 2:
            printf("Enter Value : ");
                 scanf("%d",&n);
                end(head, n);
                print(head);
                break;  
        }
    } while (ch !=3);
printf("\n|Final List|\n");
    
print(head);
    return 0;
}
