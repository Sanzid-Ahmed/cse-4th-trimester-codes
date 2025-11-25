#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of the array => ");
    scanf("%d", &n);


    int nums[n];
    printf("\nEnter the elements of the array\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    int target;
    printf("\nEnter the targeted number\n");
    scanf("%d", &target);


    int start = 0;
    int end = (n - 1);

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(nums[mid] == target){
            printf("\n%d\n", mid);
            break;
        }
        else if(nums[mid] < target)
            start = mid + 1;
        else end = mid - 1;
    }

    if(start > end){
        printf("\nThe number not exist!\n");
    }

    return 0;
}
