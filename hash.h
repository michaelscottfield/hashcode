//this is code for basic hash functions
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef struct pairr{
	char* key;
	int value;
}pairr;
typedef struct linknode{
	linknode* next;
	pairr x;	
}lnode;

typedef struct  linktable{
	int len;
	lnode* head;
}ltable;

typedef struct hashtable{
	int len;
	linktable lists[20];
}htable;

//链表插入操作
void insert(pairr p, ltable* list){
	if(list -> head){
		if(p.key <= list -> head -> x.key){
			lnode* node = (linknode *)malloc(sizeof(linknode));
			node -> x.key = p.key;
			node -> x.value = p.value;
			node -> next = list -> head;
			list -> head = node;
		}
		else{
			lnode* temp = list -> head;
			lnode* node = (linknode *)malloc(sizeof(linknode));
			while(temp -> next && p.key >= temp -> x.key){
				temp = temp -> next;
			}
			node -> x.key = p.key;
			node -> x.value = p.value;
			node -> next = temp -> next;
			temp -> next = node;

		}
	}
	else{   
		lnode* node = (linknode *)malloc(sizeof(linknode));
		node -> x.key = p.key;
		node -> x.value = p.value;
		node -> next = NULL;
		list -> head = (linknode *)malloc(sizeof(linknode));
		list -> head -> x = node -> x;
		list -> head -> next = NULL;
	}
	return;
}

//链表查询操作
int search(char key[], ltable* list){
	if(list -> head){
		lnode* node = (linknode *)malloc(sizeof(linknode));
		node = list -> head;
		while(node){
			if(strcmp(node -> x.key, key) == 0)
				return node -> x.value;
			node = node -> next;
		}
		return -2;
	}
	else{
		return -3;		
	}
}

//hash function
int hhash(char key[], int tablelen, int len){
	int nhash = 0;
	for(int i = 0; i < len; i++){
		nhash = (nhash << 5) + nhash + key[i];
	}
	return nhash % tablelen;
}

void Insertkey(pairr p, hashtable* x, int len){
	int v = hhash(p.key, x -> len, len);
	insert(p, &(x -> lists[v]));
	return;
}

//哈希表查询操作
int hvalue(char key[], hashtable x, int len){
	int v = hhash(key, x.len, len);
	return search(key, &x.lists[v]);
}
