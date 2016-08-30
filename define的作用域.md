
这种情况下，只打印一个D1
```
#include<stdio.h>
void fun();


void fun(){
	
#ifdef D1
	printf("D1\n");
#endif

}

int main(){

#ifdef D
	printf("D\n");
	printf("D\n");
#endif


#define D
#define D1
#ifdef D1
	printf("D1\n");
#endif

	fun();
	return 0;
}
```


在这种情况下，打印2个D1
```
#include<stdio.h>
void fun();



int main(){

#ifdef D
	printf("D\n");
	printf("D\n");
#endif


#define D
#define D1
#ifdef D1
	printf("D1\n");
#endif

	fun();
	return 0;
}

void fun(){
	
#ifdef D1
	printf("D1\n");
#endif

}
```

由此，我们可以知道宏定义的作用域：首先是在一个文件内，然后是从定义（可以在全局定义也可以在局部定义）之后的所有部分 <br />
可以看出，C严格依赖于代码的书写位置
