#include<stdio.h>
#include<stdlib.h>
struct Segment{
    int left;
    int right;
    int chose;
};
int cmp(const void* _a, const void* _b){
    struct Segment a = *(struct Segment*)_a;
    struct Segment b = *(struct Segment*)_b;
    return a.left > b.left ? 1 : -1;
    return 0;
}
int main(){
    int testCase;
    int d;
    struct Segment segment[100005];
    scanf("%d", &testCase);
    while(testCase--){
        scanf("%d", &d);
        int cnt;
        int minSegment = 0;
        for(cnt = 0;; cnt++){
            scanf("%d %d", &segment[cnt].left, &segment[cnt].right);
            if(segment[cnt].left == 0 && segment[cnt].right == 0) break;
            if(segment[cnt].left > segment[cnt].right){
                int tmp = segment[cnt].left;
                segment[cnt].left = segment[cnt].right;
                segment[cnt].right = tmp;
            }
            segment[cnt].chose = 0;
        }
        qsort((void*)segment, cnt, sizeof(segment[0]), cmp);
        //for(int i = 0; i < cnt; i++){
            //printf("%d : %d %d\n", i, segment[i].left, segment[i].right);
        //}
        int flag = 0;
        for(int pos = 0; pos < d;){
            //printf("current position: %d\n", pos);
            int maxIdx = 0;
            int maxDis = 0;
            int found = 0;
            for(int i = 0; i < cnt; i++){
                if(segment[i].left <= pos && segment[i].right > pos){
                    if(segment[i].right - pos >= maxDis){
                        maxDis = segment[i].right - pos;
                        maxIdx = i;
                        found = 1;
                    }
                    if(segment[i].left >= pos){
                        break;
                    }
                }
            }
            if(found == 0){
                //printf("NOT FOUND\n");
                flag = 1;
                break;
            }
            //printf("chose segment: %d %d\n", segment[maxIdx].left, segment[maxIdx].right);
            segment[maxIdx].chose = 1;
            pos = segment[maxIdx].right;
            minSegment++;
        }
        //printf("-------------------\n");
        if(flag){
            printf("0\n");
            continue;
        }
        printf("%d\n", minSegment);
        for(int i = 0; i < cnt; i++){
            if(segment[i].chose){
                printf("%d %d\n", segment[i].left, segment[i].right);
            }
        }
        //printf("===================\n");
    }
    return 0;
}