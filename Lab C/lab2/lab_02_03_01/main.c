#include <stdio.h>
#include <stdlib.h>

/** Коды возврата */
#define OK 0             /** Все хорошо */
#define ERR_IO 1         /** ошибка: Ввод/Вывод */
#define ERR_RANGE 2      /** ошибка: Значение вне допустимого диапазона */
#define ERR_UNDEF 3      /** ошибка: Неопределенное поведение */
#define ERR_NO_ELEMENT 4 /** ошибка: Таких элементов нет */
#define ERR_OVERFLOW 5   /** ошибка: Переполнение */
#define ERR_IDX_OUT 6    /** ошибка: Индекс массив вне диапазона */

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
 * @brief Найти число Фибоначчи
 */
int fibonacci(int *fib, int n)
{
    if (n == 0 || n == 1)
    {
        (*fib) = n;
        return OK;
    }

    int fib0 = 0, fib1 = 1;
    int tmp;

    while (n-- > 1)
    {
        tmp = fib1;
        fib1 += fib0;
        fib0 = tmp;
    }

    if (fib1 < 0)
        return ERR_UNDEF;

    *fib = fib1;

    return OK;
}

/**
 * @brief Вставка элемент в массив
 */
int insert_array(int value, size_t idx, int *a, size_t *n)
{
    (*n) += 1;
    // if (*n > N_MAX)
    //     return ERR_IDX_OUT;

    if (idx >= *n)
        return ERR_IDX_OUT;

    for (size_t i = *n - 1; i > idx; i--)
        a[i] = a[i - 1];
    a[idx] = value;

    return OK;
}

/**
 * @brief Делать задание
 *
 */
int do_task(int *a, size_t *size)
{
    int fib, n = 0;
    int ret;

    size_t i = 0;
    while (i < *size)
    {
        if (a[i] % 3 == 0)
        {
            ret = fibonacci(&fib, n++);
            if (iserror(ret))
                return ret;
            ret = insert_array(fib, i + 1, a, size);
            if (iserror(ret))
                return ret;
            i++;
        }
        i++;
    }

    return OK;
}

int main(void)
{
    int ret = OK;
    size_t size = 0;
    int a[N_MAX * 2];

    ret = input_number_of_element(&size);
    if (iserror(ret))
        return ret;

    ret = input_array(a, size);
    if (iserror(ret))
        return ret;

    ret = do_task(a, &size);
    if (iserror(ret))
        return ret;

    ret = output_array(a, size);
    if (iserror(ret))
        return ret;

    return ret;
}
