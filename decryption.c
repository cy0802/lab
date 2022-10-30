//still get many WAs
#include<stdio.h>
#include<string.h>
int main(){
    int n;
    char plaintext[] = "the quick brown fox jumps over the lazy dog";
    scanf("%d\n\n", &n);
    while(n--){
        char data[200][2000];
        char key[] = "the quick brown fox jumps over the lazy dog";
        int k = 0;
        while(1){
            gets(data[k]);
            if(data[k][0] == '\0' || data[k] == NULL) break;
            //printf("%s\n", data[k]);
            k++;
        }
        //printf("%d\n", k);
        int same = 1, flag = 0;
        for(int i = 0; i < k; i++){ // num of string
            if(strlen(plaintext) != strlen(data[i])) continue;
            for(int j = 0; j < strlen(data[i]); j++){
                if((data[i][j] == ' ' && plaintext[j] != ' ') || (data[i][j] != ' ' && plaintext[j] == ' ')){
                    same = 0;
                    break;
                }
            }
            if(same == 1){
                strcpy(key, data[i]);
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("No solution.\n");
            if(n) printf("\n");
            continue;
        }
        char map[26];
        for(int i = 0; i < strlen(plaintext); i++){
            map[key[i]-'a'] = plaintext[i];
        }
        //printf("%s\n%s\n", key, plaintext);
        //printf("%s", map);
        for(int i = 0; i < k; i++){
            for(int j = 0; j < strlen(data[i]); j++){
                if(data[i][j] == ' ') continue;
                data[i][j] = map[data[i][j]-'a'];
            }
        }
        for(int i = 0; i < k; i++){
            printf("%s\n", data[i]);
            //try not to output any \n at the end of output
            //if(n != 0 || i != k-1){
            //   printf("\n");
            //}
        }
        if(n) printf("\n");
    }
    return 0;
}
