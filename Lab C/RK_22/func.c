#include "func.h"

int calc(FILE *f)
{
    size_t n_line = 0;
    char line[STR_LEN];
    double sum = 0, num;
    char symbol;
    char sign = '+';
    char *end;

    while (!feof(f))
    {
        // читаем посимволно
        if (fread(&symbol, sizeof(symbol), 1, f) != 1 && !feof(f))
            return errno;

        // float with exp
        if (!isdigit(symbol) && !isspace(symbol) && !strchr("+-eE.", symbol))
            return ERR_INVALID_CHAR;

        // строка больше 50 символов
        if (n_line + 1 > STR_LEN)
            return ERR_LINE_LEN;

        // символ разделители
        if (symbol == '+' || symbol == '-' || symbol == '\n')
        {
            line[n_line] = '\0';

            // перевод строка в double
            num = strtod(line, &end);

            if (symbol == '+' || symbol == '-')
            {
                if (sign == '+')
                    sum += num;
                else
                    sum -= num;

                sign = symbol;
                if (!fprintf(stdout, "%s%c", line, symbol))
                    return errno;
            }

            if (symbol == '\n' && !feof(f))
            {
                if (sign == '+')
                    sum += num;
                else
                    sum -= num;

                if (!fprintf(stdout, "%s = %.2lf\n", line, sum))
                    return errno;

                sum = 0;
                sign = '+';
            }

            n_line = 0;
        }
        else
        {
            // формируем строку
            line[n_line] = symbol;
            n_line++;
        }
    }

    return OK;
}

void error(int err)
{
    if (err > 0)
    {
        printf("Error: %s\n", strerror(err));
        return;
    }

    switch (err)
    {
        case ERR_ARG:
            printf("Error: ERR_ARG\n");
            break;
        case ERR_INVALID_CHAR:
            printf("Error: ERR_INVALID_CHAR\n");
            break;
        case ERR_LINE_LEN:
            printf("Error: ERR_LINE_LEN\n");
            break;
        case OK:
            break;
        default:
            printf("Error: Неизвестный код %d!\n", err);
            break;
    }
}
