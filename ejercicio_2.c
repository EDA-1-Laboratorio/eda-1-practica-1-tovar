#include <stdio.h>

#define MAX 20

void generarEspiral(int n, int matriz[MAX][MAX]) {
    int valor = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (valor <= n * n) {

        for (int j = left; j <= right; j++) {
            matriz[top][j] = valor++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            matriz[i][right] = valor++;
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matriz[bottom][j] = valor++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matriz[i][left] = valor++;
            }
            left++;
        }
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\n--- Matriz Espiral de %dx%d ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Ingrese el tamaño N de la matriz (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: El tamaño excede el máximo permitido.\n");
        return 1;
    }

    generarEspiral(n, matriz);
    imprimirMatriz(n, matriz);

    return 0;
}
// PREGUNTA: ¿Qué sucede si se omite la verificación if (top <= bottom) -linea 21- dentro del bucle?
//RESPUESTA: Si se omite esa verificaion, el programa puede intentar recorrer y llenar una fila anterior que ya fue utilizada antes,
//esto puede hacer que se sobreescriban valores, la matriz tenga resultados incorrectos y/o pierda su orden logico.
