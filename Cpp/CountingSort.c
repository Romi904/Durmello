#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void display(int arr[], int n){
    printf("Array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void countingsort(int arr[], int n){ // for elements ranging in [0, n]
    int freq[n+1], sorted[n];
    for(int i=0; i<=n; i++)
        freq[i]=0;
    for(int i=0; i<n; i++)
        freq[arr[i]]++;
    for(int i=1; i<=n; i++)
        freq[i] += freq[i-1];
    for(int i=0; i<=n; i++)
        freq[i]--;
    for(int i=n-1; i>=0; i--)
        sorted[freq[arr[i]]--] = arr[i];
    for(int i=0; i<n; i++)
        arr[i] = sorted[i];
}

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    display(arr, n);
    countingsort(arr, n);
    display(arr, n);
}