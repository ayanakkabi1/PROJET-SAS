#include<stdio.h>
int parite(int a){
	if(a%2==0){
		printf("le nombre es pair");
		return 1;
	}
	else{
		printf("le nombre est impair");
		return 0;
	}	
}
int main(){
	int a;
	printf("donner A:");
	scanf("%d",&a);
	parite(a);
}

