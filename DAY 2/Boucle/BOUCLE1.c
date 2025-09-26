#include<stdio.h>
#include<ctype.h>

int main(){
	int a,i;
	printf("Merci de donner une valeur:");
	scanf("%d",&a);
	for(i=10; i>=1 ; i--){
		printf("%d * %d = %d\n",a,i,a*i);
	}
	return 0;
}
