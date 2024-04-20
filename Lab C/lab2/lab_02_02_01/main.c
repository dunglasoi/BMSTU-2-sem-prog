#include <stdio.h>
#include <stdlib.h>

/** Коды возврата */
#define OK 0             /** Все хорошо */
#define ERR_IO 1         /** ошибка: Ввод/Вывод */
#define ERR_RANGE 2      /** ошибка: Значение вне допустимого диапазона */
#define ERR_UNDEF 3      /** ошибка: Неопределенное поведение */
#define ERR_NO_ELEMENT 4 /** ошибка: Таких элементов нет */

#define N_MAX 10 /** Максимальное количество элементов, \
                     которое может ввести пользователь */

/**
 * @brief Вывод описание ошибок
 */
int iserror(int err)
{
    switch (err)
    {
        case ERR_IO:
            printf("Error: Ввод/Вывод\n");
            break;
        case ERR_RANGE:
            printf("Error: Значение вне допустимого диапазона\n");
            break;
        case ERR_NO_ELEMENT:
            printf("Error: Таких элементов нет\n");
            break;
        case OK:
            break;
        default:
            printf("Error: Неизвестный код!\n");
            break;
    }

    return err;
}

/**
 * @brief Ввод количество элементов массива
 */
int input_number_of_element(size_t *num)
{
    printf("Input number of element: ");
    if (scanf("%zu", num) != 1)
        return ERR_IO;
    if (*num <= 0 || *num > N_MAX)
        return ERR_RANGE;
    return OK;
}

/**
 * @brief Ввод элемент массива
 */
int input_array(int *a, size_t n)
{
    printf("Input array element:\n");
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", a + i) != 1)
            return ERR_IO;
    }
    return OK;
}

/**
 * @brief Вывод элемент массива
 */
int output_array(const int *a, size_t n)
{
    printf("Array element:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return OK;
}

/**
 * @brief Проверка на простое число
 *
 * @return int 0: простое; 1: не простое
 */
int is_prime(int n)
{
    if (n == 2 || n == 3)
        return 0;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return 1;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 1;
    }

    return 0;
}

/**
 * @brief Делать задание
 */
int do_task(const int *a, size_t n_a, int *b, size_t *n_b)
{
    *n_b = 0;

    for (size_t i = 0; i < n_a; i++)
    {
        if (!is_prime(a[i]))
        {
            b[*n_b] = a[i];
            (*n_b)++;
        }
    }

    if (*n_b == 0)
        return ERR_NO_ELEMENT;

    return OK;
}

int main(void)
{
    int ret = OK;
    size_t a_size = 0;
    int a[N_MAX];
    size_t b_size = 0;
    int b[N_MAX];

    ret = input_number_of_element(&a_size);
    if (iserror(ret))
        return ret;

    ret = input_array(a, a_size);
    if (iserror(ret))
        return ret;

    ret = do_task(a, a_size, b, &b_size);
    if (iserror(ret))
        return ret;

    ret = output_array(b, b_size);
    if (iserror(ret))
        return ret;

    return ret;
}
