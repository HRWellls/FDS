#include <stdio.h>
#include <stdlib.h>

typedef struct {				//definition of node
	int data;
	struct node* left;
	struct node* right;
}node;

node* root=NULL;

int abs(int x);
node* buildtree(int x);
node* plus(node* root,int newdata);
int check(node* root);
int check1(node* root);
int check2(node* root,int number);
//void print(node* root);
int checker;//used to check the number of black node in function 'check2'
int number;

int main(){
	int x;					//x is the number of trees to be judged
	scanf("%d",&x);
	for (int i=0;i<x;i++){  //judge x times
		scanf("%d",&number);//'number' is the number of nodes in this tree
		int flag;			//flag=1 -> is a red-black tree
		checker=0;
		
		node* root;
		root=buildtree(number);//the entire tree has been constructed
		

		if(root->data<0){
			printf("No\n");
			continue;
		}//if the root is red -> not a red-black tree
		
		flag=check(root);//if is,flag=1;else flag=0.
		
		if(flag){
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}


int abs(int x){			//The function to fetch the absolute value of nodes
	if (x<0) x=-x;
	return x;
}


node* buildtree(int x){//The function to build a tree with x nodes
	
	node* root=NULL;//construction of root
	
	for(int i=0;i<x;i++){		
		int newdata;
		scanf("%d",&newdata);
		root=plus(root,newdata);			
	}//build others
	
	return root;
}


node* plus(node* tree,int newdata){//The function to add a node into the tree
	if(tree==NULL){
		node* newnode=(node*)malloc(sizeof(node));
		newnode->data=newdata;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}//the construction of a new node
	else{
		if( abs(tree->data) > abs(newdata) ){
			tree->left=plus(tree->left,newdata);
		}
		else{
			tree->right=plus(tree->right,newdata);
		}
	}//determine the direction of insertion
	return tree;
}


int check(node* root){//Check if it's a red-black tree,whose root has already been checked before.
	int result1=0,result2=0;
	
	result1 = check1(root);
	if(!result1) return 0;//check if there are 2 continuous red nodes.
	
	
	checker=0;
	number=0;
	node* _root=root;
	while(_root){
		if(_root->data>0)checker++;
		_root=_root->left;
	}
	result2 = check2(root,number);
	if(!result2) return 0;//check if the number of black nodes are the same
	
	return 1;
}

int check1(node* root){//check if there are 2 continuous red nodes.
	if(!root)return 1;//leaves
	
	if(root->data<0){
		node* L =root->left;
		node* R =root->right;
		if((L&&L->data<0)||(R&&R->data<0)) return 0;
	}//if it's a red node,then check if its children are red

	return (check1(root->left) && check1(root->right));//check both its children
}



int check2(node* root,int number){//check if the number of black nodes are the same
	//If the number of black nodes in every path from root to leaves are the same,
	//then the number of black nodes is always the same in every path from a specific node to leaves
	if(!root)return 1;
	if(root->data>0)number++;
	if((!root->left)&&(!root->right)){
		if(number==checker)return 1;
		return 0;
	}
	return ( check2(root->left,number) && check2(root->right,number) );
}

/*
void print(node* root){
	if(!root)return;
	printf("%d ",root->data);
	print(root->left);
	print(root->right);
}
*/


		
		


