#include <stdio.h>

void main(){
    int arr[100] = {0};
    for(int i=0; i<100; i++)
        arr[i] = i;
    int* ptr = arr;
    printf("pointer: %p %p value: %d", ptr, arr, *arr);
    ptr++;
    printf("pointer: %p value: %d %d\n", ptr, *ptr, arr[1]);
    ptr = ptr + 98;
    printf("pointer: %p value: %d %d\n", ptr, *ptr, arr[99]);
    return;
}