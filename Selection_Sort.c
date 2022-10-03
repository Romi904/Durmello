#include<stdio.h>

int main(){
    int size,arr[100];
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the array elements separated with space: ");
    for(int i=0; i<size; ++i){
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<size-1; ++i){
        int min_index = i;
        for(int j=i+1; j<size; ++j){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    printf("Sorted array: ");
    for(int i=0; i<size; ++i){
        printf("%d ",arr[i]);
    }
    return 0;
}
