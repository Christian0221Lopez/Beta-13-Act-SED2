#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <vector>
#include <algorithm>
#include "Prototipo.h"

int MatrizAdj[300][300];
int matrizIncidencia[300][300];

void Graph::AddNode()
{
    cout << "\t\tAgregar Nodo #"<<cont<<endl;
    cout << "\tAgrega Nombre: "<<endl;
    std::getline(cin,this[cont].Data);
    this[cont].id = cont;
    cont++;

}

void Graph::AddEdges()
{
    int Origen = 0;
    int Destino = 0;

    cout << "\t\tAgregar Arista #"<<cont<<endl;
    cout << "\tAgrega Nodo Origen: "<<endl;
    cin >> Origen;
    cout << "\tAgrega Nodo Destino: "<<endl;
    cin >> Destino;

    MatrizAdj[Origen][Destino] = 1;
    this[Origen].Arista[Destino] = Destino;
    this[Origen].Adyacencia[Destino] = 1;

    cout <<"Origen "<<Origen<<" Destino "<<this[Origen].Arista[Destino]<<" Marcado en matriz "<<this[Origen].Adyacencia[Destino]<<endl;

}

void Graph::RemoveNode() {
    int ID = 0;

    cout << "\t\tRemover Nodo" << endl;
    cout << "\tID: ";
    cin >> ID;

    bool nodeFound = false;
    int nodeIndex = -1;
    for (int i = 0; i < cont; i++) {
        if (this[i].id == ID) {
            nodeFound = true;
            nodeIndex = i;
            break;
        }
    }

    if (nodeFound) {
        // Eliminar el nodo
        for (int i = nodeIndex; i < cont - 1; i++) {
            this[i] = this[i + 1];
            this[i].id = this[i + 1].id;
            this[i].Arista[i] = this[i + 1].Arista[i];
        }
        cont--;
        cout << "Nodo eliminado" << endl;
    } else {
        cout << "\n\tEl nodo no existe..!" << endl;
    }

    cout << endl;
}

void Graph::RemoveEdges()
{
    int Origen = 0;
    int Destino = 0;

    cout << "\t\tRemover Arista "<<endl;
    cout << "\tNodo Origen: "<<endl;
    cin >> Origen;
    cout << "\tNodo Destino: "<<endl;
    cin >> Destino;

    bool edgeFound = false;
    bool node1Found = false;
    bool node2Found = false;

    for (int i = 0; i < cont; i++)
        {
        if (this[i].id == Origen)
        {
            node1Found = true;
            cout << "El nodo existe." << endl;
            for (int j = 0; j < 300; j++)
            {
                if (this[j].id == Destino)
                {
                    cout << "El nodo existe22." << endl;
                    this[Origen].Arista[Destino] = 0;
                    this[Origen].Adyacencia[Destino] = 0;
                    edgeFound = true;
                    node2Found = true;
                    break;
                }
                }
            if (edgeFound) {
                break;
            }
        }
    }

    if (node1Found && !node2Found) {
        cout << "El nodo destino no existe." << endl;
    } else if (!node1Found && node2Found) {
        cout << "El nodo origen no existe." << endl;
    } else if (!node1Found && !node2Found) {
        cout << "Ambos nodos no existen." << endl;
    } else if (edgeFound) {
        cout << "Arista eliminada." << endl;
    } else {
        cout << "La arista no existe." << endl;
    }
}

void Graph::Save()
{
    ofstream File("Grafo.txt");
    int i = 0;

    if (!File)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }

    for (i=0; i<cont; i++)
    {
        File << "Nombre--------------: " << this[i].Data<<endl;
        File << "ID--------------: " << this[i].id<<endl;
        File << "Aristas--------------: ";
        for (int j=0; j<cont; j++)
        {
            if (this[i].Arista[j] != 0)
            {
                File << i << " (" << this[i].Arista[j] << ") ";
            }
        }
        File << endl;
    }


    File << "  ";
    for (int i = 0; i < 193; i++)
    {
        File << i << " ";
    }
    File << endl;

    for (int i = 0; i < 193; i++)
    {
        File << i << " ";
        for (int j = 0; j < 193; j++)
    {
            File << this[i].Adyacencia[j] << " ";
    }
    File << endl;
    }

    File << " ";
    for (int i = 0; i < 193; i++) {
        File << i << " ";
    }
    File << endl;

    for (int i = 0; i < 193; i++) {
        File << i << " ";
        for (int j = 0; j < 193; j++) {
            File << this[i].Incidencia[j] << " ";
        }
        File << endl;
    }

    File.close();
}

void Graph::Remove()
{
    int numNodes = cont;

    while (numNodes > 0)
    {
        int maxID = -1;
        int maxIDIndex = -1;
        for (int i = 0; i < cont; i++) {
            if (this[i].id > maxID) {
                maxID = this[i].id;
                maxIDIndex = i;
            }
        }

        for (int i = 0; i < cont; i++) {
            for (int j = 0; j < cont; j++) {
                if (this[i].Arista[j] == maxID) {
                    for (int k = j; k < cont - 1; k++) {
                        this[i].Arista[k] = this[i].Arista[k + 1];
                    }
                    cont--;
                }
            }
        }

        // Eliminar el nodo
        for (int i = maxIDIndex; i < cont - 1; i++) {
            this[i] = this[i + 1];
        }
        cont--;
        numNodes--;
    }

    cout << "Grafo eliminado" << endl;
}


void Graph::Matrices()
{
    // Imprimir encabezado
    cout << "  ";
    for (int i = 0; i < 193; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // Imprimir matriz de adyacencia
    for (int i = 0; i < 193; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 193; j++)
    {
            cout << this[i].Adyacencia[j] << " ";
    }
    cout << endl;
    }

    cout << " ";
    for (int i = 0; i < 193; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Imprimir matriz de adyacencia
    for (int i = 0; i < 193; i++) {
        cout << i << " ";
        for (int j = 0; j < 193; j++) {
            cout << this[i].Incidencia[j] << " ";
        }
        cout << endl;
    }

}

void Graph::Show()
{
   int i = 0;
   int op = 0;
    system("cls");

    for (i=0; i<cont; i++)
    {
        cout << "Nombre--------------: " << this[i].Data<<endl;
        cout << "ID--------------: " << this[i].id<<endl;
        cout << "Aristas--------------: ";
        for (int j=0; j<cont; j++)
        {
            if (this[i].Arista[j] != 0)
            {
                cout << i << " (" << this[i].Arista[j] << ") ";
            }
        }
        cout << endl;
    }

    cout << "\t\tDeseas Mostrar la matriz? : " <<endl;
    cin >> op;

    if(op != 2)
    {
        this->Matrices();
    }
}


void Graph::Insertar(string var)
{
    ifstream File(var);
    ofstream Matriz("Matriz de Adyacencia.txt");
    ofstream MatrizInd("Matriz de Incidencia.txt");
    string oracion;
    int i = 0;
    int ID;
    string Entero;
    string Limpio;
    int vectors;

    for(int i = 0;i<=200;i++)
    {
        for(int j = 0;j<=200;j++)
        {
            MatrizAdj[i][j] = 0;
        }
    }

    if (!File)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }


    std::getline(File, oracion, '\n');
    int Tam = std::stoi(oracion);
    std::getline(File, oracion, '\n');
    int Encabezado = std::stoi(oracion);
    cout <<Tam<< endl;
    cout <<Encabezado<< endl;
    oracion = '\0';

        for(i = 0;i <= Tam;i++)
        {
            if(i<=Encabezado)
            {
            if (!std::getline(File, oracion, '\n'))
            {
                cout << "Error: el archivo no tiene suficientes líneas" << endl;
                return;
            }
            if(i<100)
            {
                Entero = oracion.substr(0, 2);
                int Id = std::stoi(Entero);
                Limpio = oracion.substr(2, 30);
                this[cont].id = Id;
                this[cont].Data = Limpio;
                cont++;
            }
            else
            {
                Entero = oracion.substr(0, 3);
                int Id = std::stoi(Entero);
                Limpio = oracion.substr(3, 30);
                this[cont].id = Id;
                this[cont].Data = Limpio;
                cont++;
            }
            }
            else
            {
                   while (std::getline(File, oracion, ','))
                   {
                    try
                    {
                        ID = std::stoi(oracion);
                    }
                            catch(const std::invalid_argument& e) {
                            cout << "Error: el valor de código no es un entero válido" << endl;
                            return;
                        }
                    cout << ID <<",";
                    if (!std::getline(File, oracion, '\n'))
                    {
                        cout << "Error: el archivo no tiene suficientes líneas" << endl;
                        return;
                    }

                    try
                    {
                        vectors = std::stoi(oracion);
                    }
                            catch(const std::invalid_argument& e) {
                            cout << "Error: el valor de código no es un entero válido" << endl;
                            return;
                        }
                    //int vectors = std::atoi(oracion.c_str());
                    cout << vectors << endl;

                    MatrizAdj[ID][vectors] = 1;
                    this[ID].Arista[vectors] = vectors;
                    numEdges++;
                    this[ID].Adyacencia[vectors] = 1;
                   }

            }
        }

if (!Matriz)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }

    Matriz << "  ";
    for (int i = 0; i < 193; i++) {
        Matriz << i << " ";
    }
    Matriz << endl;

    // Imprimir matriz de adyacencia
    for (int i = 0; i < 193; i++) {
        Matriz << i << " ";
        for (int j = 0; j < 193; j++) {
            Matriz << MatrizAdj[i][j] << " ";
        }
        Matriz << endl;
    }

// Contar el número de aristas
int numAristas = 0;
for (int i = 0; i < 193; i++) {
    for (int j = i; j < 193; j++) {
        if (MatrizAdj[i][j] == 1) {
            numAristas++;
        }
    }
}


for (int i = 0; i < 193; i++) {
    for (int j = 0; j < numAristas; j++) {
        matrizIncidencia[i][j] = 0;
    }
}
// Llenar la matriz de incidencia
int arista = 0;
for (int i = 0; i < 193; i++) {
    for (int j = i; j < 193; j++) {
        if (MatrizAdj[i][j] == 1) {
            matrizIncidencia[i][arista] = 1;
            matrizIncidencia[j][arista] = 1;
            this[i].Incidencia[arista] = 1;
            this[j].Incidencia[arista] = 1;
            arista++;
        }
    }
}


if (!MatrizInd)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }

    MatrizInd << "  ";
    for (int i = 0; i < 193; i++) {
        MatrizInd << i << " ";
    }
    MatrizInd << endl;

    // Imprimir matriz de adyacencia
    for (int i = 0; i < 193; i++) {
        MatrizInd << i << " ";
        for (int j = 0; j < 193; j++) {
            MatrizInd << matrizIncidencia[i][j] << " ";
        }
        MatrizInd << endl;
    }

    File.close();
    Matriz.close();
    MatrizInd.close();
    cout << "Matriz guardada en archivo" << endl;
}

int Lista::Menu(string var)
{
    int op = 0;
    int salir = 0;
    do
       {
            system("cls");
    cout <<"\t\tGrafos"<<endl;

    cout <<"Menu de Opciones"<<endl;
    cout <<"1.- Agregar"<<endl;
    cout <<"2.- Mostrar"<<endl;
    cout <<"3.- Agregar Nodo"<<endl;
    cout <<"4.- Agregar Arista"<<endl;
    cout <<"5.- Eliminar Nodo"<<endl;
    cout <<"6.- Eliminar Arista"<<endl;
    cout <<"7.- Guardar Grafo"<<endl;
    cout <<"8.- Eliminar Grafo"<<endl;
    cout <<"9.- Salir"<<endl;
    cout <<"Ingresa opcion: ";
    cin >>op;
    getchar();

    switch(op)
    {
    case 1:
        Grafo->Insertar(var);
        break;
    case 2:
        Grafo->Show();
        break;
    case 3:
        Grafo->AddNode();
        break;
    case 4:
        Grafo->AddEdges();
        break;
    case 5:
        Grafo->RemoveNode();
        break;
    case 6:
        Grafo->RemoveEdges();
        break;
    case 7:
        Grafo->Save();
        break;
    case 8:
        Grafo->Remove();
        break;
    case 9:
        exit(-1);
        break;
    }

    cout <<"Deseas Salir?... 1.-Si/2.-No: "<<endl;
    cin >>salir;
system("pause");
   }while(salir != 1);

    return salir;
}
