#include "quadtree.h"
#include <bits/stdc++.h>


#define Archivo "worldcitiespop_fixed.csv"


/*
vector<Node> leer(int numeroDeLineas){
    vector<Node> ciudades;
    Node nodo;

    string citya;
    string country;
    string accentcity;

    double x;
    double y;
    string X;
    string Y;

    double population;
    string POPULATION;

    
    int region;
    string REGION;

    ifstream archivo(Archivo);
    string linea;
    char delimitador = ';';

    getline(archivo, linea);
    for (int i = 0; i < numeroDeLineas; i++)
    {
        getline(archivo, linea);
        stringstream lineaactual(linea);
        getline(lineaactual,country,delimitador);
        getline(lineaactual,citya,delimitador);
        getline(lineaactual,accentcity,delimitador);
        getline(lineaactual,REGION,delimitador);
        getline(lineaactual,POPULATION,delimitador);
        getline(lineaactual,X,delimitador);
        getline(lineaactual,Y,delimitador);


        replace(X.begin(), X.end(), ',', '.');
        replace(Y.begin(), Y.end(), ',', '.');

        population = stod(POPULATION);
        x= stod(X);
        y = stod(Y);
        
        nodo.data = population;
        nodo.pos.x = x;
        nodo.pos.y = y;
        

        
        ciudades.push_back(nodo);
    }


    

    archivo.close();
    return ciudades;
    
}

int main(){
    int n = 100;
    vector<Node> citys;
    citys = leer(n);
    for (int i = 0; i < n; i++)
    {
        cout << citys[i].pos.x << ","<< citys[i].pos.y << "      Data: "<<citys[i].data<< endl;
    }
    
    

}*/