#include<stdio.h>

int main(){
  int n;
  printf("Enter Size of Array : ");
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++){
    printf("arr[%d] : ",i);
    scanf("%d",&arr[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
   printf("Sorted Array\n");
  for(int i=0;i<n;i++){
    printf("arr[%d] : %d",i,arr[i]);
  }
  

  return 0;
}
