#include "arreglo.h"

using namespace std;

int main(){
    Arreglo<string> arreglo;
    arreglo.insertarFinal("magenta");
    arreglo.insertarFinal("azul");
    arreglo.insertarInicio("Los colores son");
    arreglo.insertarFinal("y morado");
    
    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;
    arreglo.insertar(",", 2);

    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;

    arreglo.eliminarInicio();
    arreglo.eliminarFinal();
    arreglo.eliminar(1);

    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }

    
    return 0;
}