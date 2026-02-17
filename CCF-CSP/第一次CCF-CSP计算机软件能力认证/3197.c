// https://www.acwing.com/file_system/file/content/whole/index/content/4186127/
#include <stdio.h>
#include <string.h>
int main()
{
    int hash[2002];
    memset(hash, 0, sizeof(hash));
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d", &j);
        if (-1000 <= j && j <= 1000) {
            hash[j + 1000]++;
        }
    }
    for (int i = 1; i <= 1000; i++) {
        if (hash[1000 + i] != 0 && hash[1000 - i] != 0) {
            cnt += (hash[1000 + i] >= hash[1000 - i] ? hash[1000 + i] : hash[1000 - i]);
        }
    }
    printf("%d", cnt);
}