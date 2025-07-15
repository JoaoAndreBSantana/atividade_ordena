#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 17

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

// Copia o array original para outro
void copiar_array(Pessoa destino[], Pessoa origem[]) {
    for (int i = 0; i < TAM; i++) {
        destino[i] = origem[i];
    }
}

void imprimir_pessoas(Pessoa pessoas[]) {
    for (int i = 0; i < TAM; i++) {
        printf("%s - %d anos\n", pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");
}

// BUBBLE SORT
void bubble_sort(Pessoa pessoas[], int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

// SELECTION SORT
void selection_sort(Pessoa pessoas[], int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < TAM - 1; i++) {
        int min = i;
        for (int j = i + 1; j < TAM; j++) {
            (*comparacoes)++;
            if (strcmp(pessoas[j].nome, pessoas[min].nome) < 0) {
                min = j;
            }
        }
        if (min != i) {
            Pessoa temp = pessoas[i];
            pessoas[i] = pessoas[min];
            pessoas[min] = temp;
            (*trocas)++;
        }
    }
}

// INSERTION SORT
void insertion_sort(Pessoa pessoas[], int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 1; i < TAM; i++) {
        Pessoa chave = pessoas[i];
        int j = i - 1;

        while (j >= 0 && strcmp(pessoas[j].nome, chave.nome) > 0) {
            (*comparacoes)++;
            pessoas[j + 1] = pessoas[j];
            (*trocas)++;
            j--;
        }
        if (j >= 0) (*comparacoes)++; // Última comparação falsa

        pessoas[j + 1] = chave;
    }
}

// Função para calcular tempo médio
double tempo_medio(void (*funcao)(Pessoa[], int*, int*), Pessoa pessoas[]) {
    int comp, troca;
    clock_t inicio, fim;
    double soma = 0;
    Pessoa copia[TAM];

    for (int i = 0; i < 5; i++) {
        copiar_array(copia, pessoas);
        inicio = clock();
        funcao(copia, &comp, &troca);
        fim = clock();
        soma += (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
    }
    return soma / 5.0;
}

int main() {
    Pessoa pessoas[TAM] = {
        {"Carlos", 25}, {"Bruna", 22}, {"Amanda", 19}, {"Eduardo", 30},
        {"Fernanda", 24}, {"Diego", 21}, {"Helena", 26}, {"Igor", 28},
        {"Juliana", 27}, {"Lucas", 23}, {"Mariana", 20}, {"Nicolas", 18},
        {"Otavio", 29}, {"Patricia", 31}, {"Rafael", 33}, {"Sofia", 32},
        {"Tiago", 34}
    };

    Pessoa copia[TAM];
    int comparacoes, trocas;

    printf("===== BUBBLE SORT =====\n");
    copiar_array(copia, pessoas);
    double tempo_bubble = tempo_medio(bubble_sort, pessoas);
    bubble_sort(copia, &comparacoes, &trocas);
    imprimir_pessoas(copia);
    printf("Comparacao: %d\nTrocas: %d\nTempo medio: %.2f ms\n\n", comparacoes, trocas, tempo_bubble);

    printf("===== SELECTION SORT =====\n");
    copiar_array(copia, pessoas);
    double tempo_selection = tempo_medio(selection_sort, pessoas);
    selection_sort(copia, &comparacoes, &trocas);
    imprimir_pessoas(copia);
    printf("Comparacao: %d\nTrocas: %d\nTempo medio: %.2f ms\n\n", comparacoes, trocas, tempo_selection);

    printf("===== INSERTION SORT =====\n");
    copiar_array(copia, pessoas);
    double tempo_insertion = tempo_medio(insertion_sort, pessoas);
    insertion_sort(copia, &comparacoes, &trocas);
    imprimir_pessoas(copia);
    printf("Comparacao: %d\nTrocas: %d\nTempo medio: %.2f ms\n", comparacoes, trocas, tempo_insertion);

    return 0;
}
