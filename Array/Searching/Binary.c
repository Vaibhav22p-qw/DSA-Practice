
#include<stdio.h>

int binary(int arr[], int key, int l, int r){
	while(l<=r){
	int mid=l+(r-l)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}

int main() {
    int n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the sorted array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binary(arr, key, 0, n - 1);
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
