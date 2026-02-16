// https://www.acwing.com/file_system/file/content/whole/index/content/4186134/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n, option;
    char aim[101];
    scanf("%s", aim);
    scanf("%d", &option);
    scanf("%d", &n);

    int alength = strlen(aim);

    for (int i = 0; i < n; i++)
    {
        char in[101];
        scanf("%s", in);
        int length = strlen(in);

        if (length < alength)
            continue;

        if (option == 1)
        {
            if (strstr(in, aim) != NULL)
            {
                printf("%s\n", in);
            }
        }
        else
        {
            int found = 0;
            for (int k = 0; k <= length - alength; k++)
            {
                int match = 1;
                for (int j = 0; j < alength; j++)
                {
                    if (tolower(aim[j]) != tolower(in[k + j]))
                    {
                        match = 0;
                        break;
                    }
                }
                if (match)
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                printf("%s\n", in);
            }
        }
    }
    return 0;
}