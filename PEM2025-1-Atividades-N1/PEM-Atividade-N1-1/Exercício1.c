/*
    Autor: Raphael Masiero Granado
    RA: 2040482422023
    Curso: Análise e Desenvolvimento de Sistemas (ADS) - Vespertino
    Matéria: Programação Estruturada e Modular - Professor Carlos Veríssimo
    Data: 28/02/2025
    Descrição:
        Este programa em C gerencia o processo seletivo para residência médica
        utilizando apenas arrays, sem structs nem funções.
        Compreendo que essa abordagem torna o programa menos eficiente,
        mas a implementação foi feita com base apenas nos conhecimentos
        sobre arrays que foram disponibilizados até o momento.
*/


#include <stdio.h>
#include <string.h>

int main() {
    char nomes[50][100];
    float notasPE[50][4];
    float notasAC[50][5];
    float notasPP[50][10];
    float notasEB[50][3];
    float notaFinalPE[50];
    float notaFinalAC[50];
    float notaFinalPP[50];
    float notaFinalEB[50];
    float notaFinal[50];
    int classificacao[50];
    int totalCandidatos = 0;
    int i, j, k, temp;
    float maior, menor, soma;



    printf("Quantos candidatos deseja cadastrar (máximo 50)? ");
    scanf("%d", &totalCandidatos);

    if (totalCandidatos > 50) {
        totalCandidatos = 50;
        printf("Número máximo de candidatos é 50. Serão cadastrados 50 candidatos.\n");
    }

    for (i = 0; i < totalCandidatos; i++) {
        printf("\n--- Cadastro do Candidato %d ---\n", i + 1);

        printf("Nome do candidato: ");
        scanf(" %[^\n]", nomes[i]);

        printf("\nNotas da Prova Escrita (PE) - 4 avaliadores:\n");
        for (j = 0; j < 4; j++) {
            printf("Nota %d (0.0 a 10.0): ", j + 1);
            scanf("%f", &notasPE[i][j]);
            while (notasPE[i][j] < 0 || notasPE[i][j] > 10) {
                printf("Nota inválida. Digite uma nota entre 0.0 e 10.0: ");
                scanf("%f", &notasPE[i][j]);
            }
        }

        maior = notasPE[i][0];
        menor = notasPE[i][0];
        soma = 0;

        for (j = 0; j < 4; j++) {
            if (notasPE[i][j] > maior) {
                maior = notasPE[i][j];
            }
            if (notasPE[i][j] < menor) {
                menor = notasPE[i][j];
            }
            soma += notasPE[i][j];
        }

        soma = soma - maior - menor;
        notaFinalPE[i] = soma / 2;

        printf("\nNotas da Análise Curricular (AC) - 5 avaliadores:\n");
        for (j = 0; j < 5; j++) {
            printf("Nota %d (0.0 a 10.0): ", j + 1);
            scanf("%f", &notasAC[i][j]);
            while (notasAC[i][j] < 0 || notasAC[i][j] > 10) {
                printf("Nota inválida. Digite uma nota entre 0.0 e 10.0: ");
                scanf("%f", &notasAC[i][j]);
            }
        }

        maior = notasAC[i][0];
        menor = notasAC[i][0];
        soma = 0;

        for (j = 0; j < 5; j++) {
            if (notasAC[i][j] > maior) {
                maior = notasAC[i][j];
            }
            if (notasAC[i][j] < menor) {
                menor = notasAC[i][j];
            }
            soma += notasAC[i][j];
        }

        soma = soma - maior - menor;
        notaFinalAC[i] = soma / 3;

        printf("\nNotas da Prova Prática (PP) - 10 avaliadores:\n");
        for (j = 0; j < 10; j++) {
            printf("Nota %d (0.0 a 10.0): ", j + 1);
            scanf("%f", &notasPP[i][j]);
            while (notasPP[i][j] < 0 || notasPP[i][j] > 10) {
                printf("Nota inválida. Digite uma nota entre 0.0 e 10.0: ");
                scanf("%f", &notasPP[i][j]);
            }
        }

        maior = notasPP[i][0];
        menor = notasPP[i][0];
        soma = 0;

        for (j = 0; j < 10; j++) {
            if (notasPP[i][j] > maior) {
                maior = notasPP[i][j];
            }
            if (notasPP[i][j] < menor) {
                menor = notasPP[i][j];
            }
            soma += notasPP[i][j];
        }

        soma = soma - maior - menor;
        notaFinalPP[i] = soma / 8;

        printf("\nNotas da Entrevista em Banca (EB) - 3 avaliadores:\n");
        for (j = 0; j < 3; j++) {
            printf("Nota %d (0.0 a 10.0): ", j + 1);
            scanf("%f", &notasEB[i][j]);
            while (notasEB[i][j] < 0 || notasEB[i][j] > 10) {
                printf("Nota inválida. Digite uma nota entre 0.0 e 10.0: ");
                scanf("%f", &notasEB[i][j]);
            }
        }

        maior = notasEB[i][0];
        menor = notasEB[i][0];
        soma = 0;

        for (j = 0; j < 3; j++) {
            if (notasEB[i][j] > maior) {
                maior = notasEB[i][j];
            }
            if (notasEB[i][j] < menor) {
                menor = notasEB[i][j];
            }
            soma += notasEB[i][j];
        }

        soma = soma - maior - menor;
        notaFinalEB[i] = soma / 1;

        notaFinal[i] = (notaFinalPE[i] * 0.3) + (notaFinalAC[i] * 0.1) + (notaFinalPP[i] * 0.4) + (notaFinalEB[i] * 0.2);

        classificacao[i] = i;
    }

    for (i = 0; i < totalCandidatos - 1; i++) {
        for (j = i + 1; j < totalCandidatos; j++) {
            if (notaFinal[classificacao[i]] < notaFinal[classificacao[j]]) {
                temp = classificacao[i];
                classificacao[i] = classificacao[j];
                classificacao[j] = temp;
            }
        }
    }

    printf("\n\n=== CLASSIFICACAO FINAL ===\n");
    for (i = 0; i < totalCandidatos && i < 15; i++) {
        k = classificacao[i];
        printf("%-8d| %-30s | %.2f\n", i + 1, nomes[k], notaFinal[k]);
    }

    printf("\n=== FIM DO PROGRAMA ===\n");

    return 0;
}
