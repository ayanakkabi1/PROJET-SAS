#include <stdio.h>
#include <string.h>

char* inverse(char T[]) {
    int n = strlen(T);
    char m;
    for (int i = 0; i <(n-1)/2; i++) { 
        m=T[i];
        T[i]=T[n-i-1];
        T[n-i-1]=m;
    }
    return (T);
}
int main() {
	int n;
    char T[n];
    printf("entrer une chaine :");
    scanf("%[^%\n]",&T[n]);
    printf("%s",inverse(T));
    return 0;
}
