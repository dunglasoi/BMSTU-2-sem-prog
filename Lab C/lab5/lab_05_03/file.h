#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>

/**
 * @brief Записать n случайные числа в файл
 * 
 * @param [in] f Файловая переменная
 * @param [in] number N чисел
 */
int write_file(FILE *f, char *number);

/**
 * @brief Печатать содержимое файла в другой файл
 * 
 * @param [in] f Файловая переменная
 * @param [out] f_out Куда печатаем
 */
int output_file(FILE *f, FILE *f_out);

/**
 * @brief Сортировать числа в файле
 * 
 * @param [in] f Файловая переменная
 */
int sort_file(FILE *f);

/**
 * @brief Подсчитать размер файла
 *
 * @param [in] f Файловая переменная
 * @param [out] size Размер файла
 */
int get_file_size(FILE *f, size_t *size);

#endif // _FILE_H_
