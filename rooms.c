#include<stdio.h>
#include<math.h>
int room[30005];
int nextRoom(int pos){
    //printf("%d ", pos);
    if(pos == 1){
        return room[1] = 1;
    } else if(pos < 30000 && pos >= 0){
        if(room[pos] != 0){
            return room[pos];
        }
    }
    if (pos < 0){
        return nextRoom(pos * pos) + 1;
    } else if (pos % 2 == 0) {
        if(pos > 30000) return nextRoom(pos / 2) + 1;
        else return room[pos] = nextRoom(pos / 2) + 1;
    } else if (pos % 2 == 1) {
        if(pos > 30000 || 3 * pos + 1 > 30000) return nextRoom(3 * pos + 1) + 1;
        else return room[pos] = nextRoom(3 * pos + 1) + 1;
    }
}
int main(){
    int l, u, maxValue, maxIdx;
    for(int i = 0; i < 3*u+2 && i < 30000; i++){
        room[i] = 0;
    }
    while(scanf("%d %d", &l, &u) != EOF){
        /*for(int i = l; i <= u; i++){
            if(i == 0) continue;
            printf("%d\t", i);
            nextRoom(i);
            printf("\n");
        }*/
        //nextRoom(-24);
        maxValue = 0;
        for(int i = l; i <= u; i++){
            if(i == 0) continue;
            if(nextRoom(i) > maxValue){
                maxValue = nextRoom(i);
                maxIdx = i;
            }
            //printf("%d: %d\n", i, nextRoom(i));
        }
        printf("Room_%d %d\n", maxIdx, maxValue);
    }
    printf("\n");
    return 0;
}