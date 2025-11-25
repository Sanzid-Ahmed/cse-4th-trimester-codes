#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of the array =>");
    scanf("%d", &n);


    int nums[n];
    printf("\nEnter the elements of the array: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    int target;
    printf("\nEnter the targeted value => ");
    scanf("%d", &target);

    int start = 0;
    int end = n - 1;
    int first = -1;
    int last = -1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(nums[mid] == target){
            end = mid - 1;
            first = mid;
        }
        else if(nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    start = 0;
    end = n - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(nums[mid] == target){
            start = mid + 1;
            last = mid;
        }
        else if(nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    printf("%d %d", first, last);


    return 0;

}
