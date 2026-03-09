#include <stdio.h> 
#include <assert.h> 
#include <string.h>
// char* my_strcpy(char* dststr , const char* srcstr){
//     char* ret = dststr; 
//     assert(dststr != NULL);
//     assert(srcstr != NULL);

//     while( *dststr++ = *srcstr++ )

//     return ret;
// }


// size_t my_strlen(const char *str){
//     size_t count = 0;
//     while(*str++){
//         count++;
//     }
//     return count;
// }


char* my_strncpy(char *dest,const char *src,size_t n){

    char* ret = dest ;
    assert(dest != NULL);
    assert(src != NULL);
    while(n>0&& *src != '\0'){
        *dest++ = *src++ ;
        n--;
    }
    while(n>0){
        *dest++ = '\0';
        n--;
    }

    return ret;
}


//不确定的类型，用void
// void* my_memcpy(void* dest, const void*src, size_t count){

//     void* ret = dest;
//     assert(dest != NULL);
//     assert(src != NULL);
//     char* d = (char*)dest;
//     const char* s = (const char*)src;
//     while(count--){
//         *d++ = *s++;
//     }
//     return ret;
// }


//
void reverse(void* arr,size_t elem_size, size_t arr_len){

    assert(arr !=NULL);
    char* left = (char*)arr;
    char* right = ((char*)arr +(arr_len-1)*elem_size);


    while (left < right)
    {
        for(int i = 0; i < elem_size ;i ++){
            char temp;
            temp = *(left+i);
            *(left+i) = *(right+i) ;
            *(right+i) = temp ;
        }
        if( left < right)
        {       
            left += elem_size ;
            right -= elem_size ;
        } 
    }
    
}
int main()
{
    char a[10] = "hello";
    char b[10];

    memcpy(b,a,10);

    printf("%s\n",b);

    return 0 ;
}