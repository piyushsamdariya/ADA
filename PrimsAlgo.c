
#include <stdio.h>

int cost[10][10], vt[10], et[10][10], vis[10], j, n;
int sum = 0;
int x = 1;
int e = 0;

void prims() {
    int s, min, m, k, u, v;

    vt[x] = 1;
    vis[x] = 1;

    for(s = 1; s < n; s++) {
        j = x;
        min = 999;

        while(j > 0) {
            k = vt[j];
            for(m = 1; m <= n; m++) {
                if(vis[m] == 0) {
                    if(cost[k][m] < min) {
                        min = cost[k][m];
                        u = k;
                        v = m;
                    }
                }
            }
            j--;
        }

        vt[++x] = v;
        et[s][0] = u;
        et[s][1] = v;
        e++;
        vis[v] = 1;
        sum += min;
    }
}

void main() {
    int i;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
        vis[i] = 0;
    }

    prims();

   /* printf("Edges of spanning tree:\n");
    for(i = 1; i <= e; i++) {
        printf("%d,%d\t", et[i][0], et[i][1]);
    }*/
    printf("\nWeight = %d\n", sum);
}
