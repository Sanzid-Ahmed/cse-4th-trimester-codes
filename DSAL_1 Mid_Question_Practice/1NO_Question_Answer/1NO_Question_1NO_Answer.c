#include <stdio.h>

int firstOccurrence(int arr[], int x, int n){
    int first = 0;
    int last = n - 1;

    int ans = -1;
    while(first <= last){
        int mid = first + (last - first)/2;

        if(arr[mid] == x){
            ans = mid;
            last = mid - 1;
        }
        else if(arr[mid] > x){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }

    return ans;
}


int lastOccurrence(int arr[], int x, int n){
    int first = 0;
    int last = n - 1;

    int ans = -1;
    while(first <= last){
        int mid = first + (last - first)/ 2;

        if(arr[mid] == x){
            ans = mid;
            first = mid + 1;
        }
        else if(arr[mid] > x){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }

    return ans;
}



int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);


    int first = firstOccurrence(arr, x, n);
    int last = lastOccurrence(arr, x, n);

    if(first == -1){
        printf("0\n");
    }
    else{
        printf("%d", last - first + 1);
    }


    return 0;
}
