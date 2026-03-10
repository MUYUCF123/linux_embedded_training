#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int* p = malloc(10*sizeof(int));
//     for(int i= 0; i<10; i++){
//         *(p+i) = i;
//         printf("%d\n",*(p+i));
//     }

//     free(p);
//     for(int i= 0; i<20; i++){
//         printf("%d\n",*(p+i));
//     }

void *my_calloc(size_t num, size_t size){

    void* p = malloc(size*num);
    if (p == NULL)
    {
        return NULL;
    }
    void * ret = p;
    for(int i = 0 ; i<size*num ; i++){
        unsigned char* p1 = (unsigned char*)p;
        *p1++ = 0;
    }
    return ret;
}

char *my_strdup(const char *src){

    
    char* p = malloc(strlen(src));
    if (p == NULL)
    {
        return NULL;
    }
    char*ret = p;
    for(int i = 0; i<=strlen(src); i++){
        *(p+i) = *(src+i);
    }
    return ret;
}

void my_swap(void *a, void *b, size_t size){
    
    if (a == NULL || b == NULL || size == 0)
    {
        return;
    }
    unsigned char *p1 = a;
    unsigned char *p2 = b;

    for (size_t i = 0; i < size; i++)
    {
        unsigned char tmp = p1[i];
        p1[i] = p2[i];
        p2[i] = tmp;
    }

}


void reverse(void *arr, size_t count, size_t size){
    char* left = (char*)arr;
    char* right = (char*)arr + (count-1)*size;

    while(left < right){
        my_swap(left, right, size);
        if(left < right){
            left += size;
            right -= size;
        }
    }
}
int main(){
    int*p = my_calloc(10, sizeof(int));
    for(int i= 0; i<10; i++){
        printf("%d\n",*(p+i));
    }

    int a = 10, b = 5;
    my_swap(&a, &b, sizeof(int));
    printf("a = %d, b = %d\n", a, b);

    char* str1 = "hello";
    char* str2 = "world";
    my_swap(&str1, &str2, sizeof(char*));
    printf("str1 = %s, str2 = %s\n", str1, str2);
    printf("%s",my_strdup("hello"));
    return 0;
}