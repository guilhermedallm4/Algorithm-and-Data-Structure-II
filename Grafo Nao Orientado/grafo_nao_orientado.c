
#include <stdlib.h>
#include <stdio.h>
int createMatriz(int values);

int main()
{
    int values;
    printf("Digite a quantidade de arestas: ");
    scanf("%d", &values);
    createMatriz(values);
    return 0;
}

int createMatriz(int values){
    int mMatriz[values][values];
    for(int i = 0;i<values;i++){//Valor coluna;
        for(int w = 0;w<values;w++){
            if(i == w){
                mMatriz[i][w] = 0;
                w++;
            }
                if(w < values){
                    printf("Digite o valor do peso da aresta(%d) referente a aresta(%d) ", i, w);
                    scanf("%d", &mMatriz[i][w]);
                    printf("\n");  
                }
   
            }
            }

        

    

     for(int i = 0;i<values;i++){//Valor coluna;
     printf("Aresta %d: ", i);
        for(int w = 0;w<values;w++){
            printf(" %d ", mMatriz[i][w]);
        }
        printf("\n");
         
     }
}