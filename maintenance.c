#include<stdio.h>
int main(){
    int t, n, m, cnt;
    int machine[105];
    scanf("%d", &t);
    while(t--){
        scanf("%d\n%d", &n, &m);
        for(int i = 0; i < m; i++) scanf("%d", &machine[i]);
        cnt = 0;
        for(int i = 1; i <= n; i++){ // ith day
            if(i % 7 == 6 || i % 7 == 0) continue;
            for(int j = 0; j < m; j++){ // jth machine
                if(i % machine[j] == 0){
                    //printf("%d ", i);
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}