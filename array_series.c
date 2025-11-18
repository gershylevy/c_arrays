/*------------------------------------------------------
* Filename: array_series.c
* Description: Check if an array is increasing, decreasing, constant, or messed up
* Author: Gershon Levy
-------------------------------------------------------*/

#include<stdio.h>

#define ARR_SIZE 15
#define TRUE 1
#define FALSE 0

int main() {

    /*init*/
    int arr[ARR_SIZE]={0};
    int is_increasing=TRUE;
    int is_decreasing=TRUE;
    int is_const=TRUE;
    int i=1;

    printf("Enter a num: ");
    scanf("%d",&arr[0]);

    /*input the arr*/
    for(i=1;i<ARR_SIZE;++i){
        printf("Enter a num: ");
        scanf("%d",&arr[i]);

        /*Check array status mid-loop. note that array is considered mixed if nums equal*/
        if(is_increasing==TRUE&&arr[i]<=arr[i-1]){
            is_increasing=FALSE;
        }

        if(is_decreasing==TRUE&&arr[i]>=arr[i-1]){
            is_decreasing=FALSE;
        }

        if(is_const==TRUE&&arr[i]!=arr[i-1]){
            is_const=FALSE;
        }
    }

    /*print array status*/
    if(is_increasing==TRUE){
        printf("The Array is increasing\n");
    }
    else if(is_decreasing==TRUE){
        printf("The Array is decreasing\n");
    }

    else if(is_const==TRUE){
        printf("The Array is constant\n");
    }

    /*if arr is nothing else then its messed up*/
    else{
        printf("The Array is messed up\n");
    }


    return 0;
}