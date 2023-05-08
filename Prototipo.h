#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <vector> // incluir la librería vector

#include "Prototipo.h"

using namespace std;

class Graph
{
private:
    int cont;
    int id;
	string Data;
	int Arista[300];
	int numEdges;
	int Adyacencia[300];
	int Incidencia[300];
    friend class Lista;
public:
    void Insertar(string);
    void Show();
    void AddEdges();
    void AddNode();
    void RemoveNode();
    void RemoveEdges();
    void Save();
    void Remove();
    void Matrices();
};

class Lista
{
private:
    Graph Grafo[500];
    friend class Graph;
public:
    int Menu(string var);
};



#endif // PROTOTIPO_H_INCLUDED
