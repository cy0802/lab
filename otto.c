#include<stdio.h>
#define MOD 1234567890
long long int _pow(long long int x, long long int y){ // x^y
	if(y == 1) return x;
	if(y == 0) return 1;
	long long int tmp = _pow(x, y/2) % MOD;
	if(y % 2  == 0){
		return (tmp * tmp) % MOD;
	} else {
		return ((tmp * tmp) % MOD * x) % MOD;
	}
}
int main(){
	long long int n;
	while(scanf("%lld", &n) != EOF){
		if(n <= 0){
			printf("0\n");
			continue;
		}
		if(n == 1){
			printf("2\n");
			continue;
		}
		if(n % 2 == 1){
			printf("%lld\n", (2 * _pow(5, (n - 1) / 2)) % MOD);
		} else {
			printf("%lld\n", _pow(5, n / 2) % MOD);
		}
	}
	printf("\n");
	return 0;
}