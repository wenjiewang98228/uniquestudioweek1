#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<malloc.h>

#define hashTableMaxSize 10

typedef struct hashNode hashNode;

struct hashNode{
    int key;
    int value;
    hashNode* pNext;
};

void hashTableInsert(int ch, int n);
void hashTableRemove(int ch, int n);
hashNode* hashTableFind(int ch,int n);
void hashTablePrint();

hashNode* hashTable[hashTableMaxSize];

//test
int main(){
    //hashTableInit();

    for(int i = 0; i < hashTableMaxSize; i++){
        hashTable[i] = NULL;
    }

    //testInsert
    hashTableInsert(12,150);
    hashTableInsert(225,160);
    hashTableInsert(32,140);
    hashTableInsert(12,140);
    hashTableInsert(130,25);
    hashTableInsert(12,150);
    hashTableInsert(33,167);
    hashTableInsert(15,36);
    hashTableInsert(39,125);
    hashTableInsert(66,12);
    hashTableInsert(56,19);

    //testPrint
    hashTablePrint();
    printf("\n");

    //testFind
    hashTableFind(15, 999);
    hashTableFind(22,140);

    //testRemove
    hashTableRemove(11,110);
    hashTableRemove(12,150);
    hashTableRemove(56,19);
    hashTableRemove(39,125);

    hashTablePrint();
    printf("\n");

}

void hashTablePrint(){

    for(int i = 0; i < hashTableMaxSize; i++){
        printf("the %d tab:  ", i);
        hashNode* p = hashTable[i];
        if(p == NULL);
        else{
            while(p -> pNext != NULL){
            printf("%d,%d  ",p -> key, p ->value);
            p = p -> pNext;
            }
            printf("%d,%d  ",p->key,p->value);
        }
        printf("\n");
    }
}

void hashTableInsert(int ch, int n){

    int hashCode = ch%10;

    for(int i = 0; i < hashTableMaxSize; i++){
        while(hashCode == i){

            if(hashTable[i] != NULL){
                hashNode* ptr = hashTable[i];

                while((ptr -> key != ch || ptr -> value != n) && ptr -> pNext != NULL){
                    ptr = ptr -> pNext;
                }

                if(ptr -> pNext == NULL && (ptr -> key != ch || ptr -> value != n)){
                    ptr -> pNext = (hashNode*)malloc(sizeof(hashNode));
                    ptr = ptr -> pNext;
                    ptr -> key = ch;
                    ptr -> value = n;
                    ptr -> pNext = NULL;
                    return;
                }

                if(ptr -> key == ch && ptr -> value == n){
                    printf("the %d,%d has existed\n\n",ch,n);
                    return;
                }
            }
            else{
                hashTable[i] = (hashNode*)malloc(sizeof(hashNode));
                hashNode *p = hashTable[i];

                p -> key = ch;
                p -> value = n;
                p -> pNext = NULL;
                return;
            }
        }
    }
}

 hashNode* hashTableFind(int ch,int n){

    for(int i = 0; i < hashTableMaxSize; i++){
        if(ch%10 == i){
            hashNode* p = hashTable[i];

            if(p == NULL){
                printf("the %d,%d can't find\n\n",ch,n);
                return NULL;
            }
            else{
                while((p -> key != ch && p -> value != n) && p -> pNext != NULL){
                    p = p -> pNext;
                }
                if(p -> key = ch && p -> value == n){
                    printf("the %d,%d is at:%d\n",ch,n,p);
                }
                if(p -> pNext == NULL){
                    printf("the %d,%d can't find\n\n",ch,n);
                    return p;
                }
            }
        }
    }
 }

void hashTableRemove(int ch,int n){
    hashNode* tmp = hashTableFind(ch,n);
    int hashCode = ch%10;

    if(tmp == NULL) {
        printf("can't remove %d,%d successfully\n\n",ch,n);
    }
    else{
        hashNode* p = hashTable[hashCode];

        if(p -> pNext == NULL){//the required hashCode has only one record
            hashTable[hashCode] = NULL;
            free(p);
            printf("remove %d,%d successfully\n\n",ch,n);
            return;
        }else{
            hashNode* t = p;

            if(p -> key == ch && p-> value == n){//the required hashCode is the first of the linked list
                hashTable[hashCode] = p -> pNext;
                free(p);
                printf("remove %d,%d successfully\n\n",ch,n);
                return;
            }

            while((p ->key != ch || p -> value != n ) && p -> pNext != NULL){
                t = p;
                p = p -> pNext;
            }

            if(p -> pNext == NULL){//the required k/v is the last one of the linked list
                t -> pNext = NULL;
                free(p);
                printf("remove %d,%d successfully\n\n",ch,n);
                return;
            }

            if(p -> pNext != NULL){
                t -> pNext = p -> pNext;
                free(p);
                printf("remove %d,%d successfully\n\n",ch,n);
                return;
            }
        }
    }
}
