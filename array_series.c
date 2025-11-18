/*------------------------------------------------------
* Filename: array_series.c
* Description: Check if an array is increasing, decreasing, constant, or messed up
* Author: Gershon Levy
-------------------------------------------------------*/

#include <stdio.h>

#define ARR_SIZE 15

#define TRUE 1
#define FALSE 0

/*------------------------------------------------------
* Function Name -  check_increasing
*
* Function Purpose - Checks if the values are increasing around an index i in an array.
*
* Parameters –  [IN arr - Our array.]
*               [IN i - The index to check.]
*
* Return Values - 1: The array is not increasing
*                 0: The array is increasing
*
* Author - Gershon Levy
-------------------------------------------------------*/

int check_increasing(int arr[], int i)
{
    return (arr[i] < arr[i - 1]);
}

/*------------------------------------------------------
* Function Name -  check_decreasing
*
* Function Purpose - Checks if the values are decreasing around an index i in an array.
*
* Parameters –  [IN arr - Our array.]
*               [IN i - The index to check.]
*
* Return Values - 1: The array is not decreasing
*                 0: The array is decreasing
*
* Author - Gershon Levy
-------------------------------------------------------*/

int check_decreasing(int arr[], int i)
{
    return (arr[i] > arr[i - 1]);
}

/*------------------------------------------------------
* Function Name -  check_const
*
* Function Purpose - Checks if the values are constant around an index i in an array.
*
* Parameters –  [IN arr - Our array.]
*               [IN i - The index to check.]
*
* Return Values - 1: The array is not constant
*                 0: The array is constant
*
* Author - Gershon Levy
-------------------------------------------------------*/

int check_const(int arr[], int i)
{
    return (arr[i] != arr[i - 1]);
}

int main()
{

    /*init*/
    int arr[ARR_SIZE] = {0};
    int is_increasing = TRUE;
    int is_decreasing = TRUE;
    int is_const = TRUE;
    int i = 1;

    printf("Enter %d nums: ", ARR_SIZE);
    // have to have scanf before while because the functions rely on arr[i-1]
    scanf("%d", &arr[0]);

    /*input the arr*/
    for (i = 1; i < ARR_SIZE; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        /*Check array status mid-loop. note that array is considered mixed if nums equal*/
        if (is_increasing == TRUE && check_increasing(arr, i))
        {
            is_increasing = FALSE;
        }

        if (is_decreasing == TRUE && check_decreasing(arr, i))
        {
            is_decreasing = FALSE;
        }

        if (is_const == TRUE && check_const(arr, i))
        {
            is_const = FALSE;
        }
    }

    /*print array status*/
    if (is_increasing == TRUE)
    {
        printf("The Array is increasing\n");
    }
    else if (is_decreasing == TRUE)
    {
        printf("The Array is decreasing\n");
    }

    else if (is_const == TRUE)
    {
        printf("The Array is constant\n");
    }

    /*if arr is nothing else then its messed up*/
    else
    {
        printf("The Array is messed up\n");
    }

    return 0;
}