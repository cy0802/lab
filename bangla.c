#include<stdio.h>
#define kuti 10000000
#define lakh 100000
#define hajar 1000
#define shata 100
void bangla(long long int n, int flag){
	if(n / kuti != 0){
		bangla(n / kuti, 1);
		if(n % kuti == 0 && flag == 0) printf("kuti");
		else printf("kuti ");
		bangla(n % kuti, flag == 0 ? 0 : 1);
	} else if(n / lakh != 0){
		bangla(n / lakh, 1);
		if(n % lakh == 0 && flag == 0) printf("lakh");
		else printf("lakh ");
		bangla(n % lakh, flag == 0 ? 0 : 1);
	} else if(n / hajar != 0){
		bangla(n / hajar, 1);
		if(n % hajar == 0 && flag == 0) printf("hajar");
		else printf("hajar ");
		bangla(n % hajar, flag == 0 ? 0 : 1);
	} else if(n / shata != 0){
		bangla(n / shata, 1);
		if(n % shata == 0 && flag == 0) printf("shata");
		else printf("shata ");
		bangla(n % shata, flag == 0 ? 0 : 1);
	} 
	if(n / shata == 0 && n != 0){
		if(flag == 1) 	printf("%d ", n);
		else			printf("%d", n);
	}
}
int main(){
	long long int n;
	int cnt = 0;
	while(scanf("%lld", &n) && n != -1){
		cnt++;
		printf("%d. ", cnt);
		if(n == 0){
			printf("0\n");
			continue;
		}
		bangla(n, 0);
		printf("\n");
	}
	return 0;
}