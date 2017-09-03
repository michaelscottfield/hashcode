//this is code for basic hash functions
using namespace std;
typedef struct linknode{
	lnode* next;
	char* key;	
}lnode;

typedef struct linktable{
	int len;
	lnode* head;
}ltable;

typedef struct hashtable{
	int len;
	linktable lists[len];
}htable;

//链表插入操作
void insert(char* key, ltable* list){
	if(list -> head){
		if(key > list -> head -> key){
			lnode *temp = list -> head;
			lnode *prev;
			while(key > temp -> key && temp -> next){
				prev = temp;
				temp = temp -> next;
			}
			if(key < temp -> key){
				lnode* node;
				node -> key = key;
				prev -> next = node;
				node -> next = temp;
			}
			else if(key > temp -> key){
				lnode* node;
				node -> key = key;
				temp -> next = node;
				node -> next = null;
			}
		}
		else{
			lnode *temp;
			temp -> key = key;
			temp -> next = list -> head;
			list -> head = temp;
		}
	}
	else{
		lnode* temp;
		temp -> key = key;
		temp -> next = null;
		list -> head = temp;
	}
	list -> len ++;
}

//hash function
int hash(char* key, int tablelen){
	int nhash = 0;
	while(key){
		nhash = (nhash << 5) + nhash + *key++;
	}
	return nhash % tablelen;
}

void Insertkey(int key, hashtable x){
	int value = hash(key, x -> len);
	insert(key, x -> lists[value]);
}
