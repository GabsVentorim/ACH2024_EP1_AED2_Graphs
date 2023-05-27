#include <stdbool.h>

#define VERT_INVALIDO NULL
#define AN -1

typedef float Peso;

typedef struct s
{
    int vdest;
    Peso peso;
    struct s *prox;
} Aresta;

typedef struct
{
    Aresta **listaAdj; // vetor de vetores
    int numVertices;
    int numArestas;
} Grafo;

typedef Aresta *Apontador;