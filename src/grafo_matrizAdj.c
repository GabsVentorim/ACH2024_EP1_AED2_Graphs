#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grafo_matrizAdj.h"

// O(v^2)
bool inicializaGrafo(Grafo *grafo, int nv)
{
    int i, j;
    if (nv > MAXNUMVERTICES)
    {
        fprintf(stderr, "ERRO na chamada de inicializarGrafo: num max de grafos eh %d\n", MAXNUMVERTICES); // saida de erro
        return false;
    }

    if (nv <= 0)
    {
        fprintf(stderr, "ERRO na chamada de inicianlizarGrafo: num de grafos deve ser positivo\n"); // saida de erro
        return false;
    }
    grafo->numArestas = 0;
    grafo->numVertices = nv;
    // se for 0 -> i = 0; i < nv
    // se for 1 -> i = 1; i <= nv
    for (i = 0; i < nv + 1; i++)
    {
        for (j = 0; j < nv + 1; j++)
        {
            grafo->mat[i][j] = AN;
        }
    }
    return true;
}

// O(1)
bool verificaValidadeVertice(int v, Grafo *grafo)
{
    if (v > grafo->numVertices)
    {
        fprintf(stderr, "ERRO: Num do vert %d maior que o total %d\n", v, grafo->numVertices);
        return false;
    }
    /** se quiser aresta 0 tirar o = **/
    if (v < 0)
    {
        fprintf(stderr, "ERRO: Num de vert %d deve ser positivo\n", v);
        return false;
    }
    return true;
}

// O(1)
bool existeAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && (verificaValidadeVertice(v2, grafo))))
        return false;
    if (grafo->mat[v1][v2] == AN)
    {
        return false;
    }
    return true;
}

// O(1)
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && (verificaValidadeVertice(v2, grafo))))
        return false;

    // eh nao direcionado
    grafo->mat[v1][v2] = peso;
    grafo->mat[v2][v1] = peso;
    grafo->numArestas++;
    return true;
}

// O(v)
void imprime(Grafo *grafo)
{
    int i, j;
    // se for 0 -> i = 0; i < nv
    // se for 1 -> i = 1; i <= nv
    for (i = 0; i < grafo->numVertices; i++)
    {
        for (j = 0; j < grafo->numVertices; j++)
        {
            printf("%.1f ", grafo->mat[i][j]);
        }
        printf("\n");
    }
}

// O(1)
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && (verificaValidadeVertice(v2, grafo))))
        return AN;
    // printf("obtem peso: %d - %d -> %.1f\n", v1, v2, (grafo)->mat[v1][v2]);
    return (grafo)->mat[v1][v2];
}
