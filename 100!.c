#include<stdio.h>
int main(){
    int two, five;
    int n, num, i;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &num);
        two = 0;
        five = 0;
        //printf("%d\n", num);
        for(i = 1; i <= num; i++){
            int j = i;
            //printf("%d ", j);
            while(j % 2 == 0 && j != 0){
                j /= 2;
                two++;
                //printf("%d ", j);
            }
            while(j % 5 == 0 && j != 0){
                j /= 5;
                five++;
                //printf("%d ", j);
            }
            //printf(" / %d: %d %d\n", i, two, five);
        }
        printf("%d\n", two > five ? five : two);
    }
    return 0;
}