#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 10
// Valor que representa parte do navio
#define NAVIO 3
// Tamanho dos navios
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 4; // Navio horizontal começa na linha 2, coluna 4
    int linhaV = 5, colunaV = 7; // Navio vertical começa na linha 5, coluna 7

    // Validação de posição horizontal
    if (colunaH + TAM_NAVIO <= TAM) {
        // Verifica sobreposição com navio vertical
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (linhaH == linhaV + i && colunaH + i == colunaV) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona navio horizontal
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada no navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação de posição vertical
    if (linhaV + TAM_NAVIO <= TAM) {
        // Verifica sobreposição com navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona navio vertical
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada no navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}