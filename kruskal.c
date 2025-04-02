#include <stdio.h>

int find(int v, int parent[]) {
    while (parent[v] != v)
        v = parent[v];
    return v;
}

void union1(int i, int j, int parent[]) {
    parent[j] = i;
}

void kruskal(int n, int a[10][10]) {
    int parent[10], t[10][2], count = 0, sum = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (count < n - 1) {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] < min && a[i][j] != 0) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }

        int i = find(u, parent);
        int j = find(v, parent);

        if (i != j) {
            union1(i, j, parent);
            t[count][0] = u;
            t[count][1] = v;
            count++;
            sum += min;
        }

        a[u][v] = a[v][u] = 999;
    }

    printf("Spanning Tree:\n");
    for (int i = 0; i < count; i++)
        printf("%d -- %d\n", t[i][0], t[i][1]);

    printf("Cost of Spanning Tree = %d\n", sum);
}

int main() {
    int n, a[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    kruskal(n, a);
    return 0;
}
