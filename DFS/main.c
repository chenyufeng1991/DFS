#include <stdio.h>

#define N 4

struct adj_matrix {
    int vertex[N];
    int edge[N][N];
};

struct adj_matrix matrix = {
    {1, 2, 3, 4},

    {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0},
    }
};

int visit[N] = {0, 0, 0, 0};

void dfs_visit(struct adj_matrix *G, int u)
{
    visit[u] = 1;
    printf("%3d", G->vertex[u]);

    for (int v = 0; v < N; v++)
    {
        // 表示存在一条边，并这个节点没有被访问
        if (G->edge[u][v] == 1 && visit[v] != 1)
        {
            dfs_visit(G, v);
        }
    }
}

void dfs(struct adj_matrix *G)
{
    for (int u = 0; u < N; u++)
    {
        if (visit[u] != 1)
        {
            dfs_visit(G, u);
        }
    }
}

int main(void)
{
    dfs(&matrix);
    printf("\n");

    return 0;
}