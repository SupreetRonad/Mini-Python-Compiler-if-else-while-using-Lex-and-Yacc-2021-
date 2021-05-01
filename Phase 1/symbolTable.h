struct symbolTable{

	int declared;
	struct symbolTable *next; 
	char *d;
	
};

struct symbolTable id={0}, value={0} ;

void into_table(char *d, int flag){
	struct symbolTable *a,*b;
	
	if(flag==0)
		a=&id;
	else
		a=&value; 
	
	while(a->next!=NULL){
		a=a->next;
	}
	
	b = malloc(sizeof(struct symbolTable)); 
	b->next = NULL;
	b->d = strdup(d);
	b->declared = line_no;
	a->next = b;
}

int check_table(char *d){
	struct symbolTable *a;
	a=&id;
	
	while(a->next!=NULL){
		if(strcmp(d,a->next->d)==0 ){
			return 1;
		}
		
		a=a->next;	
	}
	
	return 0;
}

void Table(){
	struct symbolTable *a;
	a=&id;
	printf("\n############################################################\n");
	printf("\n-- IDENTIFIERS --\n");
	printf("---------------------------------\n");
	printf("NAME \t DECLARED LINE \n");
	printf("---------------------------------\n");
	
	while(a->next!=NULL){
		printf("%s \t %d \n", a->next->d, a->next->declared);
		a=a->next;
	}
	
	printf("---------------------------------\n");
	
	a=&value;
	printf("\n-- VALUES --\n");
	while(a->next!=NULL){
		printf("%s ", a->next->d);
		a=a->next;
	}
	printf("\n");
}




