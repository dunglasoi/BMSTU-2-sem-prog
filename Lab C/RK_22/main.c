#include "func.h"

int main(int argc, char **argv)
{
    int rc = OK;
    FILE *f;

    if (argc == 2)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            rc = errno;
            error(rc);
            return rc;
        }
        rc = calc(f);
        fclose(f);
        if (rc)
        {
            error(rc);
            return rc;
        }
        return OK;
    }
}
