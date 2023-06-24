/*#include "quadtree.h"
#include <bits/stdc++.h>


#define Archivo "worldcitiespop_fixed.csv"

vector<pair<Point,Data>> leer(int numeroDeLineas){
    vector<pair<Point,Data>> ciudades;
    Data tempdata;
    Point temppoint;
    string citya;
    string country;
    double x;
    double y;
    string X;
    string Y;
    double population;
    string POPULATION;
    string accentcity;
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

        tempdata.city = citya;
        population = stod(POPULATION);
        tempdata.population = population;
        x= stod(X);
        y = stod(Y);
        temppoint.x = x;
        temppoint.y = y;

        
        ciudades.push_back({temppoint, tempdata});
    }


    

    archivo.close();
    return ciudades;
    
}

int main(){
    int n = 100;
    vector<pair<Point,Data>> citys;
    citys = leer(n);
    for (int i = 0; i < n; i++)
    {
        cout << citys[i].first.x << ","<< citys[i].first.y<< " " << citys[i].second.city << " " << citys[i].second.population<<endl;
    }
    
    

}*/