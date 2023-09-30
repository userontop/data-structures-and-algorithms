#include<stdio.h>
#define MAX 100
struct Node
{
	int value;
	Node* next;
};

struct dslk{
	Node* a;
};
void taodslk(dslk &l);
int sl(dslk l);
int main(){
	dslk l;
	taodslk(l);
}

void taodslk(dslk &l){
	l = new Node;
	l -> Next = NULL;
}

int sl(dslk l)
{
	int count = 0;
	position P = L -> Next;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
