#include<stdio.h>
#include<string.h>
int main(){
    int n;
    char plaintext[] = "the quick brown fox jumps over the lazy dog";
    scanf("%d\n", &n);
    while(n--){
        char data[105][100];
        int k = 0;

        // input a case
        while(gets(data[k]) != NULL && data[k][0] != '\0'){
            k++;
        }
         
        // sometimes output an extra line 
        // because in the end of input data[k] will not be NULL
        // but gets() will return NULL when it doesn't read anything
        /*while(1){
            gets(data[k]);
            if(data[k][0] == '\0' || data[k] == NULL) break;
            k++;
        }*/

        // same = 0 => key is found
        // flag = 0 => no key is found 
        int same = 1, flag = 0;
        char map[27];
        for(int i = 0; i < k; i++){ // num of string
            if(strlen(plaintext) != strlen(data[i])) continue;
            same = 1;
            for(int j = 0; j < 26; j++){
                map[j] = '@';
            }
            map[26] = '\0';
            for(int j = 0; j < strlen(data[i]); j++){
                if((data[i][j] == ' ' && plaintext[j] != ' ') || (data[i][j] != ' ' && plaintext[j] == ' ')){
                    same = 0;
                    break;
                } 
                if(data[i][j] != ' '){
                    if(map[data[i][j]-'a'] != '@' && map[data[i][j]-'a'] != plaintext[j]){
                        same = 0;
                        break;
                    } else {
                        map[data[i][j]-'a'] = plaintext[j];
                    }
                }
            }
            if(same){
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("No solution.");
            if(n) printf("\n\n");
            continue;
        }
        
        // decrypt the input data and output
        for(int i = 0; i < k; i++){
            for(int j = 0; j < strlen(data[i]); j++){
                if(data[i][j] == ' ') printf(" ");
                else printf("%c", map[data[i][j]-'a']);
            }
            if(n != 0 || i != k-1) printf("\n");
        }
        if(n) printf("\n");
    }
    return 0;
}
