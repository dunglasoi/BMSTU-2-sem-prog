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
 * @brief Делать задание
 *
 */
int do_task(const int *a, size_t n, int *prod)
{
    int n_odd = 0;
    *prod = 1;

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            n_odd++;
            *prod *= a[i];
        }
    }

    if (n_odd == 0)
        return ERR_NO_ELEMENT;

    return OK;
}

int main(void)
{
    int ret = OK;
    size_t size = 0;
    int a[N_MAX];
    int prod = 1;

    ret = input_number_of_element(&size);
    if (iserror(ret))
        return ret;

    ret = input_array(a, size);
    if (iserror(ret))
        return ret;

    ret = do_task(a, size, &prod);
    if (iserror(ret))
        return ret;

    printf("Product: %d\n", prod);

    return ret;
}
