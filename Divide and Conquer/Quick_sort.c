#include<stdio.h>

int partition(int a[], int first, int last){
    int pivot = a[last];
    int i = first -1;

    for(int j=first;j < last;j++){
        if(a[j] < pivot){
            i++;
            int temp = a[i];
            a[i]     = a[j];
            a[j]     = temp;
        }
    }
    i++;
    int temp = a[i];
    a[i]     = a[last];
    a[last]  = temp;
    
    return i;
}

void quickSort(int a[], int first, int last){
    if(first < last){
        int pivot_idx = partition(a, first, last);

        quickSort(a,first, pivot_idx -1);
        quickSort(a,pivot_idx+1, last);
    }
}

void printArray(int a[], int n){
    for(int pos = 0; pos < n; pos++){
        if(pos < n-1)
        printf("%d , ", a[pos]);

        else
        printf("%d ", a[pos]);
    }
    printf("\n");
}
int main(){
    int n, output;
    printf("Enter the range of the array :\t");
    scanf("%d", &n);

    printf("Enter elements in the array :\n");
    printf("=============================\n");
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d : \t", (i+1));
        scanf("%d", &a[i]);
    }
    printf("\nOriginal Array         :");
    printArray(a,n);
    quickSort(a,0,n-1);
    printf("Array after quick Sort :");
    printArray(a,n);
}
