#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>



int main() {
    setlocale(LC_ALL, "Russian");

    char number[10001];
    char again;

    do {
        printf("Введите целое число: ");
        scanf("%10000s", number);

        int len = strlen(number);
        int count3 = 0;
        int lastDigit = number[len - 1] - '0';
        int lastDigitCount = 0;
        int evenCount = 0;
        int greaterThan5 = 0;
        int oddSum = 0;
        int sumAtLeast7 = 0;
        unsigned long long nonzeroProduct = 1;
        int adjacentEqual = 0;
        int evenSumExceptLast = 0;
        int evenPositionSum = 0;
        int oddPositionSum = 0;

        for (int i = 0; i < len; i++) {
            int digit = number[i] - '0';
            int positionFromRight = len - i;

            if (digit == 3)
                count3++;

            if (digit == lastDigit)
                lastDigitCount++;

            if (digit % 2 == 0)
                evenCount++;

            if (digit > 5)
                greaterThan5++;

            if (digit % 2 != 0)
                oddSum += digit;

            if (digit >= 7)
                sumAtLeast7 += digit;

            if (digit != 0)
                nonzeroProduct *= digit;

            if (i > 0 && number[i] == number[i - 1])
                adjacentEqual = 1;

            if (i < len - 1 && digit % 2 == 0)
                evenSumExceptLast += digit;

            if (positionFromRight % 2 == 0)
                evenPositionSum += digit;
            else
                oddPositionSum += digit;
        }

        printf("\n1) Цифр 3: %d\n", count3);
        printf("2) Повторений последней цифры: %d\n", lastDigitCount);
        printf("3) Четных цифр: %d\n", evenCount);
        printf("4) Цифр больше 5: %d\n", greaterThan5);
        printf("5) Сумма нечетных цифр: %d\n", oddSum);
        printf("6) Сумма цифр >= 7: %d\n", sumAtLeast7);
        printf("7) Произведение цифр, исключая 0: %llu\n", nonzeroProduct);
        printf("8) Произведение предпоследней и второй цифр: %d\n",
            (number[len - 2] - '0') * (number[1] - '0'));
        printf("9) Сумма четных цифр, исключая последнюю: %d\n",
            evenSumExceptLast);
        printf("10) Есть соседние одинаковые цифры: %s\n",
            adjacentEqual ? "да" : "нет");

        int half = len / 2;
        int firstHalfSum = 0;
        int secondHalfSum = 0;

        for (int i = 0; i < half; i++)
            firstHalfSum += number[i] - '0';

        for (int i = half; i < len; i++)
            secondHalfSum += number[i] - '0';

        printf("11) Суммы половин равны: %s\n",
            firstHalfSum == secondHalfSum ? "да" : "нет");

        printf("12) Произведение сумм цифр четных и нечетных разрядов: %d\n",
            evenPositionSum * oddPositionSum);

        printf("\nПродолжить? (y/n): ");
        scanf(" %c", &again);

    } while (again != 'n' && again != 'N');

    return 0;
}