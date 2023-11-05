#include <stdio.h>

#define N 10

void displayMatrix(float matrix[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(float matrix[N][N], int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            printf("Mathematical Error!");
            return;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                float ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k <= n; k++) {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        float a = matrix[i][i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] = matrix[i][j] / a;
        }
    }

    printf("\nGauss Jordan Matrix is:\n");
    displayMatrix(matrix, n);
}

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float matrix[N][N];
    printf("Enter the augmented matrix row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Input Matrix is:\n");
    displayMatrix(matrix, n);

    gaussJordan(matrix, n);

    return 0;
}
