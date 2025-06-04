#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void input_array(int **array, int n);
void process_array(int **array, int n);
void print_array(int **array, int n);

int main(){
    int **array, i;
    int n = 5;

    array = (int**)malloc(n * sizeof(int*));
    if (array == NULL){
        printf("out of memory\n");
        return 1;
    }

    for (i = 0; i < n; i++){
        array[i] = (int*)malloc(n * sizeof(int));
        if (array[i] == NULL){
            printf("out of memory\n");
            return 2;
        }
    }

    puts("input matrix A:");
    input_array(array, n);

    process_array(array, n);

    printf("Processed matrix:\n");
    print_array(array, n);

    for (i = 0; i < n; i++)
        free(array[i]);
    free(array);

    getch();
    return 0;
}

void input_array(int **array, int n){
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &array[i][j]);
}

void process_array(int **array, int n){
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            array[i][j] = (array[i][j] > 0) ? 1 : 0;
}

void print_array(int **array, int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}
