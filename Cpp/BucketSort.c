#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Node{
    float data;
    struct Node *next;
}Node;

void insert(Node **head, Node *ptr){
    if((*head)==NULL)
        (*head) = ptr;
    else if((*head)->data>ptr->data){
        ptr->next = (*head); 
        (*head) = ptr;
    }
    else{
        Node *temp = (*head);
        while(temp->next!=NULL && temp->next->data<=ptr->data)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void bucketsort(float arr[], int n){
    Node *bucket[n];
    for(int i=0; i<n; i++){
        bucket[i] = NULL;
    }
    for(int i=0; i<n; i++){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = NULL;
        int index = n*arr[i];
        insert(&bucket[index], temp);
    }
    int j=0;
    for(int i=0; i<n; i++){
        Node *temp = bucket[i];
        while(temp!=NULL){
            arr[j++] = temp->data;
            temp = temp->next;
        }
    }
}

void display(float arr[], int n){
    printf("Array: ");
    for(int i=0; i<n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++)
        scanf("%f", &arr[i]);
    display(arr, n);
    bucketsort(arr, n);
    display(arr, n);
}