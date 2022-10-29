#include<stdio.h>
#include<string.h>
int main(){
    int n;
    int order[2000];
    char orderStr[2000];
    char data[200][2000];
    scanf("%d\n\n", &n);
    while(n--){
        scanf("\n");
        gets(orderStr);
        if(orderStr[0] == '\0') gets(orderStr);
        for(int i = 0; i < strlen(orderStr); i+=2){
            order[i/2] = orderStr[i]-'0';
            //printf("%d ", order[i/2]);
        }
        for(int i = 0; i < strlen(orderStr)/2+1; i++){
            scanf("%s", data[order[i]-1]);
        }
       //for(int i = 0; i < strlen(orderStr)/2+1; i++){
        //    printf("%d ", order[i]);
        //}
        //printf("%d\n", strlen(orderStr));
        //printf("*");
        for(int i = 0; i < strlen(orderStr)/2+1; i++){
            
            //printf("%d", i);
            printf("%s\n", data[i]);
        }
        printf("\n");
    }
    return 0;
}
