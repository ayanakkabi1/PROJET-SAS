#include<stdio.h>
int somme(int a,int b){
	return a+b;
}
int main(){
	int a,b;
	printf("donner a et b :");
	scanf("%d %d",&a,&b);
	printf(" %d+%d=%d",a,b,somme(a,b));
	return 0;
}

