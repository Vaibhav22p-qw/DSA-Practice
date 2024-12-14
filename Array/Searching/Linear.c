#include<stdio.h>
#include<stdlib.h>


int linear(int arr[], int key, int n){
	for(int i=0;i<n;i++){
		if(key==arr[i])
			return i;
	}
	return -1;

}

int main(){
	int key, n;
	printf("Enter the size of Array : ");
	scanf("%d",&n);
	printf("Enter the key to find : ");
	scanf("%d",&key);
	int arr[n];
	for(int i=0;i<n;i++){
		printf("index %d : ",i);
		scanf("%d",&arr[i]);
	}
	
	int a=linear(arr, key ,n);
	printf("At index : %d",a);
}
