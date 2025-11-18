/*------------------------------------------------------
* Filename: encryption.c
* Description: Decrypt an encrypted message.
* Author: Gershon Levy
-------------------------------------------------------*/

#include <stdio.h>

#define MSG_LEN 26

#define MOVED_BACK 5
#define MULTED_BY 7
#define MOVED_FORWARD 4
#define GREW_BY 5

/*------------------------------------------------------
* Function Name - shrink_by_before
*
* Function Purpose - To shrink each element in the array by the one before it (after the one before it has been shrunk).
*
* Parameters –  [IN arr - The array.]
*
* Return Values - The updated array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

int *shrink_by_before(int arr[MSG_LEN])
{
    // we dont have to change arr[0]
    int i = 0;

    for (i = 1; i < MSG_LEN; ++i)
    {
        arr[i] -= arr[i - 1];
    }

    return arr;
}

/*------------------------------------------------------
* Function Name - move_n_forward
*
* Function Purpose - To cyclically move the array n forward.
*
* Parameters –  [IN arr - The array.]
*               [IN n - The amount to move forward.]
*
* Return Values - The updated array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

int *move_n_forward(int arr[MSG_LEN], int n)
{
    int i = 0;
    int temp[MSG_LEN];

    if (n < 0)
    {
        printf("Error: cant move negative number forward\n");
        return arr;
    }

    // instead of doing multiple loop arounds of the whole array we do only the last one (the only one that actually offsets)
    if (n > MSG_LEN)
    {
        n %= MSG_LEN;
    }

    // move everything n forward
    for (i = 0; i < MSG_LEN - n; ++i)
    {
        temp[i + n] = arr[i];
    }

    // move all the ones at the end to the beginning
    for (i = 0; i < n; ++i)
    {
        temp[i] = arr[(MSG_LEN - n) + i];
    }

    for (i = 0; i < MSG_LEN; ++i)
    {
        arr[i] = temp[i];
    }

    return arr;
}

/*------------------------------------------------------
* Function Name - divide_evens_by
*
* Function Purpose - To divide every element with an even index by a given number.
*
* Parameters –  [IN arr - The array.]
*               [IN num - The amount to divide by.]
*
* Return Values - The updated array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

int *divide_evens_by(int arr[MSG_LEN], int num)
{
    int i = 0;
    for (i = 0; i < MSG_LEN; i += 2)
    {
        // no need for if in loop since we jump by 2
        arr[i] /= num;
    }

    return arr;
}

/*------------------------------------------------------
* Function Name - shrink_by_n
*
* Function Purpose - To shrink every element by a given number.
*
* Parameters –  [IN arr - The array.]
*               [IN num - The amount to shrink by.]
*
* Return Values - The updated array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

int *shrink_by_n(int arr[MSG_LEN], int num)
{
    int i = 0;
    for (i = 0; i < MSG_LEN; ++i)
    {
        arr[i] -= num;
    }

    return arr;
}

/*------------------------------------------------------
* Function Name - decrypt
*
* Function Purpose - To decypt and print an incrypted array.
*
* Parameters –  [IN arr - The encrypted array.]
*
* Return Values - None.
*
* Author - Gershon Levy
-------------------------------------------------------*/

void decrypt(int arr[MSG_LEN])
{
    // to decrypt we need to do all the operations backwords and in backwords order
    int i = 0;

    arr = move_n_forward(arr, MSG_LEN / 2); // switching halfs is moving half the message forwards/backwords
    arr = shrink_by_before(arr);
    arr = move_n_forward(arr, MOVED_BACK); // moving len-x forward is the same as moving x backwords
    arr = divide_evens_by(arr, MULTED_BY);
    arr = move_n_forward(arr, MSG_LEN - MOVED_FORWARD);
    arr = shrink_by_n(arr, GREW_BY);

    printf("Your decrypted message is\n");

    for (i = 0; i < MSG_LEN; ++i)
    {
        printf("%c", arr[i]);
    }
}

int main()
{
    int msg[MSG_LEN] = {921, 842, 884, 953, 834, 837, 914, 915, 936, 948, 864, 780, 542, 116, 928, 925, 372, 365, 911, 909, 937, 959, 945, 940, 891, 886};

    int i = 0;

    printf("Enter the encypted message:\n");

    /*for (i = 0; i < MSG_LEN; ++i)
    {
        if (scanf("%d", &msg[i]) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }
    }*/

    decrypt(msg);

    return 0;
}