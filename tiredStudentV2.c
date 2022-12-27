#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char *str;
    struct Node *next;
};
void insert(struct Node *pos, char str[]){
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp -> str = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(tmp -> str, str);
    //printf("tmp: %p, list: %p\n", str, tmp -> str);
    tmp -> next = pos -> next;
    pos -> next = tmp;
    pos = tmp;
}
int main(){
    char input[100005];
    while(scanf("%s", input) != EOF){
        struct Node *head = malloc(sizeof(struct Node));
        head -> str = "*";
        head -> next = NULL;
        struct Node *pos = head;
        int begin = 0;
        char tmp[100005];
        for(int i = 0; i < strlen(input); i++){
            if(input[i] == '['){
                strncpy(tmp, input + begin, i - begin);
                tmp[i - begin] = '\0';
                //printf("begin: %d, i: %d, tmp: %s\n", begin, i, tmp);
                insert(pos, tmp);
                pos = head;
                begin = i + 1;
            } else if (input[i] == ']') {
                strncpy(tmp, input + begin, i - begin);
                tmp[i - begin] = '\0';
                //printf("begin: %d, i: %d, tmp: %s\n", begin, i, tmp);
                insert(pos, tmp);
                while(pos -> next != NULL){
                    pos = pos -> next;
                }
                begin = i + 1;
            }
        }
        strcpy(tmp, input + begin);
        //printf("begin: %d, tmp: %s\n", begin, tmp);
        insert(pos, tmp);

        struct Node *it = head -> next;
        while(it != NULL){
            struct Node *tmp = it;
            printf("%s", it -> str);
            it = it -> next;
            free(tmp -> str);
            free(tmp);
        }
        free(head);
        printf("\n");
    }
    return 0;
}