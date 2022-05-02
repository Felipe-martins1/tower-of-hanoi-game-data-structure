#include <stdio.h>
#include <stdlib.h>
#include "./pilha.h"

//Retorna se o valor pode ser inserido na pilha -- Função de auxilio para popular a pilha
int ValorValido(Pilha pilhas[], int n, int valor){
    int quantidadeValorAparece = 0;
    int numPilhas = n+2;
    int i,j;
    for(j=0;j<numPilhas;j++){
        for(i=0;i<4;i++){
            if(pilhas[j].elem[i] == valor){
                quantidadeValorAparece++;
            }
        }
    } 

   return quantidadeValorAparece < 4;
}

//Popula Pilha
int PopulaPilha(Pilha pilha[MAXSIZE], int n, Pilha pilhas[]){
    for(int i = 0; i < 4; i++){
        int val = 1 + rand()%(n);
        while(!ValorValido(pilhas, n, val)){
            val = 1 + rand()%(n);
        }
        Empilha(pilha, val); 
    }
}

//Realiza Jogada
int Jogada(Pilha pilha1[MAXSIZE], Pilha pilha2[MAXSIZE]){
    int aux;
    aux = Desempilha(pilha1);
    Empilha(pilha2,aux);
}


//Mostra as pilhas no terminal
int PrintPilhas(Pilha pilhas[], int numPilhas){
    int i,j;
    for(j=0;j<numPilhas;j++){
        printf("\nPilha %d: ",j+1);
        for(i=0;i<4;i++){
            if(i > pilhas[j].topo){
                printf("_ ");
            }else{
                printf("%d ", pilhas[j].elem[i]);
            }
        }
        if(!PilhaVazia(pilhas[j])){
            printf(" <-- Topo");
        }
        printf("\n");
    } 
}


//Retorna se o jogo terminou(Jogador ganhou)
int JogoTerminou(Pilha pilhas[], int numPilhas){
    int i,j;
    int pilhasIguais = 0;
    for(j=0;j<numPilhas;j++){
        if(!PilhaVazia(pilhas[j])){
            int elementosIguais = 4;
            for(i=1;i<4;i++){
                if(pilhas[j].elem[i] != pilhas[j].elem[i+1]){
                    elementosIguais--;
                    break;
                }
            }
            if(elementosIguais == 4){
                pilhasIguais++;
            }
        }else{
            pilhasIguais++;
        }
    }

    return pilhasIguais == numPilhas - 2;
}

int main(){   
    int n, j, i, numPilhas;

    printf("Quantos numeros diferentes serao distribuidos entre as pilhas?\n");
    scanf("%d",&n);

    numPilhas = n + 2;

    Pilha pilhas[numPilhas];

    printf("\n\n\nIniciando o jogo...\n");

    for(i=0;i<numPilhas;i++){
        InicializaPilha(pilhas+i);
        if(i < n){
            PopulaPilha(pilhas+i, n, pilhas);
        }
    }

    printf("\n\n\nBoa sorte!:\n\n");

    PrintPilhas(pilhas, numPilhas);

    while(!JogoTerminou(pilhas, numPilhas)){
        int pilhaSaida, pilhaEntrada;
        printf("\nQual pilha voce quer desempilhar?\n");
        scanf("%d",&pilhaSaida );
        printf("\nQual pilha voce quer empilhar?\n");
        scanf("%d",&pilhaEntrada);

        pilhaSaida--;
        pilhaEntrada--;

        if(pilhaEntrada < 0 || pilhaSaida < 0){
            printf("\n\nPor favor, digite um valor valido.\n\n");
        }else if(pilhaSaida == pilhaEntrada){
            printf("\nPilhas iguais! tente novamente.\n");
        }else{
            if(PilhaVazia(pilhas[pilhaSaida])){
                printf("\nA Pilha de saida esta Vazia!\n");
            }else if(PilhaCheia(pilhas[pilhaEntrada])){
                printf("\nA Pilha de entrada esta cheia!\n");
            }else if(PilhaVazia(pilhas[pilhaEntrada])){
                Jogada(pilhas+pilhaSaida, pilhas+pilhaEntrada);
            }else{
                if(ElementoDoTopo(pilhas[pilhaSaida]) == ElementoDoTopo(pilhas[pilhaEntrada])){
                    Jogada(pilhas+pilhaSaida, pilhas+pilhaEntrada);
                }else{
                    printf("\n\nJogada Invalida! tente novamente.\n\n");
                }
            }
        }
        PrintPilhas(pilhas, numPilhas);
    }

    printf("\n\n\n\nParabens! Voce ganhou!\n\n\n\n");
}