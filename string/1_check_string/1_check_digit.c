#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isNum(unsigned char *arr)
{
    int i = 0;
    while(arr[i])
    {
        if(isdigit(arr[i]) == false)
            return false;
        i++;
    }

    return true;
}

int main()
{
    //unsigned char arr[] = {64, 65, 33, 2};
    unsigned char arr[] = "3789";
    if(isNum(arr))
        printf("Integer");
    else
        printf("String");

    printf("\r\n");
}