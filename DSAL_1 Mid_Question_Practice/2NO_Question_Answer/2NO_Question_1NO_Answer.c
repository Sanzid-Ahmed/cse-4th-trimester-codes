#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);


    float first = 0;
    float last = num;

    while((last * last * last - first * first * first) >= 0.0001){
        float mid = first + (last - first)/ 2;

        if(mid * mid * mid > num){
            last = mid;
        }
        else{
            first = mid;
        }
    }

    printf("%.3f", first);


    return 0;
}
