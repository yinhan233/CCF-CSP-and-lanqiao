#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int hash[100000];
    int start = 100001;
    int end = -1;
    scanf("%d", &n);
    memset(hash, 0, sizeof(hash));
    getchar();
    for (int i = 0; i < n; i++)
    {
        char buffer[100000];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        int pos = 0;
        int num = 0;
        while (buffer[pos] != '\0')
        {
            if (buffer[pos] == ' ')
            {
                hash[num]++;
                if (num < start)
                {
                    start = num;
                }
                if (num > end)
                {
                    end = num;
                }
                num = 0;
            }
            else
            {
                num = num * 10 + (buffer[pos] - '0');
            }
            pos++;
        }
        hash[num]++;
        if (num < start)
        {
            start = num;
        }
        if (num > end)
        {
            end = num;
        }
    }
    int d;
    int l;
    for (int i = start; i <= end; i++)
    {
        if (hash[i] == 0)
        {
            d = i;
        }
        if (hash[i] == 2)
        {
            l = i;
        }
    }
    printf("%d ", d);
    printf("%d", l);
    return 0;
}