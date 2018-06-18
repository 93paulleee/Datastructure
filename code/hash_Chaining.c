#include<stdio.h>
#include<stdlib.h>
#define MAX_HASH 10
#define HASH_KEY(key) key%MAX_HASH

typedef struct Node{
	int id;
	Node* hashNext;
}Node;

Node* hashTable[MAX_HASH];

void AddHashData(int key, Node* node){
	int hash_key = HASH_KEY(key);
	if(hashTable[hash_key] == NULL )
	{
		hashTable[hash_key] = node;
	}
	else
	{
		node -> hashNext = hashTable[hash_key];
		hashTable[hash_key] = node;
	}
}
void DelHashData(int id){
	int hash_key = HASH_KEY(id);
	if(hashTable[hash_key] == NULL)
		return;
	Node* delNode = NULL;
	if(hashTable[hash_key]->id==id){
		delNode = hashTable[hash_key];
		hashTable[hash_key] = hashTable[hash_key]-> hashNext;
	}
	else{
		Node* node = hashTable[hash_key];
		Node* next = node->hashNext;
		while(next){
			if(next->id==id){
				node->hashNext = next->hashNext;
				delNode = next;
				break;
			}
			node = next;
			next = node->hashNext;
		}
	}
	free(delNode);
}
void PrintAllHashData(){
	printf("####Print Data\n");
	for(int i = 0 ; i<MAX_HASH ; i++){
		printf("idx: %d \n",i);
		if(hashTable[i]!=NULL){
			Node* node = hashTable[i];
			while(node->hashNext){
				printf(" %d ", node-> id);
				node = node->hashNext;
			}
			printf(" %d \n",node->id);
		}
	}
	printf("\n\n");
}

int main()
{
    int saveidx[101] = { 0, };
    for (int i = 0; i < 100; i++)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->id = rand() % 1000;
        node->hashNext = NULL;
        AddHashData(node->id, node);
        saveidx[i] = node->id;
    }
    PrintAllHashData();
 
 
    for (int i = 0; i < 50 ; i++)
    {
        DelHashData(saveidx[i]);
    }
    PrintAllHashData();
 
    for (int i = 50; i < 100; i++)
    {
        DelHashData(saveidx[i]);
    }
    PrintAllHashData();
    return 0;
 
}


