#include<iostream>
#include<String.h>
using namespace std;
#define MAX 100
struct sinhvien{
	char mssv[MAX], ten[MAX], xeploai[MAX];
	float diem;
};
typedef sinhvien ElementType;
struct Node{
	ElementType Element;
	Node *next;
};
typedef Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void makeNull_List(List &l);
void insertList(ElementType x, Position p, List l);
void xeploai(List &l);
void nhapNode(ElementtType &x);
void nhapDS(List l, int n);
void xuatNode(ElementType x);
void xuatDS(List l);
void sapXepTang(List l);
void saoXepGiam(List l);
void tach(List l, List l1, List l2);

int main(){
	List l;
	int n;
	cout << "nhap n: ";cin >> n;
	makeNull_List(l);
	
	return 0;
}


void makeNull_List(List &l){
	l = new Node;
	l->next = NULL;
}
void insertList(ElementType x, Position p, List l){
	Position tmp;
	tmp = new Node;
	while(tmp == NULL)
		cout << "danh sach rong";
	else{
		tmp->Element = x;
		tmp->next = p->next;
		p->next = tmp;
	}
}
void xeploai(List &l);
void nhapNode(ElementtType &x);
void nhapDS(List l, int n);
void xuatNode(ElementType x);
void xuatDS(List l);
void sapXepTang(List l);
void saoXepGiam(List l);
void tach(List l, List l1, List l2);
