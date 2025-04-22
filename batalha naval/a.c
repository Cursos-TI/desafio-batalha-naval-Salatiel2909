#include <stdio.h>

int main() {
    
    int tamtabuleiro = 10;
    int tamnavio = 3;
    
    int tabuleiro[10][10] = {0};

    int linhaH = 2;
    int colunaH = 4;

    int linhaV = 5;
    int colunaV = 7;

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
    } else {
        printf("Erro\n");
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
    } else {
        printf("Erro\n");
    }

    printf("Tabuleiro:\n");
    for (int linha = 0; linha < tamtabuleiro; linha++) {
        for (int coluna = 0; coluna < tamtabuleiro; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}