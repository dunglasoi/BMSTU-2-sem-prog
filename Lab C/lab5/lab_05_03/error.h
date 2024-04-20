#ifndef _ERROR_H_
#define _ERROR_H_

#include <errno.h>

/** Коды возврата */
#define OK 0                 /** Все хорошо */
#define ERR_READ -1          /** ошибка: Чтение файла */
#define ERR_WRITE -2         /** ошибка: Запись в файл */
#define ERR_SEEK -4          /** ошибка: Установка позиции в потоке данных */
#define ERR_GET_FILE_SIZE -3 /** ошибка: Определение размер файла */
#define ERR_USAGE 53         /** ошибка: Использование */
#define ERR_RANGE -16        /** ошибка: Значение вне допустимого диапазона */
#define ERR_EMPTY -17        /** ошибка: Нет цифры в файле */
#define ERR_FILE -18         /** ошибка: Файл поврежден */

/**
 * @brief Вывод описание ошибок
 */
void print_error(int err);

#endif // _ERROR_H_
