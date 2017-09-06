#include "hash.h"
#include <malloc.h>
int main(){
	hashtable *x = (hashtable *)malloc(sizeof(hashtable));
	x -> len = 10;
	int i;
	for(i = 0; i < 10; i++){
		x -> lists[i].len = 0;
		x -> lists[i].head = NULL;
	}
	 char key[] = "wertk";
	 pairr p;
	 p.key = key;
	 p.value = 20;
 	 Insertkey(p, x, 5);
	 char key2[] = "csaty";
	 p.key = key2;
	 p.value = 23;
         Insertkey(p, x, 5);
	 char key3[] = "dghji";
	 p.key = key3;
	 p.value = 29;
 	 Insertkey(p, x, 5);
	 char key4[] = "jikql";
	 p.key = key4;
	 p.value = 33;
 	 Insertkey(p, x, 5);
	 char key5[] = "rtiop";
	 p.key = key5;
	 p.value = 67;
	 Insertkey(p, x, 5);
	 char testkey[] = "wertk";
	 cout << hvalue(testkey, *x, 5) << endl;
	 strcpy(testkey, "dghji");
	 cout << hvalue(testkey, *x, 5) << endl;
	 return 0;
}
