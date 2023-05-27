#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1
#define VERT_INVALIDO -1

typedef float Peso;

typedef struct
{
    Peso mat[MAXNUMVERTICES][MAXNUMVERTICES];
    int numVertices;
    int numArestas;
} Grafo;

bool inicializaGrafo(Grafo *grafo, int nv);
bool existeAresta(int v1, int v2, Grafo *grafo);
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo);
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo);