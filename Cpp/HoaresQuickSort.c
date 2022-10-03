#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void display(int arr[], int size){
    printf("Array: ");
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start, j = end;
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[start]);
    return j;
}

void quicksort(int arr[], int start, int end){
    if(start<end){
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot);
        quicksort(arr, pivot+1, end);
    }
}

void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements in the array: ");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);
    display(arr, size);
    quicksort(arr, 0, size);
    display(arr, size);
}