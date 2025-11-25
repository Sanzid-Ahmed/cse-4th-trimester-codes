#include <stdio.h>
#include <string.h>


int main(){
    char s[1000], t[1000];
    printf("Enter s => \n");
    scanf("%s", &s);

    printf("\nEnter s => \n");
    scanf("%s", &t);

    if(strlen(s) != strlen(t)){
        printf("\nNO\n");
        return 0;
    }

    int num[26] = {0};

    for(int i = 0; s[i] != '\0'; i++){
        num[s[i] - 'a'] += 1;
    }

    for(int i = 0; t[i] != '\0'; i++){
        num[t[i] - 'a'] -= 1;
    }

    for(int i = 0; i < 26; i++){
        if(num[i] != 0){
            printf("\nNO\n");
            return 0;
        }
    }

    printf("\nYES\n");
    return 0;

}
