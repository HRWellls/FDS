#include <stdio.h>
#include <time.h>   
clock_t start,stop;  //both start and stop are used to control the clock 
double tick,duration,totaltime; //3 variables are used to record time
#define K 20000000   //different situations have different k
                     //k is used to expend the time of each algorithm when it takes too less time

double AL1 (double x,int n);
double AL2 (double x,int n);	//recursive version
double AL3 (double x,int n);	//iterative version


int main() {
	double x,a;	//a records the result of calculation
	int n;
	scanf("%lf %d",&x,&n);	//read in x as base and read in n as index

	start = clock() ;	//start recording the time
	for(int i=0;i<K;i++){
		a=AL1(x,n);	
	}                	//do algorithm1 for k times
	stop  = clock() ;	//stop recording the time
	tick=(double)(stop-start);	//data type conversion
	totaltime=tick/CLK_TCK;		//the whole time needed for using this algorithm for K times
	duration=totaltime/K;	//the time  needed for using this algorithm  to get the result
	printf("%lf %lf %lf %lf\n",a,tick,totaltime,duration);	//print all the datas we get

	start = clock() ;
	for(int i=0;i<K;i++){
		a=AL2(x,n);	
	}
	stop  = clock() ;
	tick=(double)(stop-start);
	totaltime=tick/CLK_TCK;
	duration=totaltime/K;
	printf("%lf %lf %lf %lf\n",a,tick,totaltime,duration);

	start = clock() ;
	for(int i=0;i<K;i++){
		a=AL3(x,n);	
	}
	stop  = clock() ;
	tick=(double)(stop-start);
	totaltime=tick/CLK_TCK;
	duration=totaltime/K;
	printf("%lf %lf %lf %.10lf\n",a,tick,totaltime,duration);
	//the duration of this algorithm is so short that we need to 
	//keep 10 places after the decimal point,in order to keep accuracy.	                                            
}

double AL1 (double x,int n) {
	double a=1.0;				//a is used to record the answer of x**n
	for(int i=0; i<n; i++) {	
		a*=x;
	}                           // x**n equals to 1 multiples x for n times
	return a;
}
double AL2 (double x,int n) {
	if(n==1)return x;			//if n==1,it means x itself.So return x
	else if(n%2==0)return AL2(x,n/2)*AL2(x,n/2);//if n is an even number,then x**n can be seen 
	                                            //as the multiple result of x**(n/2) and x**(n/2).
	else return AL2(x,n/2)*AL2(x,n/2)*x;//if n is odd even number,then x**n can be seen 
	                                    //as the multiple result of x**(n/2) , x**(n/2) and x.
}
double AL3 (double x,int n) {
	int p[100]= {0},i=0;            //open a new array to record the quality of n,
	                                //which is analysed in AL2.That is n can be factorized in 2 ways 
	while (n) {						//We continue the factorization of n until it's 0
		if(n%2==0)    p[i++]=1;		//If n is even,we record the result of array as 1;
		else    i++;				//If n is odd,we record the result of array as 0;
		n/=2;						//in every loop n cuts in half
	}
	double a=1;
	i--;							//make i the subsciption of the last valid data
	while(i>=0) {                   //the loop goes on until all the valid data in array is used
		if(p[i])a*=a;				//if p[i]==1,it means during this factorization,n is even.
									//That means the multiple result of x**(n/2) and x**(n/2) is x**n
		else a=a*a*x;				//if p[i]==0,it means during this factorization,n is odd.
									//That means the multiple result of x**(n/2),x**(n/2) and x is x**n
		i--;
	}
	return a;
}