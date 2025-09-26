#include<stdio.h>
int MIN(int a,int b){
  if(a<b){
  	return a;
  }
  else {
  	return b;
  }
}
int main(){
	int a,b;
	printf ("donner a et b :");
	scanf("%d %d",&a,&b);
	printf("le min %d et %d est %d",a,b,MIN(a,b));
	return 0;
}
