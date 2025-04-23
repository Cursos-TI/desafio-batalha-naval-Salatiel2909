#include <stdio.h>

int main() {

    int tamtabuleiro = 10;
    int tamnavio = 3;

    int tabuleiro[10][10] = {0};

    int linhaH = 2, colunaH = 4; 
    int linhaV = 5, colunaV = 7; 
    int linhaD1 = 1, colunaD1 = 1; 
    int linhaD2 = 0, colunaD2 = 9; 

    int i;
    int sobreposicao = 0;

    if (colunaH + tamnavio <= tamtabuleiro) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < tamnavio; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        } else {
            printf("Erro\n");
        }
    }

    sobreposicao = 0;

    if (linhaV + tamnavio <= tamtabuleiro) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < tamnavio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro\n");
        }
    }

    sobreposicao = 0;

    if (linhaD1 + tamnavio <= tamtabuleiro && colunaD1 + tamnavio <= tamtabuleiro) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < tamnavio; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        } else {
            printf("Erro\n");
        }
    }

    sobreposicao = 0;

    if (linhaD2 + tamnavio <= tamtabuleiro && colunaD2 - tamnavio + 1 >= 0) {
        for (i = 0; i < tamnavio; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (i = 0; i < tamnavio; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        } else {
            printf("Erro\n");
        }
    }

    printf("Tabuleiro:\n   ");
    for (int coluna = 0; coluna < tamtabuleiro; coluna++) {
        printf("%d ", coluna);
    }
    printf("\n");

    for (int linha = 0; linha < tamtabuleiro; linha++) {
        printf("%c  ", 'A' + linha);
        for (int coluna = 0; coluna < tamtabuleiro; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}