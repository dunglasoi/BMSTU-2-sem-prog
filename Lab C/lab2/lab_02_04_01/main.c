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

#define OK_100 100 /** специальный код ошибки */

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
        case OK:
            break;
        case OK_100:
            err = OK;
            break;
        default:
            printf("Error: Неизвестный код!\n");
            break;
    }

    return err;
}

/**
 * @brief Ввод элемент массива
 *
 */
int input_array(int *a, size_t *n)
{
    printf("Input array element:\n");

    printf("a[%d]: ", 0);
    if (scanf("%d", a) != 1)
        return ERR_IO;

    *n = 1;
    while (*n <= N_MAX + 1)
    {
        if (*n > N_MAX)
        {
            *n = N_MAX;
            return OK_100;
        }
        printf("a[%zu]: ", *n);
        if (scanf("%d", a + *n) != 1)
            return OK;
        (*n)++;
    }

    return OK;
}

/**
 * @brief Вывод элемент массива
 *
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
 * @brief Вставить элемент в отсортированном массиве
 *
 * Передвигаем элементы больше key на одну позицию вправо.
 * Вставляем key в освободившее место слева.
 *
 * @param key Элемент, который нужно вставить
 * @param a Отсортированный массив
 * @param n До n-ого элемента массив отсортирован
 * @return int
 */
int insert_into_sorted_array(int key, int *a, size_t *n)
{
    int j = *n - 1;
    while (j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j -= 1;
    }
    a[j + 1] = key;
    (*n)++;

    return OK;
}

/**
 * @brief Сортировка вставками
 *
 */
int insertion_sort(int *a, size_t n)
{
    size_t i = 1;
    while (i < n)
    {
        insert_into_sorted_array(a[i], a, &i);
    }

    return OK;
}

int main(void)
{
    int ret = OK;
    size_t size = 0;
    int a[N_MAX + 1];

    ret = input_array(a, &size);
    if (iserror(ret))
        return ret;

    insertion_sort(a, size);

    output_array(a, size);

    return ret;
}
