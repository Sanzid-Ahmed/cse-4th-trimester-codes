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

    int found;
    //for(int i = 0; i < n; i++){
        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            //if(nums[mid] == i){
                //break;
            //}
            if(nums[mid] > mid)
                end = mid - 1;
            else
                start = mid + 1;

        }

        //if(start > end){
            //found = i;
            //break;
        //}
    //}


    //printf("\n%d\n", found);
    printf("\n%d\n", start);

    return 0;
}
