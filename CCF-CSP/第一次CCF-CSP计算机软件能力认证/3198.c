// https://www.acwing.com/file_system/file/content/whole/index/content/4186128/
#include <stdio.h>
#include <stdlib.h>

typedef struct window
{
    int x1, y1, x2, y2;
} window;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    window *windows = (window *)malloc(sizeof(window) * n);
    int *idx = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &windows[i].x1, &windows[i].y1, &windows[i].x2, &windows[i].y2);
        idx[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int found = -1;
        for (int k = n - 1; k >= 0; k--)
        {
            int win = idx[k];
            if (windows[win].x1 <= x && x <= windows[win].x2 &&
                windows[win].y1 <= y && y <= windows[win].y2)
            {
                found = k;
                break;
            }
        }
        if (found != -1)
        {
            int win = idx[found];
            printf("%d\n", win + 1);
            int temp = idx[found];
            for (int j = found; j < n - 1; j++)
            {
                idx[j] = idx[j + 1];
            }
            idx[n - 1] = temp;
        }
        else
        {
            printf("IGNORED\n");
        }
    }
    free(windows);
    free(idx);
    return 0;
}