/* Author: Wang Minkai;  ID: 3220100975;  No.02 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int* element;
}HEAP;//struct of heap
typedef HEAP* hp;//heap_pointer



typedef struct{
	int array[100005];
	int size;
}STACK;//stuct of stack


int N,M;
int read[100005];//the input order
int counter;//the number of elements which have been dealt with.
int index;//the element to be dealt with.

hp heap_initialize(int x);
void PercolateUp( int p, hp H );
void PercolateDown( int p, hp H );
void insert( int X, hp H ) ;
int DeleteMin(hp H );
STACK * stack_initialize();
void push(int x,STACK* a);
int cmp(const void *a, const void *b);

int main(){
	
	scanf("%d %d",&N,&M);
	hp H=heap_initialize(M+5);
	STACK *now=stack_initialize();//the next array to be output 
	STACK *next=stack_initialize();//the next array of 'now'.
	//initialization
	for (int i=0;i<N;i++){
		scanf("%d",&read[i]);
	}							//read in all the data 
	for(int i=0;i<M;i++){
		insert(read[i],H);
	}//first m elements should all be added into the heap.

	counter=0;//the number of elements which have already been dealt with
	index=M;//the index of element to be judged(which means it hasn't been judged yet)
	
	while(counter<N){
		counter++;
		int min=DeleteMin(H);//pop the minimum		
		push(min,now);
		if(index<N){//still got elements to deal
			if(min<=read[index]){
				insert(read[index],H);//this one should eventually goes into 'now'
			}
			else{
				push(read[index],next);//this one goes into the next array
			}
			index++;
		}
		if(H->size==0){//there's no elements in the heap,which means all the element of 'now' has been added to it.
			qsort(now->array,now->size+1,sizeof(now->array[0]),cmp);
			//sort 'now' in increasing order.
			for(int i=0;i<=now->size;i++){
				if(i==now->size){
					printf("%d\n",now->array[i]);
					break;
				}
				printf("%d ",now->array[i]);
			}//output the array
			for(int i=0;i<=next->size;i++){
				insert(next->array[i],H);
			}//put all the elements in 'next' into the heap;
			now->size=-1;
			next->size=-1;//clear the 2 stacks.
		}
	}	
}


//-----------------------------------------------------heap operations
hp heap_initialize(int x){
	hp H=(hp)malloc(sizeof(HEAP));
	H->size=0;	
	H->element=(int *)malloc(sizeof(int)*(x));
	return H;
}//initialize a heap

void PercolateUp( int p, hp H ){
	int data=H->element[p];
	while(p>1){
		int parent=p/2;
		if(H->element[parent]<data)break;
		H->element[p]=H->element[parent];
		p=parent;
	}
	H->element[p]=data;
}//percolateup an element

void PercolateDown( int p, hp H ){
	int data=H->element[p];
	while(p*2<H->size){
		int child=p*2;
		if(child<H->size&&H->element[child]>H->element[child+1])child++;
		if(data<H->element[child])break;
		H->element[p]=H->element[child];
		p=child;
	}
	H->element[p]=data;
}//percolatedown an element

void insert( int X, hp H ) 
{
    int p = ++H->size;
    H->element[p] = X;
    PercolateUp( p, H );
}//insert a new element into the heap

int DeleteMin(hp H ) 
{ 
    int MinElement; 
    MinElement = H->element[1];
    H->element[1] = H->element[H->size--];
    PercolateDown( 1, H );
    return MinElement; 
}//pop the minimal element in the heap
//------------------------------------------------------------------------------

//--------------------------------------stack operations
STACK * stack_initialize(){
	STACK * p=(STACK *)malloc(sizeof(STACK));
	p->size=-1;
	return p;
}//initialize a stack

void push(int x,STACK* a){
	a->size++;
	a->array[a->size]=x;
}//push a new element into the stack

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}//used for quick_sort in increasing order
//------------------------------------------------------------------------------

