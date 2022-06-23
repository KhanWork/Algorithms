#include <stdio.h>
#include <stdbool.h>

unsigned int stringLen;

bool allCharSame(unsigned char *s)
{
    int i = 0;
    while(s[i])
    {
        if(s[i] != s[0])
            return false;
        i++;
    }

    return true;
}

int main()
{
    unsigned char arr[] = "aaa";
    stringLen = sizeof(arr);

    if(allCharSame(arr))
        printf("Yes");
    else
        printf("No");
    
    printf("\r\n");

    return 0;
}