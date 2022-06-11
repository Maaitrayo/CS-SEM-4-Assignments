#include<stdio.h>


void merge(int a[], int first, int mid, int last){
    int n1 = mid - first + 1;
    int n2 =  last - mid;

    // temporary arrays
    int a_1[n1];
    int a_2[n2];

    for(int i=0; i<n1; i++){
        a_1[i] = a[first+i];
    }

    for(int i=0; i<n1; i++){
        a_2[i] = a[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = first;

    while(i < n1 && j <n2){
        if(a_1[i] < a_2[j]){
            a[k] = a_1[i];
            i++;
            k++;
        }
        else{
            a[k] = a_2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        a[k] = a_1[i];
        i++;
        k++;
    }

    while(j<n2){
        a[k] = a_2[j];
        j++;
        k++;
    }

}

void mergeSort(int a[], int first, int last){
    if(first < last){
        int mid = (first + last)/2;

        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);

        merge(a, first, mid, last);
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
    printf("\nOriginal Array         :\n");
    printf("=============================\n");
    printArray(a,n);

    mergeSort(a,0,n-1);

    printf("\nArray after quick Sort :\n");
    printf("=============================\n");
    printArray(a,n);
}
