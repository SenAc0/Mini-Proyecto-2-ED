/*#include "raiz.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
#define Archivo "worldcitiespop_fixed.csv"
int main() {
    double latmax = -200;
    double latmin = 200;

    double lonmax = -200;
    double lonmin = 200;

   
    ///////////////// desde acá probaremos lo del archivo
    stack<Node*> stacknodo;
    ifstream archivo(Archivo);

    string linea;
    char delimitador = ';';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    int j = 0;
    while (getline(archivo, linea)  && j < 20)
    {
        j++;
        stringstream stream(linea); // Convertir la cadena a un stream
        string Country, City, AccentCity, Region, Population, Latitude, Longitude, geopoint;
        // Extraer todos los valores de esa fila
        getline(stream, Country, delimitador);
        getline(stream, City, delimitador);
        getline(stream, AccentCity, delimitador);
        getline(stream, Region, delimitador);
        getline(stream, Population, delimitador);
        getline(stream, Latitude, delimitador);
        getline(stream, Longitude, delimitador);
        getline(stream, geopoint, delimitador);
        // Imprimi

        std::replace(Latitude.begin(), Latitude.end(), ',', '.');  //reemplazamos, porque sino no lo lee como decimales.
        std::replace(Longitude.begin(), Longitude.end(), ',', '.');


        double num1_double = std::stod(Latitude);
        double num2_double = std::stod(Longitude);  // se convierten
        int num3_int = std::stoi(Population);
        Node* nodo = new Node(Point(num1_double, num2_double), num3_int); //creamos un  nodo, es necesario para almacenarlos en un stack

        if (num1_double > latmax) {
            latmax = num1_double;
        }
        if (num1_double < latmin) {
            latmin = num1_double;
        }
        if (num2_double > lonmax) {
            lonmax = num2_double;
        }
        if (num2_double < lonmin) {
            lonmin = num2_double;
        }

        stacknodo.push(nodo);  // se almacena
     /*   cout << "==================" << endl;
        cout << "Latitude nodo: " << nodo->pos.x << endl;  //para comprobar
        cout << "Longitude nodo:" << nodo->pos.y << endl;
        cout << "Pop nodo: " << nodo->data << endl;

        
    }
    archivo.close();
    QuadArbol plano(Point(latmin, lonmin), Point(latmax, lonmax));
    for (int i = 0; i < j; i++) {
        //   cout << "nodossssss latitudee" << stacknodo.top()->pos.x << endl;  //esto es solo para ver que quedaron correctamente en el stack
        plano.insert(stacknodo.top()->pos, stacknodo.top()->data);


        Node* p = plano.search(stacknodo.top()->pos);
        if (p != NULL) cout << p->data << endl;   // comprobaremos que se hayan insertado
        else cout << "No existe el punto." << endl; // en el ejemplo que doy, hay uno que no se introdujo, debido a que su longitud sobrepasa los 100

        stacknodo.pop();
    }
    cout << "Agreggate region "<<plano.AggregateRegion(Point((latmax+latmin)/2,(lonmax+lonmin)/2),400)<<endl;




    

}


*/











