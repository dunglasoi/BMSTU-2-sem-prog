# Тесты для лабораторной работы № 04, Задание № 04

## Входные данные

Строка

## Выходные данные

YES/NO

## Позитивные тесты

- 01 - Есть вещественное число, но после другие слова.          - NO
- 02 - Нет вещественное число.                                  - NO
- 03 - Нет слово.                                               - NO
- 04 - Пробелы в начале и в конце.                              - YES
- 05 - Вещественное число в подстроке.                          - NO
- 29 - Пустая строка.                                           - NO

- 06 - Одна цифра.                                      0       - YES
- 07 - Цифра с точкой.                                  1.      - YES
- 08 - Цифра с точкой, цифра.                           1.2     - YES
- 30 - Цифра с точкой, экспонент без цифр после.        1.E     - NO
- 31 -                                                  1.E-    - NO
- 09 - Цифра с точкой, экспонент, цифра.                1.E2    - YES
- 10 -                                                  1.e2    - YES
- 11 - Цифра с точкой, экспонент, знак, цифра.          1.e+2   - YES
- 12 -                                                  1.e-2   - YES
- 13 - Цифра, экспонент, цифра.                         1e2     - YES
- 14 - Цифра, экспонент, знак, цифра.                   1e+2    - YES
- 15 - Цифра, экспонент, знак, цифра.                   1e-2    - YES
- 16 - Цифра, точка, цифра, экспонент, цифра.           1.0e2   - YES
- 17 - Цифра, точка, цифра, экспонент, знак, цифра.     1.0e+2  - YES
- 18 -                                                  1.0e-2  - YES
- 19 - Две точки.                                       1..2    - NO
- 28 -                                                  .2.3    - NO
- 20 - Две экспонент.                                   1.Ee2   - NO
- 21 - Две знаки.                                       1e+-2   - NO
- 22 - Просто точка.                                    .       - NO
- 23 - Точка, цифра                                     .0      - YES
- 24 - Точка, экспонент, цифра.                         .E0     - NO
- 25 - Точка, цифра, экспонент, цифра.                  .0E0    - YES
- 26 - Точка, цифра, экспонент, знак, цифра.            .0E+0   - YES
- 27 - Знак без экспонент.                              +0.0-0  - NO


## Негативные тесты

- 01 - Неправильный ввод
- 02 - Ошибка в длине строку

