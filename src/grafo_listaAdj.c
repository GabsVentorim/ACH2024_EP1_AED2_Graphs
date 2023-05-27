#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grafo_listaAdj.h"

// O(v)
bool inicializaGrafo(Grafo *grafo, int nv)
{
    if (nv <= 0)
    {
        fprintf(stderr, "ERRO em inicializaGrafo: Num de vert. deve ser positivo");
        return false;
    }
    grafo->numVertices = nv;
    if (!(grafo->listaAdj = (Apontador *)calloc(nv, sizeof(Apontador))))
    {
        fprintf(stderr, "ERRO em inicializaGrafo: Falha na alocacao de memoria");
        return false;
    }
    grafo->numArestas = 0;
    return true;
}

// O(1)
bool verificaValidadeVertice(int v, Grafo *grafo)
{
    if (v < 0 || v >= grafo->numVertices)
    {
        fprintf(stderr, "ERRO: verificaValidadeVertice vertice %d invalido\n", v);
        return false;
    }
    return true;
}

// O(v)
bool existeAresta(int v1, int v2, Grafo *grafo)
{
    Apontador q;
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;
    q = grafo->listaAdj[v1];
    while ((q != NULL) && (q->vdest != v2))
        q = q->prox;
    if (q != NULL)
        return true;
    return false;
}

// O(1)
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo)
{

    Apontador p, q;
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;

    if (!(p = (Apontador)calloc(1, sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao em insereAresta");
        return false;
    }

    if (!(q = (Apontador)calloc(1, sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao em insereAresta");
        return false;
    }

    p->vdest = v2;
    p->peso = peso;
    p->prox = grafo->listaAdj[v1]; // insere no inicio da lista de adjacentes
    grafo->listaAdj[v1] = p;
    grafo->numArestas++;

    q->vdest = v1;
    q->peso = peso;
    q->prox = grafo->listaAdj[v2]; // insere no inicio da lista de adjacentes
    grafo->listaAdj[v2] = q;
    grafo->numArestas++;

    return true;
}

// O(a)
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo)
{
    Apontador p;
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return AN;
    p = grafo->listaAdj[v1];
    while (p != NULL)
    {
        if (p->vdest == v2)
            return p->peso;

        p = p->prox;
    }
    return AN;
}