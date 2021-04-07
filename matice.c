#include <stdio.h>
#include <stdlib.h>
#define ROWS 15
#define COLUMNS 15

void naplnVypisPoleASectiRadky(int matice[ROWS][COLUMNS]) {
    int hodnota, soucetRadku = 0;
    srand((unsigned)time(NULL));
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++){
            hodnota = rand() % 99 + 1;
            matice[i][j] = hodnota;
            printf(" %.2d ", matice[i][j]);
            soucetRadku += matice[i][j];
        }
        printf("| %d\n", soucetRadku);
        soucetRadku = 0;
    }
    return;
}

void sectiSloupce(int matice[ROWS][COLUMNS]) {
    int soucetSloupce = 0;
    printf("------------------------------------------------------------|\n");
    
    for(int i = 0; i < COLUMNS; i++){
        for(int j = 0; j < ROWS; j++){
            soucetSloupce += matice[i][j];
        }
        printf("%d ",soucetSloupce);
        soucetSloupce = 0;
    }
    printf("\n");
    return;
}

void prumerDiagonaly(int matice[ROWS][COLUMNS]){
    float avg = 0;
    float soucetDiagonaly = 0;
    
    for(int i = 0; i < ROWS; i++){
        soucetDiagonaly += matice[i][i];
    }
    
    avg = soucetDiagonaly / ROWS; // diky ctvercove matici (15x15 ma diagonalu 15) se muze pouzit ROWS i COLUMNS
    printf("\nPrumerna hodnota prvku na diagonale je %.2f.\n\n", avg);
    
    return;
}

void minHodnota(int matice[ROWS][COLUMNS]){
    int minNum = matice[0][0];
    typedef struct Lokace {
        int row;
        int column;
    } Lokace;
    Lokace minLokace[ROWS * COLUMNS]; //pole na ukladani pozic minHodnot
    int minLokaceIndex = 0;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(minNum > matice[i][j]) {
                minNum = matice[i][j];
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (matice[i][j] == minNum) {
                minLokace[minLokaceIndex].row = i;
                minLokace[minLokaceIndex].column = j;
                minLokaceIndex++;
            }
        }
    }

    printf("Minimalni hodnota %d je obsazena v matici %d krat na indexech ", minNum, minLokaceIndex);
    for (int i = 0; i < minLokaceIndex; i++) {
        printf("[%d][%d], ", minLokace[i].row, minLokace[i].column);
    }
    printf("\b\b.\n");
}


void maxHodnota(int matice[ROWS][COLUMNS]){
    int maxNum = matice[0][0];
    typedef struct Lokace {
    int row;
    int column;
    } Lokace;
    Lokace maxLokace[ROWS * COLUMNS];
    int maxLokaceIndex = 0;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(maxNum < matice[i][j]) {
                maxNum = matice[i][j];
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (matice[i][j] == maxNum) {
                maxLokace[maxLokaceIndex].row = i;
                maxLokace[maxLokaceIndex].column = j;
                maxLokaceIndex++;
            }
        }
    }

    printf("Maximalni hodnota %d je obsazena v matici %d krat na indexech ", maxNum, maxLokaceIndex);
    for (int i = 0; i < maxLokaceIndex; i++) {
        printf("[%d][%d], ", maxLokace[i].row, maxLokace[i].column);
    }
    printf("\b\b.\n");
}

int main() {
    int matice[ROWS][COLUMNS];
    naplnVypisPoleASectiRadky(matice);
    sectiSloupce(matice);
    prumerDiagonaly(matice);
    minHodnota(matice);
    maxHodnota(matice);
    return 0;
}