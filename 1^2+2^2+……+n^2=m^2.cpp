#include<stdio.h>
#include<math.h>

int main(){
	int i;
	int sum=0;

	for(i=1;;++i){
		sum+=i*i;
		int tmp=sqrt(sum);
		if(tmp*tmp==sum || (tmp+1)*(tmp+1)==sum){
			printf("find %d: %d\n",i,sum);
			scanf("%d",&tmp);   //to stop
		}
	}
}
