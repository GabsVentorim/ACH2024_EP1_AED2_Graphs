#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DEVE-SE COMENTAR UM DESSES INCLUDES PARA ESCOLHER A IMPLEMENTACAO DO GRAFO

// #include "grafo_matrizadj.h"
#include "grafo_listaadj.h"

#define inf 9999;

int main(int argc, char **argv)
{
    int i;

    Grafo grafo;

    // num de argumentos deve ser 2
    // Ex: arq.exe entrada.txt
    if (argc != 2)
    {
        fprintf(stderr, "Erro: quantidade de argumentos\n");
    }

    FILE *arq_ent = fopen(argv[1], "r");
    if (!arq_ent)
    {
        fprintf(stderr, "Erro: ponteiro do arq_ent\n");
    }

    int numVertices, numArestas, numConsultas;
    if (fscanf(arq_ent, "%d %d %d", &numVertices, &numArestas, &numConsultas) != 3)
    {
        fprintf(stderr, "Erro: falha na leitura da primeira linha\n");
    }

    int v, u;
    float peso;
    for (i = 1; i <= numArestas; i++)
    {
        if (fscanf(arq_ent, "%d %d %f", &v, &u, &peso) != 3)
        {
            fprintf(stderr, "Erro: falha de leitura de: v u peso\n");
        }
    }

    int partida, chegada;
    for (i = 1; i <= numConsultas; i++)
    {
        if (fscanf(arq_ent, "%d %d", &partida, &chegada) != 2)
        {
            fprintf(stderr, "Erro: falha de leitura das consultas\n");
        }
    }

    fclose(arq_ent);

    return 0;
}
