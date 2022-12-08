#include<stdio.h>
#include<math.h>
int isPrime[1000000];
int f[1000000] = {0};
int sumOfDigits(int n){
    int sum = 0;
    while(n != 0){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
int main(){
    int testCase, r1, r2;
    for(int i = 2; i <= 1000000; i++){
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i <= 1000; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= 1000000; j += i){
                isPrime[j] = 0;
            }
        }
    }
    int cur = 0;
    for(int i = 1; i <= 1000000; i++){
        f[i] = cur;
        if(isPrime[i] && isPrime[sumOfDigits(i)]){
            cur++;
        }
    }
    scanf("%d", &testCase);
    while(testCase--){
        scanf("%d %d", &r1, &r2);
        printf("%d\n", f[r2] - f[r1]);
    }
}