#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>



int main() {
    setlocale(LC_ALL, "Russian");

    int R, a;
    char symbol;

    printf("Введите радиус R: ");
    if (scanf("%d", &R) != 1 || R <= 0) return 1;

    printf("Введите параметр a: ");
    if (scanf("%d", &a) != 1 || a <= 0 || a >= R) return 1;

    while (getchar() != '\n');

    printf("Введите символ: ");
    scanf("%c", &symbol);

    int width = 2 * R + 4;
    int height = 2 * R + 4;

    printf("\n");

    for (int y = -R - 2; y <= R + 2; y++) {
        for (int x = -R - 2; x <= R + 2; x++) {
            double real_y = y / 2.2;

            double dist_to_center = sqrt(x * x + real_y * real_y);
            int is_circle = (dist_to_center >= R - 0.5 && dist_to_center <= R + 0.5);

            int is_deltoid_edge = 0;
            double tx = R - a;
            double ty = sqrt(R * R - a * a);

            if (x >= tx && x <= R) {
                double k = ty / (tx - R);
                double line_y = k * (x - R);
                if (fabs(real_y - line_y) < 0.6 || fabs(real_y + line_y) < 0.6) {
                    is_deltoid_edge = 1;
                }
            }

            if (x >= -R && x <= tx) {
                double k2 = ty / (tx + R);
                double line_y = k2 * (x + R);
                if (fabs(real_y - line_y) < 0.6 || fabs(real_y + line_y) < 0.6) {
                    is_deltoid_edge = 1;
                }
            }

            if (is_deltoid_edge) {
                putchar(symbol);
            }
            else if (is_circle) {
                putchar('.');
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}

 