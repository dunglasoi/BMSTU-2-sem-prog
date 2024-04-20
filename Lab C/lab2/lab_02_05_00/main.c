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
        case ERR_UNDEF:
            printf("Error: Неопределенное поведение\n");
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
int input_array(int *pa, int *pb)
{
    printf("Input array element:\n");
    for (int *i = pa; i < pb; i++)
    {
        if (scanf("%d", i) != 1)
            return ERR_IO;
    }
    return OK;
}

/**
 * @brief Делать задание
 *
 */
int do_task(const int *pa, const int *pb, int *max)
{
    pb--;
    *max = *pa + *pb;
    pa++;
    pb--;

    int tmp;
    while (pa <= pb)
    {
        tmp = *pa + *pb;
        if (tmp > *max)
            *max = tmp;
        pa++;
        pb--;
    }

    return OK;
}

int main(void)
{
    int ret = OK;
    size_t size = 0;
    int a[N_MAX];
    int max;

    ret = input_number_of_element(&size);
    if (iserror(ret))
        return ret;
    if (size == 1)
    {
        ret = ERR_UNDEF;
        iserror(ret);
        return ret;
    }

    int *pa = a, *pb = pa + size;

    ret = input_array(pa, pb);
    if (iserror(ret))
        return ret;

    ret = do_task(pa, pb, &max);
    if (iserror(ret))
        return ret;

    printf("Max: %d\n", max);

    return ret;
}
