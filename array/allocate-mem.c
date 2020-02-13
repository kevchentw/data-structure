#include <stdlib.h>
#include <stdio.h>

void int_type(){
    int size = 16;
    int* arr = malloc(size*sizeof(int));
    int* ptr = arr;
    for(int i=0; i<size; i++){
        *arr = i;
        arr++;
    }
    for(int i=0; i<size; i++){
        printf("%p %d\n", ptr, *ptr);
        ptr++;
    }
}

void char_type(){
    int size = 16;
    char* arr = malloc(size*sizeof(char));
    char* ptr = arr;
    for(int i=0; i<size; i++){
        *arr = 'a'+i;
        arr++;
    }
    for(int i=0; i<size; i++){
        printf("%p %c\n", ptr, *ptr);
        ptr++;
    }
}

int main(){
    int_type();
    char_type();
    return 0;
}