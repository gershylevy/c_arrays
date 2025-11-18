/*------------------------------------------------------
* Filename: str_to_int_atoi.c
* Description: Convert an str to int and add 36 to it using atoi.
* Author: Gershon Levy
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define ZERO '0'
#define NOT_A_NUM_ERR -1

int main()
{
    char str[MAX_SIZE];
    int num;
    int size = 0;

    str[0] = fgetc(stdin);

    while (size < 100 && str[size] != '\n')
    {
        ++size;
        str[size] = fgetc(stdin);
        if ((str[size] < '0' || str[size] > '9') && str[size] != '\n')
        {
            printf("not a number\n");
            return NOT_A_NUM_ERR;
        }
    }

    num = atoi(str);

    num += 36;

    printf("%d", num);

    return 0;
}