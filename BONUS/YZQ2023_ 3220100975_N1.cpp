/* Author: Wang Minkai;  ID: 3220100975;  No.01 */
#include <stdio.h>
#include <stdlib.h>

void IN(int n);
void OUT();

int p1[1005],p2[1005];
int *s1=p1,*s2=p2;

int main(){
	int n,len1,len2;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++){	
		char op;
		op=getchar();
		if(op=='I'){
			int data;
			getchar();
			scanf("%d",&data);	
			IN(data);
			getchar();		
		}
		else{
			OUT();
			getchar();
		} 
	}
}

void IN(int n){
	s1++;
	*s1=n;
/*	int * p0=p1;
	while(p0!=s1){
		p0++;
		printf("%d ",*p0);
	}
	printf("\n");*/
}

void OUT(){
	int t=0;												//record the time of dequeue
	if(s2==p2){												//st2 is empty
		if (s1==p1){										//st1 is also empty => error
			printf("ERROR\n");
			return;
		}
		while(1){											//pop everything from st1 and push into st2
			int temp;
															//temp used for the storage of data in st1;
			temp=*s1;
			s1--;											//st1 pop;
			
			s2++;
			*s2=temp;											//s2 push;
			
			t+=2;											//every pop and push takes 1 unit
			if(s1==p1)break;
		}
		printf ("%d %d\n",*s2,t+1);
		s2--;
	}
	else{
		printf ("%d 1\n",*s2);
		s2--;
	}
}




















