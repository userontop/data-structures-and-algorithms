void delete_all_list(list L){
	Position P = L -> next;
	While(P != NULL){
		tmp = P ->;
		P = tmp->next;
		free(tmp);
	}
	free(P->next);
	free(P);
}


Position Headder(list L){
	Position P = L;	
	return P;
}


position first(list l){
	position p = l -> next;
	return p;
}


position advance(position p){
	return p -> next;
}


ElementType retrieve(position p){
	return p -> Element;
}


void read_list(list l){
	int n;
	scanf("%d", &n);
	Position P = l -> next;
	for(int Position p = l->next; p < n; p = p -> next){
		printf("%2d", p -> Element);
	}
}

void xuat(Elementype X, List L){
	Position P = L -> next;
	for(int Position P = L->next; P != NULL; P = P -> next){
		Printf("%d", P-> Elementype)
	}
}

























