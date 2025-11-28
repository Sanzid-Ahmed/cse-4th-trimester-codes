#include <stdio.h>

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);


    int arr[size];
    printf("\nEnter the elements of the array: \n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the number: ");
    int num;
    scanf("%d", &num);


    int start = 0;
    int end = size - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] > num){
            end = mid - 1;
            ans = mid;
        }
        else
            start = mid + 1;
    }

    printf("%d", ans);

    return 0;
}
