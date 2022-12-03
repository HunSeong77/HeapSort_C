#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAXHEAP 1
#define MINHEAP 2

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
    for(int i = arr[0] / 2; i > 0; i--)
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
        return 0;
    }

    arr[0]--;
    swap(&arr[1], &arr[size]);
    heapify(arr, 1, type);

    return arr[size];
}

void heapSort(element* arr, int type)
{
    int size = arr[0];
    buildHeap(arr, type);
    while(arr[0] != 0){
        extract(arr, type);
    }
    arr[0] = size;
}

void PrintData(element* arr){
    if(arr[0] == 0){
        printf(" ** empty now **\n");
    }
    else{
        printf("[[ ");
        for(int i = 1; i <= arr[0]; ++i){
            printf("%d, ", arr[i]);
        }
        printf("\b ]]\n");
    }
}

int printCommands(element* arr)
{
    printf("\nCurrent Data : ");
    PrintData(arr);
    printf("\n== Enter the Commands Below ==\n");
    printf("  1. Insert Data\n");
    printf("  2. Sort Current Data in Increasing Order\n");
    printf("  3. Sort Current Data in Decreasing Order\n");
    printf("  4. Clear\n");
    printf("  5. Quit\n");
}

void InsertData(element* arr){
    int N;
    
    printf("Enter the size of Input : ");
    scanf_s("%d", &N);

    for(int i = 1; i <= N; ++i){
        scanf_s("%d", &arr[arr[0] + i]);
    }
    arr[0] += N;
}

int main(void){
    int command = 0;
    element arr[1000];
    arr[0] = 0;
    while(command != 5){
        printCommands(arr);
        printf("\nCommand : ");
        scanf_s("%d", &command);
        switch(command){
            case 1 : InsertData(arr); break;
            case 2 : heapSort(arr, MAXHEAP); break;
            case 3 : heapSort(arr, MINHEAP); break;
            case 4 : arr[0] = 0; break;
        }
        system("cls");
    }
    printf("Thank you.\n");
}
