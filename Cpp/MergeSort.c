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

void merge(int arr[], int start, int mid, int end){
    int size1 = mid-start+1, size2 = end-mid;
    int temp1[size1], temp2[size2];
    for(int i=0; i<size1; i++)
        temp1[i] = arr[start+i];
    for(int i=0; i<size2; i++)
        temp2[i] = arr[mid+1+i];
    int i=0, j=0, k=0;
    while(i<size1 && j<size2){
        if(temp1[i]<temp2[j]){
            arr[start+k] = temp1[i];
            i++;
        }
        else{
            arr[start+k] = temp2[j];
            j++;
        }
        k++;
    }
    while(i<size1){
        arr[start+k] = temp1[i];
        i++, k++;
    }
    while(j<size2){
        arr[start+k] = temp2[j];
        j++, k++;
    }
}

void mergesort(int arr[], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        merge(arr, start, mid, end);
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
    mergesort(arr, 0, size);
    display(arr, size);
}