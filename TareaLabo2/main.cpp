#include <fstream>
#include <iostream>
#include "classes.h"

using namespace std;

void readCoordinates(ifstream &file, int n, item* item_list){
    //Como utilizaremos el método setIntFloat declararemos la variable entera y flotante respectivamente
    int e; float r;
    for(int i=0; i<n; i++){
      file >> e >> r;
      item_list[i].setIntFloat(e,r);
    }
}


int main() {
    char filename[10];
    string line;
    mesh m;
    ifstream file;
    float k,Q;
    int nnodes,neltos,ndirich,nneu;

    do{
        cout << "Ingrese el nombre del archivo: ";
        cin >> filename;
        file.open(filename);
    }while(!file);

    file >> k >> Q;
    file >> nnodes >> neltos >> ndirich >> nneu;

    file >> line;
    //Seteamos con los valores de K y Q como nos lo muestra  en classes.h
    m.setParameters(k, Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.createData();
    //Éste método tendrá 3 valores como parámetro, earchivo, número de nodos y donde nos retornará el valor del nodo
    readCoordinates(file,nnodes,m.getNodes());

    file.close();

    //Éste for nos permitirá que nos retorne nodo por nodo obteniendo el valor de cada nodo en la malla
    for(int i=0;i<nnodes;i++){
        cout<<m.getNode(i).getX();
        cout <<endl;
    }

    return 0;
}
