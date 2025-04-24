#include <stdio.h>

#define TAM 10
#define THAB 5

int main() {
    int tabuleiro[TAM][TAM] = {0};

    int tamnavio = 3;
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 7;
    int linhaD1 = 1, colunaD1 = 1;
    int linhaD2 = 0, colunaD2 = 9;
    int sobreposicao = 0, i;

    if (colunaH + tamnavio <= TAM) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao)
            for (i = 0; i < tamnavio; i++)
                tabuleiro[linhaH][colunaH + i] = 3;
    }

    sobreposicao = 0;
    if (linhaV + tamnavio <= TAM) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) sobreposicao = 1;
        }
        if (!sobreposicao)
            for (i = 0; i < tamnavio; i++)
                tabuleiro[linhaV + i][colunaV] = 3;
    }

    sobreposicao = 0;
    if (linhaD1 + tamnavio <= TAM && colunaD1 + tamnavio <= TAM) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao)
            for (i = 0; i < tamnavio; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    sobreposicao = 0;
    if (linhaD2 + tamnavio <= TAM && colunaD2 - tamnavio + 1 >= 0) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao)
            for (i = 0; i < tamnavio; i++)
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    int cone[THAB][THAB], cruz[THAB][THAB], octaedro[THAB][THAB];

    for (int i = 0; i < THAB; i++) {
        for (int j = 0; j < THAB; j++) {
            cone[i][j] = (j >= THAB/2 - i && j <= THAB/2 + i) ? 1 : 0;
        }
    }

    for (int i = 0; i < THAB; i++) {
        for (int j = 0; j < THAB; j++) {
            cruz[i][j] = (i == THAB/2 || j == THAB/2) ? 1 : 0;
        }
    }

    for (int i = 0; i < THAB; i++) {
        for (int j = 0; j < THAB; j++) {
            int dist_i = (i > THAB/2) ? i - THAB/2 : THAB/2 - i;
            int dist_j = (j > THAB/2) ? j - THAB/2 : THAB/2 - j;
            octaedro[i][j] = (dist_i + dist_j <= THAB/2) ? 1 : 0;
        }
    }

    int origemL[3] = {2, 6, 4};
    int origemC[3] = {4, 5, 8};
    int (*habilidades[3])[THAB] = {cone, cruz, octaedro};

    for (int h = 0; h < 3; h++) {
        int ot = THAB / 2;
        for (int i = 0; i < THAB; i++) {
            for (int j = 0; j < THAB; j++) {
                int l = origemL[h] + i - ot;
                int c = origemC[h] + j - ot;
                if (l >= 0 && l < TAM && c >= 0 && c < TAM && habilidades[h][i][j] == 1) {
                    if (tabuleiro[l][c] == 0)
                        tabuleiro[l][c] = 5;
                }
            }
        }
    }

    printf("Tabuleiro\n   ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n");

    for (int l = 0; l < TAM; l++) {
        printf("%c  ", 'A' + l);
        for (int c = 0; c < TAM; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    return 0;
}