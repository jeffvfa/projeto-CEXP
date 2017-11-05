#include<stdio.h>
#include<stdlib.h>
#define tam 723

typedef struct vertice{
    int aresta;
    int MSP;
    char* nome;
} vertice;

void inicializa(vertice m[tam][tam], int v);
void conecta(vertice m[tam][tam], int a, int b);
int adjacente(vertice m[tam][tam], int a, int b);
void menu(vertice g[tam][tam]);

int main ()
{
    vertice grafo[tam][tam];

    inicializa(grafo,0);

}

/***************************************************************************/

void menu(vertice g[tam][tam]){
   int opcao;
   system("clear");
   printf("                             TRABALHO DE ED II     -     GRAFOS\n\n\n");
   printf("           [7]                  Sair");
   printf("\n\n");
   printf("Digite a sua opcao: ");
   scanf("%d",&opcao);
      while((opcao!=1)&&(opcao!=2)&&(opcao!=3)&&(opcao!=4)&&(opcao!=5)&&(opcao!=6)&&(opcao!=7))
         {
            system("clear");
            printf("           [7]            Sair");
            printf("\n\n");
            printf("Digite a sua opcao: ");
            scanf("%d",&opcao);
         }
      if(opcao==7)
         {
            exit(1);
         }
}

/***************************************************************************/
void inicializa(vertice m[tam][tam], int v){
   int i,j;
   i=j=0;
      while(i!=7){
               while(j!=7){
                    m[i][j].aresta = v;
                    m[i][j].MSP = 0;
                    j++;
                  }
            j=0;
            i++;
         }
}

/***************************************************************************/
void conecta(vertice m[tam][tam], int a, int b){
    m[a][b].aresta = 1;
    m[b][a].aresta = 1;
}
/***************************************************************************/
int adjacente(vertice m[tam][tam], int a, int b){
    if(m[a][b].aresta == 0){
        return(0);
    }
    else{
        return(1);
    }
}
