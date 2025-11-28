#include <stdio.h>


int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements of the array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target: ");
    scanf("%d", &target);

    int start = 0, end = size - 1, c = 0, b = -1, e = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] <= target){
            if(arr[mid] == target) b = mid;

            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    start = 0;
    end = size - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] >= target){
            if(arr[mid] == target) e = mid;

            end = mid - 1;
        }
        else
            start = mid + 1;
    }

   printf("%d", b - e + 1);


    return 0;
}
