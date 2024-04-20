#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdio.h>

/**
 * @brief Записать n случайные числа в файл
 *
 * @param [in] f Файловая переменная
 * @param [in] number N чисел
 */
int process_c(FILE *f, char *number);

/**
 * @brief Печатать содержимое файла на экран
 *
 * @param [in] f Файловая переменная
 */
int process_p(FILE *f);

/**
 * @brief Сортировать числа в файле
 *
 * @param [in] f Файловая переменная
 */
int process_s(FILE *f);

/**
 * @brief Конвертировать текстовый файл со структурой student_t в бинарный
 *
 * @param [in] file_txt Имя файл текстовый
 * @param [out] file_bin Имя файл бинарный
 */
int process_t2b(char *file_txt, char *file_bin);

/**
 * @brief Конвертировать бинарный файл со структурой student_t в текстовый
 *
 * @param [in] file_bin Имя файл бинарный
 * @param [out] file_txt Имя файл текстовый
 */
int process_b2t(char *file_bin, char *file_txt);

#endif
