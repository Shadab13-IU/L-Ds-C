typedef struct node* t;
typedef struct node{
	int data;
	t next;
}node;
t create(int);
void traverse(t);
void insert(t**,int,int);
void deletenode(t**,int);
