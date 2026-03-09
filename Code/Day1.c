#include<stdio.h>




int main (void)
{
    int m = 10;
    char n = 'A';
    char * i  = &n ;
    printf("int %d\nchar %d\nchar* %d\n ", sizeof(m), sizeof(n) ,sizeof(i));


}