#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct vector
{
    int* head;
    int size;
    int capacity;
};


void resize(struct vector*, int);

struct vector new_vector(int capacity){
    int* arr = malloc(capacity*sizeof(int));
    struct vector v;
    v.head = arr;
    v.size = 0;
    v.capacity = capacity;
    return v;
}

void free_vector(struct vector *v){
    free(v->head);
    v->head = NULL;
}

int is_empty(struct vector v){
    return v.size == 0;
}

int size(struct vector v){
    return v.size;
}

int capacity(struct vector v){
    return v.capacity;
}

int at(struct vector v, int n){
    if(n<v.size){
        return *(v.head+n);
    }
}

int push(struct vector *v, int x){
    if(v->size == v->capacity){
        resize(v, 2*v->size);
    }
    *(v->head+v->size) = x;
    v->size++;
}

void insert(struct vector *v, int idx, int value){
    if(v->size == v->capacity){
        resize(v, 2*v->size);
    }
    v->size++;
    for(int i=v->size; i>=idx; i--){
        *((v->head)+i+1) = *(v->head+i);
    }
    *(v->head+idx) = value;
    return;
}

void prepend(struct vector *v, int value){
    if(v->size == v->capacity){
        resize(v, 2*v->size);
    }
    v->size++;
    for(int i=v->size; i>=0; i--){
        *(v->head+i+1) = *(v->head+i);
    }
    *(v->head) = value;
}

int pop(struct vector *v){
    v->size--;
    if(v->size < (v->capacity/4)){
        resize(v, v->size/2);
    }
    return *(v->head+v->size);
}

void delete(struct vector *v, int index){
    for(int i=index; i<v->size; i++){
        *(v->head+i) = *(v->head+i+1);
    }
    v->size--;
    if(v->size < (v->capacity/4)){
        resize(v, v->size/2);
    }
}

int found(struct vector *v, int item){
    for (int i = 0; i < v->size; i++){
        if(*(v->head+i)==item)
        return i;
    }
    return -1;
}

void remove_vector(struct vector *v, int item){
    for (int i = 0; i < v->size; i++){
        if(*(v->head+i)==item){
            delete(v, i);
        }
    }
}

void print_vector(struct vector v){
    printf("sz: %d [", v.size);
    for(int i=0; i<v.size; i++){
        printf("%d, ", *(v.head+i));
    }
    printf("]\n");
}

void resize(struct vector *v, int capacity){
    int* new_head = malloc(capacity*sizeof(int));
    int min =  v->size < capacity ? v->size : capacity;
    for(int i=0; i<min; i++){
        *(new_head+i) = *(v->head+i);
    }
    free(v->head);
    v->head = new_head;
    v->size = min;
}

int main(){
    struct vector v = new_vector(16);
    printf("head: %p, size: %d capacity: %d\n", v.head, size(v), capacity(v));
    for(int i=0; i<5;i++){
        push(&v, i);
    }
    print_vector(v);
    insert(&v, 3, 100);
    print_vector(v);
    prepend(&v, 123);
    print_vector(v);
    printf("pop: %d\n", pop(&v));
    print_vector(v);
    delete(&v, 2);
    print_vector(v);
    for(int i=0; i<5; i++){
        prepend(&v, i);
    }
    print_vector(v);
    remove_vector(&v, 0);
    print_vector(v);
    printf("1=%d\n", found(&v, 1));
    printf("99=%d\n", found(&v, 99));
    resize(&v, 2);
    print_vector(v);
    free_vector(&v);
}