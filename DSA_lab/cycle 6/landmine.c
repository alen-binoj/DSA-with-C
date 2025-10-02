#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Direction vectors for 4 neighbors (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Queue node
typedef struct {
    int x, y;
} Point;

// BFS function to find shortest distances
void bfs(int maze[MAX][MAX], int dist[MAX][MAX], int n, int m) {
    Point queue[MAX * MAX];
    int front = 0, rear = 0;

    // Initialize distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;  // -1 means not reached
            if (maze[i][j] == -1) {  // landmine
                dist[i][j] = 0;
                queue[rear++] = (Point){i, j};  // enqueue all mines
            }
        }
    }

    // BFS
    while (front < rear) {
        Point p = queue[front++];
        for (int k = 0; k < 4; k++) {
            int nx = p.x + dx[k];
            int ny = p.y + dy[k];

            // Check boundaries and valid cell
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maze[nx][ny] == 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[p.x][p.y] + 1;
                    queue[rear++] = (Point){nx, ny};
                }
            }
        }
    }
}

int main() {
    int n, m;
    int maze[MAX][MAX], dist[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter maze (1 = free cell, -1 = landmine, 0 = blocked):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    bfs(maze, dist, n, m);

    printf("\nShortest distances to nearest landmine:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
