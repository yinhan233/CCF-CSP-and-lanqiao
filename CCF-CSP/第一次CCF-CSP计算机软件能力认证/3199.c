// https://www.acwing.com/file_system/file/content/whole/index/content/4186129/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char* para = (char*)malloc(sizeof(char) * 52);
    scanf("%s", para);
    int times;
    scanf("%d", &times);
    getchar();
    for (int i = 1; i <= times; i++) {
        char* string = (char*)malloc(sizeof(char) * 256);
        printf("Case %d:", i);
        fgets(string, 256, stdin);
        string[strcspn(string, "\n")] = '\0';
        int pow = 0;
        int exist[26] = { 0 };
        char arg[26][256] = { 0 };
        // 定位到参数部分（命令名之后）
        for (int j = 0; j < strlen(string); j++) {
            if (string[j] == ' ') {
                pow = j + 1;
                break;
            }
        }
        while (pow < strlen(string)) {
            while (pow < strlen(string) && string[pow] == ' ')
                pow++;
            if (pow >= strlen(string))
                break;
            // 检查是否是选项开头（'-'）
            if (string[pow] != '-')
                break;
            pow++;
            if (pow >= strlen(string))
                break;
            char c = string[pow];
            if (c < 'a' || c > 'z')
                break;
            if (pow + 1 < strlen(string) && string[pow + 1] != ' ')
                break;
            int valid = 0;
            int has_arg = 0;
            for (int k = 0; k < strlen(para); k++) {
                if (para[k] == c) {
                    valid = 1;
                    // 检查是否带参数
                    if (k + 1 < strlen(para) && para[k + 1] == ':')
                        has_arg = 1;
                    break;
                }
            }
            if (!valid)
                break; // 不是合法选项，停止分析
            // 先移动到选项字符之后，再处理参数
            pow++;
            if (has_arg) {
                // 跳过空格，找到参数开头
                while (pow < strlen(string) && string[pow] == ' ')
                    pow++;
                if (pow >= strlen(string))
                    break; // 带参数选项但无参数，直接停止，不记录该选项
                // 解析额外参数
                int epow = 0; // 记录arg的游标
                while (pow < strlen(string) && string[pow] != ' ') {
                    arg[c - 'a'][epow++] = string[pow++];
                }
                arg[c - 'a'][epow] = '\0';
            }
            // 只有参数检查通过后，才记录选项
            exist[c - 'a'] = 1;
        }
        // 按照字母升序输出
        for (int j = 0; j < 26; j++) {
            if (exist[j]) {
                printf(" -%c", 'a' + j);
                if (arg[j][0] != '\0') // 带参数的选项输出参数
                    printf(" %s", arg[j]);
            }
        }
        printf("\n");
        free(string);
    }
    free(para);
    return 0;
}