// https://www.acwing.com/file_system/file/content/whole/index/content/4186133/
#include <stdio.h>
#include <string.h>
int main()
{
    int graph[101][101];
    memset(graph, 0, sizeof(graph));
    int n;
    scanf("%d", &n);
    for (int k = 0; k < n; k++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                graph[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (graph[i][j] == 1) {
                cnt += 1;
            }
        }
    }
    printf("%d", cnt);
}