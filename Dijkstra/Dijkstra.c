#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2000
#define INFINITO INT_MAX;

int **criaGrafo(int *numeroVertices);
void insereVertices(int **grafo, int linha, int coluna, int peso);
void insert(int **grafo, int numeroVertices);
void listarGrafo(int **grafo, int numeroVertices);
void dijkstra(int **grafo, int pInicial, int pFinal, int numeroVertices);
void menu(int **grafo, int numeroVertices);
void clear(int **grafo, int numeroVertices);

int main() {
    int **grafo = NULL, numeroVertices, pInicial, pFinal, opcao;
    
    /* Cria o grafo e inicializa com valores */
    grafo = criaGrafo(&numeroVertices);

    /* Define se quer alterar os pesos do grafo ou utilizar pesos já definidos */
    menu(grafo, numeroVertices);


        printf("Informe o ponto Inicial: ");
        scanf("%d", &pInicial);

        printf("Informe o ponto Final: ");
        scanf("%d", &pFinal);


        
        dijkstra(grafo, pInicial, pFinal, numeroVertices);


    clear(grafo, numeroVertices);
    

}

int **criaGrafo(int *numeroVertices) {
    int **novoGrafo = NULL, i, j;
    do {
        printf("Informe o numero de vertices: ");
        scanf("%d", numeroVertices);

    } while (*numeroVertices < 1 || *numeroVertices > 20);

    novoGrafo = (int**)malloc((*numeroVertices) * sizeof(int*));

    if (!novoGrafo) {
        printf("Erro ao Alocar memoria\n");
        exit(1);
    }

    for (i = 0; i < *numeroVertices; i++) {
        novoGrafo[i] = (int*)malloc(*numeroVertices * sizeof(int));

        if (!novoGrafo[i]) {
            printf("Erro ao Alocar memoria\n");
            exit(1);
        }
    }

    for (i = 0; i < *numeroVertices; i++) 
        for (j = 0; j < *numeroVertices; j++) 
            novoGrafo[i][j] = INFINITO;
        
    return novoGrafo;
}

void insereVertices(int **grafo, int linha, int coluna, int peso) {
    grafo[linha][coluna] = peso;
}

void dijkstra(int **grafo, int pInicial, int pFinal, int numeroVertices) {
    int distancia[numeroVertices], predecessor[numeroVertices], visitado[numeroVertices], contVertices = 0, menorDistancia, indexMenor = pFinal, i;
    
    /* Inicializa os vetores auxiliares */
    for (i = 0; i < numeroVertices; i++) {
        distancia[i] = grafo[pInicial][i];
        predecessor[i] = pInicial;
        visitado[i] = 0;
    }
    /* Estabelece a distância do vértice para ele mesmo é zero e marca como visitado */
    distancia[pInicial] = 0;
    visitado[pInicial] = 1;
    contVertices++;

   while (contVertices < numeroVertices) {
        menorDistancia = INFINITO;

        
        for (i = 0; i < numeroVertices; i++) {
            if (distancia[i] < menorDistancia && !visitado[i]) {
                menorDistancia = distancia[i];
                indexMenor = i;
            }
        }

        
        visitado[indexMenor] = 1;

        
        for (i = 0; i < numeroVertices; i++) {
            if (!visitado[i])
                
                if (menorDistancia + grafo[indexMenor][i] < distancia[i]) {
                    distancia[i] = menorDistancia + grafo[indexMenor][i];
                    predecessor[i] = indexMenor;
                }
        }

        contVertices++;
    }

    printf("Distancia = %d\n", distancia[pFinal]);


    do {
        pFinal = predecessor[pFinal];
        printf("%d ", pFinal);
    } while (pFinal != pInicial);

    printf("\n");
}

void listarGrafo(int **grafo, int numeroVertices) {
    int i, j;

    for (i = 0; i < numeroVertices; i++) {
        for (j = 0; j < numeroVertices; j++) 
            printf("%d ", grafo[i][j]);
        printf("\n");
    }
}

void insert(int **grafo, int numeroVertices) {
    int linha, coluna;

    for (linha = 0; linha < numeroVertices; linha++) {
        for (coluna = 0; coluna < numeroVertices; coluna++) {
            if(linha == coluna){
                grafo[linha][coluna] = 0;
                coluna++;
            }
            printf("Aresta (%d) em relação Aresta (%d): ", linha, coluna);
            scanf("%d", &grafo[linha][coluna]);
            while(grafo[linha][coluna] < 0){
                printf("Peso invalido, digite um peso maior ou igual a 0:\n");
                scanf("%d", &grafo[linha][coluna]);
            }
        }
    }
}

void menu(int **grafo, int numeroVertices) {
    int opcao;

    do {
        printf("1- Gerar Grafo\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: insert(grafo, numeroVertices);
                    break;
            
            default: printf("Informe uma opcao valida\n");
                     break;
        }
    } while (opcao != 1);
}

void clear(int **grafo, int numeroVertices) {
    int linha;

    for (linha = 0; linha < numeroVertices; linha++) 
        free(grafo[linha]);
    

    free(grafo);
}