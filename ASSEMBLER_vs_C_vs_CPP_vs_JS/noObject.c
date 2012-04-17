// #include<string.h>
#include<stdio.h>



compare(int a, int b){

	if(a>b){return a;}else{return b;}
}

int main(void)
{
	char name[11] = "Hello World";
	int a = 23,b = 5;
	printf("The Object named: %s\nCompared: %d with %d.\n%d is bigger!\n",name,a,b,compare(a,b));

	return 0;
}