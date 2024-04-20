#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWord(char *str, const char *target, const char *replacement)
{
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);

    // Duyệt qua chuỗi và tìm từ cần thay thế
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], target) == &str[i])
        {
            // Nếu tìm thấy từ cần thay thế, thì thay thế nó bằng từ mới
            strncpy(&str[i], replacement, replacementLen);
            i += replacementLen - 1;
        }
    }
}

int main()
{
    char str[1000];

    printf("Nhập chuỗi: ");
    fgets(str, sizeof(str), stdin);

    // Xóa ký tự newline (\n) ở cuối chuỗi
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    replaceWord(str, "em", "anh");

    printf("Chuỗi sau khi thay thế: %s\n", str);

    return 0;
}
