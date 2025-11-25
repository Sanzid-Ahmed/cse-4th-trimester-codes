#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of the array => ");
    scanf("%d", &n);


    int nums[n];
    printf("\nEnter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    int found = 0;
    for(int i = 0; i < n; i++){
            found = 0;
        for(int j = 0; j < n; j++){
            if(i == nums[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            found = i;
            break;
        }
    }

    printf("\n%d\n", found);


    return 0;
}
