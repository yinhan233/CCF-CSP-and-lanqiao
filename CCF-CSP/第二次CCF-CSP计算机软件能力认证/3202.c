// https://www.acwing.com/file_system/file/content/whole/index/content/4186132/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int hash[10000];
    int n;
    int cnt = 0;
    scanf("%d", &n);
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        hash[k] += 1;
    }
    int z = 1;
    while (z < 10000) {
        if (hash[z - 1] > 0 && hash[z] > 0) {
            cnt += (hash[z - 1] > hash[z] ? hash[z] : hash[z - 1]);
        }
        if (hash[z + 1] > 0 && hash[z] > 0) {
            cnt += (hash[z + 1] > hash[z] ? hash[z] : hash[z + 1]);
        }
        z += 2;
    }
    printf("%d", cnt);
}