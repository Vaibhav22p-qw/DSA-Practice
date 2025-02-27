#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *pre;
    int value;
    struct node *next;
    
}*head=NULL, *temp, *newn;

void inst_beg(int data){
    newn=(struct node*)malloc(sizeof(struct node));
    newn->value=data;
    newn->pre=NULL;
    newn->next=head;
     if (head != NULL) {
        head->pre = newn;
    }
    head=newn;
}

void inst_end(int data){
    newn=(struct node*)malloc(sizeof(struct node));
    newn->value=data;
     if (head == NULL) {
        head = newn;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newn;
        newn->pre=temp;
    }
}

void del_beg(){
    if(head==NULL){
        printf("Oops! Unable to Delete.\n");
    }
    else{
        temp=head;
        head=head->next;
        head->pre=NULL;
        free(temp);
    }
}
void del_end(){
    if(head==NULL){
        printf("Oops! Unable to Delete.\n");
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->pre->next=NULL;
        free(temp);
    }
}

void print(){
    temp=head;
    printf("Forward : NULL <-> ");
      while (temp != NULL) {
        printf("%d <-> ", temp->value);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Backward : NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->pre;
    }
    printf("NULL\n");
}

 void menu(){
 printf("1. Insert at Begning\n");
 printf("2. Insert at End\n");
 printf("3. Delete at Begning\n");
 printf("4. Delete at End\n");
 printf("5. Exit\n");
} 
int main()
{
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
