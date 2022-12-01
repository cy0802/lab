#include<stdio.h>
#include<string.h>
#define MAXLEN 2000
void add(int a[MAXLEN], int b[MAXLEN], int c[MAXLEN]){
    int carry = 0;
    for(int i = 0; i < MAXLEN; i++){
        c[i] = a[i] + b[i] + carry;
        carry = c[i] / 10;
        c[i] %= 10;
    }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int fibo[3][MAXLEN] = {0};
        if(n == 0){
            printf("The Fibonacci number for 0 is 0\n");
            continue;
        } else if(n == 1){
            printf("The Fibonacci number for 1 is 1\n");
            continue;
        }
        fibo[1][0] = 1;
        for(int i = 2; i <= n; i++){
            add(fibo[(i - 1) % 3], fibo[(i - 2) % 3], fibo[i % 3]); // f[i] = f[i-1] + f[i-2]
            /*for(int j = 0; j < 10; j++){
                printf("%d", fibo[i%3][j]);
            }
            printf("\n");*/
        }
        int length;
        for(int i = 0; i < MAXLEN; i++){
            if(fibo[n % 3][i] != 0){
                length = i;
            }
        }
        //printf("%d\n", length);
        printf("The Fibonacci number for %d is ", n);
        for(int i = length; i >= 0; i--){
            printf("%d", fibo[n % 3][i]);
        }
        printf("\n");
    }
}