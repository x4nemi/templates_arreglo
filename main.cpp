#include "arreglo.h"
#include "computadora.h"

using namespace std;

int main(){
    Arreglo<Computadora> compus;

    Computadora c1("ruby", "linux", "pentium", 8.0);
    Computadora c2("hp", "windows", "pentium", 4.0);
    Computadora c3("dell", "macOs", "i5", 8.0);
    compus << c1 << c2 << c3 << c2 << c1;

    Computadora c4("hp", "windows", "pentium", 4.0);

    Arreglo<Computadora*> ptr = compus.buscarTodos(c4);

    if(ptr.size() > 0){
        for(size_t i = 0; i < ptr.size(); i++){
            Computadora *c = ptr[i];

            cout << *c << endl;
        }
    }

    else{
        cout << "No existe" << endl;
    }
    
    return 0;
}