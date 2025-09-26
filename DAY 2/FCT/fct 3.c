#include<stdio.h>
int MAX(int a,int b){
  if(a<b){
  	return b;
  }
  else {
  	return a;
  }
}
int main(){
	int a,b;
	printf ("donner a et b :");
	scanf("%d %d",&a,&b);
	printf("le max %d et %d est %d",a,b,MAX(a,b));
	return 0;
}
