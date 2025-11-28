#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    float low = 0, high = N;
    while((high * high - low * low) >= 0.001){
        float mid = low + (high - low) / 2;
        if(mid * mid > N)
            high = mid;
        else
            low = mid;
    }

    printf("%.3f", low);


    return 0;
}
