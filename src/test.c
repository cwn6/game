#include <stdio.h>

int main() {
    int i, j, k;
    int n = 3;
    int m = 3;
    int p = 3;
    int a[n][m];
    int b[m][p];
    int c[n][p];

    // Initialize matrix a
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = i + j;
        }
    }
}