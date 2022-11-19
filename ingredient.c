#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int testCase;
    int n, k;
    char **ingredient;
    int *frequency;
    int *record;
    scanf("%d", &testCase);
    while (testCase--) {
        scanf("%d %d", &n, &k);
        ingredient = malloc(n * sizeof(char*));
        frequency = malloc(n * sizeof(int));
        record = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            ingredient[i] = malloc(100 * sizeof(char));
            scanf("%s %d", ingredient[i], &frequency[i]);
            record[i] = 1;
        }
        // record: how many times(-1) the gredient has been added
        while(k--){
            int minIndex = 0;
            int minValue = frequency[0] * record[0];
            for(int i = 0; i < n; i++){
                if(frequency[i] * record[i] < minValue){
                    minValue = frequency[i] * record[i];
                    minIndex = i;
                }
            }
            printf("%d %s\n", minValue, ingredient[minIndex]);
            record[minIndex]++;
        }
        for(int i = 0; i < n; i++){
            free(ingredient[i]);
        }
        free(ingredient);
        free(frequency);
        free(record);
    }
    return 0;
}