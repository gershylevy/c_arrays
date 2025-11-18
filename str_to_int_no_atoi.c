/*------------------------------------------------------
* Filename: str_to_int_no_atoi.c
* Description: Convert an str to int and add 36 to it without using atoi.
* Author: Gershon Levy
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define ZERO '0'
#define NOT_A_NUM_ERR -1
#define FALSE 0
#define TRUE 1

int main()
{
    char str[MAX_SIZE];
    int num = 0;
    int size = 0;
    int minus = FALSE;
    int i = 0;

    str[0] = fgetc(stdin);

    if ((str[0] < '0' || str[0] > '9') && str[0] != '-')
    {
        printf("not a number\n");
        return NOT_A_NUM_ERR;
    }

    // get the num
    while (size < 100 && str[size] != '\n')
    {
        ++size;
        str[size] = fgetc(stdin);
        // check if its a valid num
        if ((str[size] < '0' || str[size] > '9') && str[size] != '\n')
        {
            printf("not a number\n");
            return NOT_A_NUM_ERR;
        }
    }

    // check if the number is negative
    if (str[0] == '-')
    {
        minus = TRUE;
        ++i;
    }

    for (; i < size; ++i)
    {
        str[i] -= ZERO;
        // make room for next number (e.g turn 12 into 120 so we could add 3 and get 123)
        num *= 10;

        // add next number if num is negative then do subtraction instead of addition
        if (minus == TRUE)
        {
            num -= str[i];
        }
        // add next num (for positives)
        else
        {
            num += str[i];
        }
    }

    num += 36;

    printf("%d", num);
}