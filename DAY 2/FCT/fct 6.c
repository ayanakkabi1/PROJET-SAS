#include<stdio.h>
int FIB(int a){
 int t[a+1];
 t[0]=0;
 t[1]=1;
 for(int i=2;i<=a;i++){
 	t[i]=t[i-1]+t[i-2];
 }
 return t[a];	
}
int main(){
	int a;
	printf("donner a : ");
	scanf("%d",&a);
	printf("le terme est :%d",FIB(a));
	return 0;
}
