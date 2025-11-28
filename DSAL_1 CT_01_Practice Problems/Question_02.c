#include <stdio.h>

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);


    int start = 0, end = num, ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(mid * mid < num){
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    printf("%d", ans);

    return 0;

}
