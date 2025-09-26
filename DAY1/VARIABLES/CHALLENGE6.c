#include <stdio.h>

int main() {
    float a,b,A,s,m,d;

    printf("Donner la valeur a: ");
    scanf("%f", &a);
    printf("Donner la valeur b: ");
    scanf("%f", &b);
    A=a+b;
    s=a-b;
    m=a*b;
    d=a/b;
    printf("a + b=%f\na-b=%f\na x b=%f\na /b=%f",A,s,m,d);
    return 0;
}
