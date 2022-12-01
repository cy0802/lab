#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Species {
    char name[35];
    int population;
};

int cmp(const void* _a, const void* _b){
    char* a = (*(struct Species*)_a).name;
    char* b = (*(struct Species*)_b).name;
    return strcmp(a, b);
}

int main(){
    int n;
    scanf("%d\n", &n);
    while(n--){
        char tree[35];
        struct Species species[10005]; 
        int totalSpecies = 0;
        int totalTrees = 0;
        while(gets(tree) != NULL && tree[0] != '\0'){
            // search if the tree exist
            // if exist, update
            totalTrees++;
            int exist = 0;
            for(int i = 0; i < totalSpecies; i++){
                if(strcmp(species[i].name, tree) == 0){
                    exist = 1;
                    species[i].population++;
                    break;
                }
            }
            // if not exist, create
            if(!exist){
                strcpy(species[totalSpecies].name, tree);
                species[totalSpecies].population = 1;
                totalSpecies++;
            }
        }
        qsort((void*)species, totalSpecies, sizeof(species[0]), cmp);
        for(int i = 0; i < totalSpecies; i++){
            printf("%s %.4lf\n", species[i].name, species[i].population / 1.0 / totalTrees * 100);
        }
        printf("\n");
    }
    return 0;
}