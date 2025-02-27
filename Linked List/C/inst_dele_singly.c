#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*newn;

void inst_beg(int val){
    newn=(struct node*)malloc(sizeof(struct node));
    newn->data=val;
    newn->next=head;
    head=newn;
    
}

void inst_end(int val){
    newn=(struct node*)malloc(sizeof(struct node));
    newn->data=val;
    newn->next=NULL;
    if(head==NULL){
        head=newn;
        return;
}
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;
}

void del_beg(){
    if(head==NULL){
        printf("\nOops! Unable to Delete.\n");
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
    }
}
void del_end(){
    if(head==NULL){
        printf("\nOops! Unable to Delete.\n");
    }
    else{
        if(head->next==NULL){
            temp=head;
            head=NULL;
            free(temp);
        }
        else{
            temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            struct node *t=temp->next;
            temp->next=NULL;
            free(t);
        }
    }
}

void print(){
    struct node* t;
        t=head;
    while(t!=NULL){
        printf("%d -> ",t->data);
        t=t->next;
    }
    
    printf("NULL\n");
}

 void menu(){
 printf("1. Insert at Begning\n");
 printf("2. Insert at End\n");
 printf("3. Delete at Begning\n");
 printf("4. Delete at End");
 printf("5. Exit\n");
} 

int main(){
    int n;
     menu();
    int ch;
     do {
        printf("=> ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
            printf("Enter Value : ");
                 scanf("%d",&n);
                 inst_beg(n);
                print();
                break;
            case 2:
            printf("Enter Value : ");
                 scanf("%d",&n);
                inst_end(n);
                print();
                break; 
             case 3:
                del_beg();
                print();
                break; 
             case 4:
                del_end();
                print();
                break;     
        }
    } while (ch !=5);
printf("\n|Final List|\n");
    
print(head);
    return 0;
}
