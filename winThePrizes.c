#include<stdio.h>
#include<stdlib.h>
struct Player{
    int id;
    struct Player *next;
    struct Player *fixedNext;
};
void initiate(struct Player *head, int k){
    struct Player *it = head;
    while(k--){
        it -> next = it -> fixedNext;
        it = it -> fixedNext;
    }
}
struct Player* buildList(int player){
    struct Player *head = malloc(sizeof(struct Player));
    head -> id = 1;
    head -> next = head -> fixedNext = NULL;
    struct Player *it = head;
    struct Player *ret = NULL;
    for(int i = 2; i <= player; i++){
        struct Player *tmp = malloc(sizeof(struct Player));
        tmp -> id = i;
        it -> next = it ->fixedNext = tmp;
        if(i == player) ret = it;
        it = tmp;
    }
    it -> next = it -> fixedNext = head;
    return it;
}
void _free(struct Player *head, int player){
    struct Player *it = head;
    while(player--){
        struct Player *tmp = it;
        it = it -> fixedNext;
        free(tmp);
    }
}
int main(){
    int k;
    int minM[14];
    for(k = 2; k < 14; k++){
        //printf("k: %d\n", k);
        int player = 2 * k;
        struct Player *head = buildList(player);
        /*struct Player *it = head;
        for(int i = 0; i < player+5; i++){
            printf("%d ", it -> id);
            it = it -> next;
        }
        printf("\n");*/
        for(int m = 2;; m++){
            //printf("m: %d\n", m);
            struct Player *it = head;
            int cnt = 1;
            int flag = 0;
            for(int round = 1; round <= k; round++){
                //printf("round: %d\t", round);
                // eliminate one player
                cnt = m % (player - round + 1) - 1;
                if(cnt < 0) cnt += (player - round + 1);
                //printf("cnt: %d\t", cnt);
                while(cnt--){
                    it = it -> next;
                }
                //printf("eliminate %d\n", it -> next -> id);
                if(it -> next -> id <= k){
                    //printf("*\n");
                    flag = 1;
                    break;
                }
                it -> next = it -> next -> next;
            }
            // this m failed
            if(flag){
                initiate(head, player);
                continue;
            } else {
                minM[k] = m;
                _free(head, player);
                break;
            }
        }
    }
    minM[1] = 2;
    /*for(int i = 1; i < 14; i++){
        printf("%d ", minM[i]);
    }
    printf("\n");*/
    while(scanf("%d", &k) && k != 0){
        printf("%d\n", minM[k]);
    }
    return 0;
}