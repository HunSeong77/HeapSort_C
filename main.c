#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -2147483647
#define MAXHEAP 1
#define MINHEAP 0

typedef int element;

void swap(element*, element*);
void buildHeap(element* arr, int type);
void heapify(element* arr, int target, int type);
element extract(element* arr, int type);
void heapSort(element* arr, int type);

void swap(element* x, element* y)
{
    element z = *x;
    *x = *y;
    *y = z;
}

void buildHeap(element* arr, int type)
{
    for(int i = arr[0] / 2; i >= 0; i--)
        heapify(arr, i, type);
}

void heapify(element* arr,  int target, int type)
{
    int size = arr[0];
    int leftChild = target * 2;
    int rightChild = leftChild + 1;
    int optChild = target;
    if(leftChild > size){
    }
    else if(rightChild > size){
        optChild = leftChild;
    }
    else{
        if(type == MAXHEAP)
            optChild = arr[leftChild] > arr[rightChild] ? leftChild : rightChild;
        else
            optChild = arr[leftChild] < arr[rightChild] ? leftChild : rightChild;
    }
    if(type == MAXHEAP){
        if(arr[optChild] > arr[target]){
            swap(&arr[target], &arr[optChild]);
            heapify(arr, optChild, type);
        }
    }
    else{
        if(arr[optChild] < arr[target]){
            swap(&arr[target], &arr[optChild]);
            heapify(arr, optChild, type);
        }
    }
}

element extract(element* arr, int type)
{
    int size = arr[0];
    if(size == 0){
        printf("Heap is Empty.\n");
        return;
    }

    arr[0]--;
    swap(&arr[1], &arr[size]);
    heapify(arr, 1, type);

    return arr[size];
}

void heapSort(element* arr, int type)
{
    buildHeap(arr, type);
    while(arr[0] != 0){
        extract(arr, type);
    }
}

int printCommands()
{
    printf("1. Insert Data\n");
    printf("2. Print Current Data\n");
    printf("3. Sort Current Data in Increasing Order\n");
    printf("4. Sort Current Data in Decreasing Order\n");
    printf("5. Clear\n");
    printf("6. Quit\n");
    int ret;
    scanf_s("%d ", &ret);
    return ret;
}

void InsertData(element* arr){
    int N;
    
    printf("Enter the size of Input : ");
    scanf_s("%d ", &N);

    for(int i = 1; i <= N; ++i){
        scanf_s("%d ", &arr[arr[0] + i]);
    }
    arr[0] += N;
}

void PrintData(element* arr){
    for(int i = 1; i <= arr[0]; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void){

    int command = 0;
    element arr[1000];
    arr[0] = 0;
    while(command != 6){
        command = printCommands();
        switch(command){
            case 1 : InsertData(arr);       break;
            case 2 : PrintData(arr);        break;
            case 3 : heapSort(arr, MAXHEAP); break;
            case 4 : heapSort(arr, MINHEAP); break;
            case 5 : arr[0] = 0;            break;
        }
    }
}