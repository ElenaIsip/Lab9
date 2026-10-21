#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Russian");

    printf("=== ЗАДАНИЕ 1: Таблица Пифагора (полная) ===\n");


    printf("    ");
    for (int j = 1; j <= 9; j++) {
        printf("%4d", j);
    }
    printf("\n");

    for (int j = 0; j <= 9; j++) {
        printf("----");
    }
    printf("\n");

   
    for (int i = 1; i <= 9; i++) {
        printf("%3d|", i); 
        for (int j = 1; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    printf("\n\n");


    printf("=== ЗАДАНИЕ 2: Левый нижний треугольник ===\n");

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    printf("\n\n");

    printf("=== ЗАДАНИЕ 3: Треугольник из единиц ===\n");

    for (int i = 5; i >= 1; i--) {   
        for (int j = 1; j <= i; j++) { 
            printf("1 ");
        }
        printf("\n");
    }


    return 0;

}