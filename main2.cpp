/*#include "raiz.h"
//#include <sstream>
//#include <fstream>
//#include <algorithm>  ya están incluidas de antes, las dejo como comentario para que sepa qué se usó
//#include <chrono>
//#include <cstdlib>}
#define Archivo "worldcitiespop_fixed.csv"
int main() {
    double latmax = -200;
    double latmin = 200;

    double lonmax = -200; //inicializamos las capacidades minimas y maximas con valores que si o si van a superar.
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
    while (getline(archivo, linea)  && j < 3200000)
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


        double num1_double = std::stod(Latitude) ;
        double num2_double = std::stod(Longitude) ;  // se convierten
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
    // podria añadir directamente los puntos, pero no podríamos tener latmin,lonmin,latmax,lonmax. Además, calcular cuanto tarda en insertarse
                      //es más directo de esta forma.
    }
    archivo.close();
    QuadArbol plano(Point(latmin, lonmin), Point(latmax, lonmax)); //el arbol se crea en base a los datos más extremos
    cout << "latmax: " << latmax << endl;
        cout << "latmin: " << latmin << endl;
        cout << "lonmax: " << lonmax << endl;
        cout << "lonmin: " << lonmin << endl;
    for (int i = 0; i < j; i++) {
     //    cout << "nodossssss latitudee" << stacknodo.top()->pos.x << endl;  //esto es solo para ver que quedaron correctamente en el stack
        plano.insert(stacknodo.top()->pos, stacknodo.top()->data);
    
     // Node* p = plano.search(stacknodo.top()->pos);
       // if (p != NULL) cout << p->data << endl;   // comprobaremos que se hayan insertado
       // else cout << "No existe el punto." << endl; 
       
stacknodo.pop();
    }



    //Preorder para recorrer
    plano.preorder(plano.getraiz());
    cout << endl;
    //solo toma los nodos negros
    cout << "Cantidad de nodos: " << plano.totalNodes() << endl;
    cout << endl;




    cout << "Cantidad de puntos: " << plano.countRegion(Point(latmin, lonmin), 360) << endl; //ejemplo en canvas




    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 20; i++) {
        cout << "Poblacion estimada: " << plano.AggregateRegion(Point(latmin, lonmin), 360) << endl; //ejemplo en canvas
    }
    auto end = chrono::steady_clock::now();  //esto usamos para calcular el tiempo



    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

    cout << "Elapsed time in microseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;

    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

    cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";















    return 0;
}
*/











