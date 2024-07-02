#include <stdio.h>
#include <limits.h>//to use infinity

#define MAX 1005

int graph[MAX][MAX];  //use a matrix to represent the graph
                      //graph[i][j] is the weight between vertice i and vertex j
int dis[MAX];   	  //use an array to record the distance from a vertex to others
int visit[MAX];       //use an array to record if every node is ever visited;
                	  //This array should be initializea again everytime we apply a new dijkastra
int temp[MAX];		  //The temporary sequence to be checked.

int V,E;			  //the number of vertexs and edges
	
void Creat_graph(int edge);
int dijkastra(int v);

int main(){	
	scanf("%d %d",&V,&E);
	Creat_graph(E);//creat the graph
	
	int K;//the number of queries
	scanf("%d",&K);
	for(int i=0;i<K;i++){	
		for(int j=0;j<V;j++){
			scanf("%d",temp+j);
		}//read in the sequence	  
		
		int flag=1;                   
		flag=dijkastra(temp[0]);	//calculate record[temp[0]]
		if(flag)printf("Yes\n");
		else printf("No\n");
	}

}



void Creat_graph(int edge){//This is the function to creat the graph.	
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++)
			graph[i][j]=INT_MAX;
	}//initialize the matrix
	 //the initial distance between any vertices is infinity.
		
	for(int i=0;i<edge;i++){
		int v1,v2,weight;
		scanf("%d %d %d",&v1,&v2,&weight);//Read in the weight of each edge.
		graph[v1][v2]=weight;
		graph[v2][v1]=weight;
	}
}


int dijkastra(int v){
	
	for(int i=0;i<MAX;i++){
		dis[i]=INT_MAX;
		visit[i]=0;//clear array 'visit' and 'dis' everytime dijkastra is applied
	}//initialization
	dis[v]=0;//the distance to itself is 0.
	
				
	for(int i=0;i<V;i++){//dijkastra is a algorithm which loops for V times
		int min=INT_MAX, tempmin=-1;//min is the minimal distnce;
		                            //tempmin is the index of the vertex to be added.
    	for(int j=1;j<=V;j++){
    		if(visit[j]==0 && dis[j]<min){
    			tempmin=j;
    			min=dis[j];
			}
		}
		
	    if(dis[tempmin]!=dis[temp[i]])return 0;		
		
		visit[tempmin]=1;//this vertex has been visited;
		for(int j=1;j<=V;j++){
			if(visit[j]==0 && graph[tempmin][j]!=INT_MAX && 
			dis[tempmin]+graph[tempmin][j]<dis[j])
				dis[j]=dis[tempmin]+graph[tempmin][j];
		}
	}
	return 1;
}










