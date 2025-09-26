#include <stdio.h>

int main() {
    float T;

    printf("Donner la temperature en Celsius: ");
    scanf("%f", &T);

    if (T < 0) {
        printf("SOLIDE\n");
    }
    else if (T >= 0 && T <= 100) {
        printf("LIQUIDE\n");
    }
    else {
        printf("GAZ\n");
    }

    return 0;
}

