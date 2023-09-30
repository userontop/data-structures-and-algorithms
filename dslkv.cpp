// danh sach lien ket don vong
#include<stdio.h>
#include<iostream>
using namespace std;
int n;
struct Node{
	int data;
	Node  *next;//chua dia chi node ke tiep ma cn tro toi
};

struct List{
	Node *head;
	Node *tail;
};

void Init(List &l){//khoi tao List rong
	l.head = l.tail = NULL;
}

Node *creatNode(int x){ //taoj thong tin cho node
	Node *p = new Node;
	if(p == NULL) exit(1);
	p ->next = NULL;
	p->data = x;
	return p;
}
bool isEmpty(List l){ //kiem tra xem list co rong hay khong
	if(l.head == NULL) return true;
	return false;
}
//chen vao dau list;

void addHead(List &l, int x){
	Node *p = creatNode(x);
	if(isEmpty(l)) l.head = l.tail = p;
	else{
		p->next = l.head;// con tro next cua p tro toi dia chi cua node(ban dau
		l.head = p;// cap nhat nde head(luc sau)
	}
	l.tail->next =l.head; // khep vong don
}
//ham chon vao cuoi list
void addTail(List &l, int x){ 
	Node *p = creatNode(x);
	if(isEmpty(l)) addHead(l, x);
	else{
		l.tail ->next = p;
		l.tail = p;
	}
	l.tail ->next = l.head;// vong don
}

//tim kiem
Node *search(List l, int k){
	Node *p = l.head;
	do{
		if(p ->data == k) return p;
		else p = p -> next;
	}while(p!= l.head);
	return NULL;
}

void addMid(List &l, int x, int k){// cho node co data =x vao sau node co data = k;
	Node *p = search(l, k);
	if(p != NULL){
		Node *q = creatNode(x);
		Node *r = p->next;
		p->next = q;
		q->next = r;
	}
	else cout << "\nkhong tim thay node co data = k";
}

//void addAtk(List &l, int x, int k){ //chon vi tri node bat ki
//	if(isEmpty(l) || k <= 1) addHead(l, x);
//	else if(k >= n) addTail(l, k);
//	else {
//		Node *p = creatNode(x)
//		Node *q = new Node, *w = new Node;
//		Node *r = l.head;
//		int dem = 0;
//		while(e!= NULL){
//			dem++;
//			q = r;
//			if(dem == k) break;
//			else r = r->next;
//		}
//		w = l.head;
//		while(w -> next != q) w = w-> next;
//		w->next = p;
//		p -> next = r;
//	}
//}

void nhap(List &l){//nhap vao 1 list do dai n
	cout << "\nnhap so phan tu ban dau cua List: ";
	cin >> n;
	for( int i = 1; i <= n; i++) addTail(l,i);
}

void xuat(List l){// xuat thong tin danh sach ra mang hinh
	Node *p = l.head;
	do{
		cout << " "<<p->data;
		p = p->next;
	}while( p != l.head);
}

void delHead(List &l){// xoa node o dau list
	if(!isEmpty(l)){
		Node *p = l.head;
		l.head = l.head -> next;// cap nhat l.head
		delete p;//xoat bo node head ban dau
	}
	l.tail -> next = l.head; 
}


void delTail(List &l){
	if(!isEmpty(l)){
		Node *p = l.head;
		Node *q = new Node;
		while(p->next != l.tail) p = p->next; //tim Node trn truc Tail
		q = p;// gan node nay cho node q
		p = p->next; //p là node can xoa
		l.tail = q;// cap nhat l.tail
		l.tail -> next = NULL;// cap nhat node cho l.tail
		delete p;
	}
	l.tail -> next = l.head;
}

void delAtk(List &l, int k){
	if(k <= 1) delHead(l);
	else if( k >= n) delTail(l);
	else {
		int dem = 0;
		if(!isEmpty(l)){
			Node *p = l.head;
			Node *q = new Node;
			while ( p != NULL){// tim node thu k
				dem++;
				q = p;
				if(dem == k) break;// tim thay thi break
				else p = p->next; //k thi tim tiep
			}
			Node *r = l.head;
			while(r -> next != q) r = r->next; // tim node k - 1
			r -> next = q->next;// cho node next cuar node k - 1 tro toi node k + 1
			delete q;
		}
	}
}


void menu(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	int k, x, lc;
	do{
		printf("\n___________MENU___________\n1.chen dau.\n2.chen cuoi.\n3.chen sau vi tri node data = k.\n4.chen vao vi tri bat ki.\n5.xuat thong tin List.\n6.xoa phan tu dau List.\n7.xoa phan tu o cuoi list\n8.xoa node o vi tri k.\no.thoat.\n->ban chon: ");
		cin>> lc;
		switch(lc){
			case 0: break;
			case 1: cout << "\n nhap x:"; cin >> x; addHead(l, x); n++;break;
			case 2: cout << "\n nhap x:"; cin >> x; addTail(l, x);n++; break;
			case 3: cout << "\n nhap x, k:"; cin >> x >> k; addMid(l, x, k);n++;break;
			case 5: xuat(l);break;
			case 6:delHead(l);n--;break;
			case 7: cout << "\nnhap vi tri k: "; cin >> k; delAtk(l,k); n--; break;
		}		
	}while (lc != 0);
}

int main(){
	menu();
	return 0;
}
