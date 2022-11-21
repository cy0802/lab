#include<stdio.h>
int main(){
    int t, m, n;
    scanf("%d", &t);
    while(t--){
        char dna[55][1005];
        int numOfACGT[4] = {0};
        char ans[1005];
        int error = 0;
        scanf("%d %d\n", &m, &n);
        for(int i = 0; i < m; i++){
            gets(dna[i]);
        }
        for(int i = 0; i < n; i++){
            numOfACGT[0] = numOfACGT[1] = numOfACGT[2] = numOfACGT[3] = 0;
            for(int j = 0; j < m; j++){
                if(dna[j][i] == 'A') numOfACGT[0]++;
                else if(dna[j][i] == 'C') numOfACGT[1]++;
                else if(dna[j][i] == 'G') numOfACGT[2]++;
                else if(dna[j][i] == 'T') numOfACGT[3]++;
            }
            int max = 0, maxIdx;
            for(int j = 0; j < 4; j++){
                if(numOfACGT[j] > max){
                    max = numOfACGT[j];
                    maxIdx = j;
                }
            }
            if(maxIdx == 0) ans[i] = 'A';
            else if(maxIdx == 1) ans[i] = 'C';
            else if(maxIdx == 2) ans[i] = 'G';
            else if(maxIdx == 3) ans[i] = 'T';
            for(int j = 0; j < m; j++)
                if(dna[j][i] != ans[i])
                    error++;
        }
        ans[n] = '\0';
        printf("%s\n%d\n", ans, error);
    }
    printf("\n");
    return 0;
}