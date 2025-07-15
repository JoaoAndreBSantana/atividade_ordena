# Projeto de Ordenação em C

Este projeto em linguagem C implementa e compara **três algoritmos de ordenação**: **Bubble Sort**, **Selection Sort** e **Insertion Sort**.  
Os dados utilizados são 17 pessoas (nome e idade), armazenados em um vetor de structs. A ordenação é feita **em ordem alfabética pelo nome**, utilizando a função `strcmp`.

---

##  Estrutura Utilizada

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

##  Algoritmos Implementados

###  Bubble Sort

O **Bubble Sort** compara pares adjacentes e os troca se estiverem fora de ordem. Esse processo se repete até que o vetor esteja ordenado.

**Complexidade:**

- Melhor caso: `O(n)` (lista já ordenada)  
- Caso médio: `O(n²)`  
- Pior caso: `O(n²)`

---

###  Selection Sort

O **Selection Sort** percorre a lista procurando o menor elemento e o coloca na posição correta. Isso é repetido até o fim da lista.

**Complexidade:**

- Melhor caso: `O(n²)`  
- Caso médio: `O(n²)`  
- Pior caso: `O(n²)`

---

###  Insertion Sort

O **Insertion Sort** percorre a lista e insere cada elemento na posição correta à esquerda, mantendo uma sublista ordenada.

**Complexidade:**

- Melhor caso: `O(n)`  
- Caso médio: `O(n²)`  
- Pior caso: `O(n²)`

- ## Tabela Comparativa dos Algoritmos

| Algoritmo         | Comparações | Trocas | Tempo Médio (ms) |
|-------------------|-------------|--------|------------------|
| Bubble Sort       | 136         | 5      | 0.00             |
| Selection Sort    | 136         | 3      | 0.00             |
| Insertion Sort    | 19          | 5      | 0.00             |

---

## Escolha dos algoritmos

Escolhi o Bubble Sort, Selection Sort e Insertion Sort por serem algoritmos clássicos, simples de implementar e muito utilizados em contextos acadêmicos. Eles permitem entender bem os conceitos de comparações, trocas e comportamento em diferentes situações. Além disso, são ideais para comparar eficiência em listas pequenas, como as usadas neste projeto.


