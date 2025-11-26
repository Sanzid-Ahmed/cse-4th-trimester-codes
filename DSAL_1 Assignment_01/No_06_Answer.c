#include <stdio.h>

int main(){
    int num;
    printf("Enter the number => ");
    scanf("%d", &num);


    int start = 0;
    int end = num;

    while(start <= end){
        int mid = start + (end - start)/ 2;

        if(mid * mid == num){
            printf("YES");
            break;
        }
        else if(mid * mid < num)
            start = mid + 1;
        else
            end = mid - 1;
    }

    if(start > end)
        printf("NO");


        return 0;
}
