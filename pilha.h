#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 4

typedef struct pilha{
  int elem[MAXSIZE];      
  int topo;
} Pilha;

//Inicializando
void InicializaPilha (Pilha *pilha){
    pilha->topo = -1;  
}   

//Retorna se pilha cheia
int PilhaCheia(Pilha pilha){
  return pilha.topo == MAXSIZE - 1;  
}

//Retorna se pilha vazia
int PilhaVazia(Pilha pilha){
  return pilha.topo == -1; 
}

//Empilhando
void Empilha(Pilha *pilha, int x){
  if(!PilhaCheia(*pilha)){
    pilha->topo++;
    pilha->elem[pilha->topo] = x;
  }
}


//Desempilhando
int Desempilha(Pilha *pilha){
  if(!PilhaVazia(*pilha)){
    int aux = pilha->elem[pilha->topo];
    pilha->topo--;
    return aux;
  }
}

//Retorna Elemento do Topo
int ElementoDoTopo(Pilha pilha){  
  if(!PilhaVazia(pilha)){
    return pilha.elem[pilha.topo];  
  }else{
    printf("Pilha Vazia\n"); 
  }
}