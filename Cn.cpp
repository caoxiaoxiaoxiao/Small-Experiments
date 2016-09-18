#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int cn[N+1]N+1];
	int* p[N+1][N+1];
	int *list;

	//init
	for(int i=1;i<=N;++i){
		cn[1][i]=1;
		list=(int *)malloc(sizeof(int));
		p[1][i]=list;
		*list=i;

		cn[i][i]=1;
		list=(int *)malloc(i*sizeof(int));
		p[i][i]=list;
		for(int ii=0;ii<i;++ii)
			*(list++)=1;	
	}

	//calculate
	for(int sum=3;sum<=N;++sum)
		for(int heap=2;heap<sum;++heap){

			int size=0;
			int min=heap<sum-heap?heap:sum-heap;
			for(int i=1;i<=min;++i)
				size+=cn[i][sum-heap];

			//copy from previous
			list=(int *)malloc(size*sizeof(int));
			memset(list,0,size*sizeof(int));
			p[heap][sum]=list;
			int j=0;
			for(int i=1;i<=min;++i)
				for(int ii=0;ii<cn[i][sum-heap];++ii,++j)
					memcpy(list+j*heap,p[i][sum-heap]+ii*i,i);
			//add 1
			for(int i=0;i<size;++i)
				(*p[heap][sum])++;
		}
			
	//print
	for(int i=1;i<=N;++i){//heap
		printf("heap=%d\n",i);

		for(int j=0;j<cn[i][N];++j){//cn
			for(int k=0;k<i;++k)//one solution
				printf("%d ",*(p[i][N]+j*i+k));
			printf("\n");
		}
	}

	return 0;
}
