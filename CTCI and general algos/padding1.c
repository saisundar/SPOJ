#include <stdio.h>
struct a
{
        char t;      //1 byte+7 padding byte
        // double d;    //8 bytes
        // short s;     //2 bytes + 2 padding bytes
        // char arr[12];
        // int a[1];//12 bytes 8+8+4+12=32.
};
int main(void) 
{
        printf("%d",sizeof(struct a)); 

        printf("test %s\n",NULL );
        printf("%s\n",NULL );  
        return 0;
}