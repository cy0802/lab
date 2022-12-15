#include<stdio.h>
#include<stdlib.h>
struct Homework{
    int point;
    int deadline;
};
int cmp(const void* _a, const void* _b){
    struct Homework a = *(struct Homework*)_a;
    struct Homework b = *(struct Homework*)_b;
    if(a.point == b.point){
        return a.deadline > b.deadline ? 1 : -1;
    } else {
        return a.point < b.point ? 1 : -1;
    }
}
int main(){
    struct Homework homework[10005];
    int n;
    int scheduled[10005]; // denote how much time remain before time i
    while(scanf("%d", &n) && n != -1){
        int maxPoint = 0;
        int maxTime = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &homework[i].point, &homework[i].deadline);
            maxTime = homework[i].deadline > maxTime ? homework[i].deadline : maxTime;
        }
        qsort((void*)homework, n, sizeof(homework[0]), cmp);
        for(int i = 1; i <= maxTime; i++) scheduled[i] = 0;
        for(int i = 0; i < n; i++){
            //printf("%d %d\n", homework[i].point, homework[i].deadline);
            for(int j = homework[i].deadline; j >= 1; j--){
                if(scheduled[j] == 0){
                    scheduled[j] = 1;
                    maxPoint += homework[i].point;
                    break;
                }
            }
        }
        printf("%d\n", maxPoint);
    }
    return 0;
}