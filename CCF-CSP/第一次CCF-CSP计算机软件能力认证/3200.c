// https : // www.acwing.com/file_system/file/content/whole/index/content/4186130/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point
{
    int x;
    int y;
    bool type;
} point;

// BFS 队列节点：当前节点索引 + 已用新增路由器数
typedef struct QueueNode
{
    int u;
    int cnt;
} QueueNode;

int bfs(point *a, int n, int m, int k, int r)
{
    // dist[u][cnt]：到达节点 u，使用 cnt 个新增路由器的最少边数
    int dist[n + m + 1][k + 1];
    memset(dist, -1, sizeof(dist));
    QueueNode q[(n + m + 1) * (k + 1)]; // 数组模拟队列
    int head = 0, tail = 0;
    // 初始化起点：第 0 个节点（第一个路由器），0 个新增
    q[tail].u = 0;
    q[tail].cnt = 0;
    tail++;
    dist[0][0] = 0;
    while (head < tail)
    {
        QueueNode curr = q[head++];
        int u = curr.u;
        int cnt = curr.cnt;
        int current_dist = dist[u][cnt];
        // 遍历所有节点 v，尝试扩展
        for (int v = 0; v < n + m; v++)
        {
            if (v == u)
                continue;
            long long dx = (long long)a[u].x - a[v].x;
            long long dy = (long long)a[u].y - a[v].y;
            long long dist_sq = dx * dx + dy * dy;
            long long r_sq = (long long)r * r;
            if (dist_sq > r_sq)
                continue;
            int new_cnt = cnt;
            if (v >= n)
            {
                new_cnt = cnt + 1;
                if (new_cnt > k)
                    continue;
            }
            // 如果该状态未访问过，更新距离并入队
            if (dist[v][new_cnt] == -1)
            {
                dist[v][new_cnt] = current_dist + 1;
                q[tail].u = v;
                q[tail].cnt = new_cnt;
                tail++;
            }
        }
    }
    // 找终点（第 1 个节点）的最少边数
    int min_steps = -1;
    for (int j = 0; j <= k; j++)
    {
        if (dist[1][j] != -1)
        {
            if (min_steps == -1 || dist[1][j] < min_steps)
            {
                min_steps = dist[1][j];
            }
        }
    }
    return min_steps - 1;
}

int main()
{
    int n, m, k, r;
    scanf("%d %d %d %d", &n, &m, &k, &r);
    point *plist = (point *)malloc(sizeof(point) * (n + m));

    // 读取原有路由器
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &plist[i].x, &plist[i].y);
        plist[i].type = true;
    }

    // 读取可选路由器位置
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &plist[i + n].x, &plist[i + n].y);
        plist[i + n].type = false;
    }

    printf("%d", bfs(plist, n, m, k, r));
    free(plist);
    return 0;
}