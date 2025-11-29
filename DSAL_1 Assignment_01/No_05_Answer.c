#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of the array => ");
    scanf("%d", &n);


    int nums[n];
    printf("Enter an sorted array : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

        int start = 0;
        int end = n;

        while(start < end){
            int mid = start + (end - start) / 2;


            if(nums[mid] == mid)
                start = mid + 1;
            else
                end = mid;

        }

    printf("\n%d\n", start);

    return 0;
}
