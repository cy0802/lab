#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int idxBegin;
    int idxEnd;
    struct Node *next;
};
void add(struct Node *pos, int begin, int end){
    //printf("%d %d\n", begin, end);
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp -> idxBegin = begin;
    tmp -> idxEnd = end;
    tmp -> next = pos -> next;
    pos -> next = tmp;
    pos = tmp;
}
int main(){
    char input[100000];
    while(scanf("%s", input) != EOF){
        struct Node *head = malloc(sizeof(struct Node));
        head -> idxBegin = head -> idxEnd = -1;
        head -> next = NULL;
        struct Node *pos = head;
        int begin = 0;
        for(int i = 0; i < strlen(input); i++){
            if(input[i] == '['){
                add(pos, begin, i - 1);
                begin = i + 1;
                pos = head;
            } else if(input[i] == ']'){
                add(pos, begin, i - 1);
                while(pos -> next != NULL){
                    pos = pos -> next;
                }
                begin = i + 1;
            }
        }
        add(pos, begin, strlen(input) - 1);
        struct Node *it = head -> next;
        //printf("\n\n");
        while(it != NULL){
            for(int i = it -> idxBegin; i <= it -> idxEnd; i++){
                printf("%c", input[i]);
            }
            //printf("%d %d\n", it -> idxBegin, it -> idxEnd);
            it = it -> next;
        }
        printf("\n");
    }
    return 0;
}