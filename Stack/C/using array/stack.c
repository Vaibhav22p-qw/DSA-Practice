#include <stdio.h>
#define size 5
int stack[size];
int top=-1;

void push(int n){
    if(top==size-1){
        printf("Oops! Unable to PUSH.");
    }
    else{
        stack[++top]=n;
    }
}
 
void pop() {
    if (top == -1) {
        printf("Oops! Stack is empty, unable to POP.\n");
    } else {
        top--;
    }
}
 void print(){
    if(top==-1){
		printf("Empty\n");
		return;
	}
	for(int i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	}
 }
 
 void menu(){
     printf("1.PUSH\n");
     printf("2. POP\n");
     printf("3. Exit\n");
 }
 
int main()
{
    menu();
    int choice, value;
	do{
		printf(">>> ");
		scanf("%d",&choice);
		switch (choice){
			case 1: printf("Enter Value : ");
					scanf("%d",&value);
					push(value);
					print();
					break;
			case 2: pop(); 
			        print();
			        break;
		}
	}while (choice !=3);
	printf("\n| Final List |\n");
	print();
    return 0;
}
