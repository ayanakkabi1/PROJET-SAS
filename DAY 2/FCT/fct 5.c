#include<stdio.h>
int FACTORIELLE(int x){
  int p=1;
  if(x!= 0){
  for(int i=1;i <= x;i++){
  p = p * i;
  }
  return p;
  }
  else {
  	return 1;
  }
}
int main(){
	int x;
	printf ("merci de donner l'entier :");
	scanf("%d",&x);
	printf("le factorielle de %d  est %d",x,FACTORIELLE(x));
	return 0;
}
