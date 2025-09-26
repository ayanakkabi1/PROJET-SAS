#include<stdio.h>
int multipl(int a,int b){
	return a*b;
}
int main(){
	int a,b;
	printf("donner a et b :");
	scanf("%d %d",&a,&b);
	printf(" %d * %d = %d",a,b,multipl(a,b));
	return 0;
}

