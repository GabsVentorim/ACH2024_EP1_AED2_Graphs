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