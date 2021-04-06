#include <stdio.h>
#include <stdlib.h>
#define ROWS 15
#define COLUMNS 15

void naplnASectiRadky(int matice[ROWS][COLUMNS]) {
    int hodnota, soucetRadku = 0;;
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
    printf("____________________________________________________________|\n");
    
    for(int k = 0; k < COLUMNS; k++){
        for(int l = 0; l < ROWS; l++){
            soucetSloupce += matice[l][k];
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
    
    for(int x = 0; x < ROWS; x++){
        soucetDiagonaly += matice[x][x];
    }
    
    avg = soucetDiagonaly / ROWS; // diky ctvercove matici (15x15 ma diagonalu 15) se muze pouzit ROWS i COLUMNS
    printf("\nPrumer v diagonale je %.2f\n", avg);
    
    return;
}

void minHodnota(int matice[ROWS][COLUMNS]){
    int minLokace = matice[0][0];
    int radekMinLokace, sloupecMinLokace = 0;
    
    for(int a = 0; a < ROWS; a++) {
        for(int b = 0; b < COLUMNS; b++) {
            if(matice[a][b] < minLokace) {
                minLokace = matice[a][b];
                radekMinLokace = a;
                sloupecMinLokace = b;
            }
        }
    }
    
    printf("Nejmensi hodnota v matici je %d, nachazejici se na [%d][%d].\n", minLokace, radekMinLokace, sloupecMinLokace);
    return;
}

void maxHodnota(int matice[ROWS][COLUMNS]){
    int maxLokace = matice[0][0];
    int radekMaxLokace;
    int sloupecMaxLokace;
    
    for(int c = 0; c < ROWS; c++) {
        for(int d = 0; d < COLUMNS; d++) {
            if(maxLokace < matice[c][d]) {
                maxLokace = matice[c][d];
                radekMaxLokace = c;
                sloupecMaxLokace = d;
            }
        }
    }
    
    printf("Nejvetsi hodnota v matici je %d, nachazejici se na [%d][%d].\n", maxLokace, radekMaxLokace, sloupecMaxLokace);
    return;
}

int main() {
    int matice[ROWS][COLUMNS];
    naplnASectiRadky(matice);
    sectiSloupce(matice);
    prumerDiagonaly(matice);
    minHodnota(matice);
    maxHodnota(matice);
    return 0;
}
