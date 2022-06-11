#include<stdio.h>

int binarySearchIterative(int a[], int low, int up, int x){
    int mid;
    while(low <= up){
        mid = (low + up)/2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] > x){
            up = mid-1;
        }
        else{
            low = mid + 1; 
        }
    }
    return -1;
}

int main(){
    int n, x, output;
    printf("Enter the range of the array :\t");
    scanf("%d", &n);

    printf("Enter the element to search  :\t");
    scanf("%d", &x);

    printf("Enter elements in the array :\n");
    printf("=============================\n");
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d : \t", (i+1));
        scanf("%d", &a[i]);
    }
    output = binarySearchIterative(a, 0, n-1, x);
    if(output == -1){
        printf("Element not found");
    }
    else{
        printf("Element found at %d position", output+1);
    }
}