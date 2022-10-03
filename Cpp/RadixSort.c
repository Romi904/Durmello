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

void countingsort(int arr[], int n, int pwr){
    int freq[10], sorted[n];
    for(int i=0; i<10; i++)
        freq[i]=0;
    for(int i=0; i<n; i++)
        freq[(arr[i]/pwr)%10]++;
    for(int i=1; i<10; i++)
        freq[i] += freq[i-1];
    for(int i=0; i<10; i++)
        freq[i]--;
    for(int i=n-1; i>=0; i--)
        sorted[freq[(arr[i]/pwr)%10]--] = arr[i];
    for(int i=0; i<n; i++)
        arr[i] = sorted[i];
}

void radixsort(int arr[], int n){
    int max = arr[0];
    for(int i=0; i<n; i++)
        if(arr[i]>max)
            max = arr[i];

    for(int i=1; max/i > 0; i*=10)
        countingsort(arr, n, i);
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
    radixsort(arr, n);
    display(arr, n);
}