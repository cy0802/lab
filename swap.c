#include<stdio.h>
#include<stdlib.h>
void swap(int *xp, int *yp){
    int* tmp = malloc(sizeof(int));
    *tmp = *xp;
    *xp = *yp;
    *yp = *tmp;
    free(tmp);
}
int main(){
    int n, l;
    int box[55];
    int cnt;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &l);
        for(int i = 0; i < l; i++){
            scanf("%d", &box[i]);
        }
        cnt = 0;
        for(int i = 0; i < l - 1; i++){
            for(int j = 0; j < l - i - 1; j++){
                if(box[j] > box[j+1]){
                    swap(&box[j], &box[j+1]);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}