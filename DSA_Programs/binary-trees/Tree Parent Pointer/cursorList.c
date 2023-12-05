#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct {
    int data;
    int left, right;
} Node;

typedef struct {
    Node elem[MAX];
    int avail;
} VH;

typedef int Head;

void initialize(VH* v, Head* h)
{    
    int i;
    
    for(i = 0; i < MAX; i++) {
        v->elem[i].left = i + 1;
        v->elem[i].right = i + 1;
    }
    v->avail = 0;
    *h = -1;
}

int allocSpace(VH* v)
{
    int retval = v->avail;
    
    if(retval != -1)
        v->avail = v->elem[v->avail].left;
    
    return retval;
}

void deallocSpace(VH* v, int idx)
{
	if(idx > -1 && idx < MAX) {
		v->elem[idx].left = v->avail;
		v->elem[idx].right = v->avail;
		v->avail = idx;
	}
}

void insertNode(int data, VH* v, Head* h)
{
    if(v->avail < MAX) {
        int* trav;
            
        for(trav = h; *trav != -1 && v->elem[*trav].data != data;) {
            if(data <  v->elem[*trav].data) trav = &v->elem[*trav].left;
            else if(data > v->elem[*trav].data) trav = &v->elem[*trav].right;
        }
            
        if(*trav == -1) {
            int temp = allocSpace(v);
        
            if(temp != -1) {
                v->elem[temp].data = data;
                v->elem[temp].left = -1;
                v->elem[temp].right = -1;
                
                *trav = temp;
            }
        }
    }
}

void deleteNode(int data, VH* v, Head* h)
{
	if(*h != -1) {
		int* trav;
		
		for(trav = h; *trav != -1 && v->elem[*trav].data != data; ) {
			if(data < v->elem[*trav].data) trav = &v->elem[*trav].left;
			else if(data > v->elem[*trav].data) trav = &v->elem[*trav].right;
		}
		
		if(*trav != -1) {
			int temp = *trav;
			v->elem[*trav].left = v->elem[temp].left;
			v->elem[*trav].right = v->elem[temp].right;
			
			deallocSpace(v, temp);
		}
	} 
}

int main()
{
    Head h;
    VH virtualHeap;
    
    initialize(&virtualHeap, &h);
    
    insertNode(3, &virtualHeap, &h);
    insertNode(1, &virtualHeap, &h);
    insertNode(5, &virtualHeap, &h);
    insertNode(6, &virtualHeap, &h);    
    insertNode(0, &virtualHeap, &h);
    
    deleteNode(5, &virtualHeap, &h);
    
    return 0;
}
