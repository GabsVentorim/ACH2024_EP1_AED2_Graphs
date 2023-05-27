ep1_matriz.exe: grafo_matrizAdj.o ep1.o 
	gcc -o ep1_matriz.exe grafo_matrizAdj.o ep1.o 

ep1_lista.exe: grafo_listaAdj.o ep1.o
	gcc -o ep1_lista.exe grafo_listaAdj.o ep1.o 

grafo_matrizAdj.o: grafo_matrizAdj.c grafo_matrizAdj.h
	gcc -c grafo_matrizAdj.c

grafo_listaAdj.o: grafo_listaAdj.c grafo_listaAdj.h
	gcc -c grafo_listaAdj.c

ep1.o: ep1.c grafo_matrizAdj.h grafo_matrizAdj.c grafo_listaAdj.h grafo_listaAdj.c
	gcc -c ep1.c

clean:
	rm -f *.o *.exe