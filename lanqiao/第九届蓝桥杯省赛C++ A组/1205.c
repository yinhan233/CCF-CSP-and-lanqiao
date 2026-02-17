// https://www.acwing.com/problem/content/description/1207/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int max_size = n * m;
    bool st[max_size];
    memset(st, 0, sizeof(st));
    st[0] = true;
    for (int i = 1; i < max_size; i++) {
        if (i >= n && st[i - n])
            st[i] = true;
        if (i >= m && st[i - m])
            st[i] = true;
    }
    int ans = 0;
    for (int i = max_size - 1; i >= 0; i--) {
        if (!st[i]) {
            ans = i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}