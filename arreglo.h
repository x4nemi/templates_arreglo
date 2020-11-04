#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>

template <class T>
class Arreglo{
    private:
        T *arreglo;
        size_t dim;
        size_t cont;
        const static size_t MAX = 5;
        void expandir();

    public:
        Arreglo();
        ~Arreglo();

        void insertarInicio(const T&);
        void insertarFinal(const T&);
        void insertar(const T&, const size_t&);

        void eliminar(const size_t& p);
        void eliminarInicio();
        void eliminarFinal();

        T* buscar(const T& v);
        Arreglo<T*> buscarTodos(const T& v);

        size_t size();
        T operator[](size_t p){
            return arreglo[p];
        }

        friend Arreglo<T>& operator<<(Arreglo<T>& a, const T& v){
            a.insertarFinal(v);

            return a;
        }
};

#endif

using namespace std;

template <class T>
Arreglo<T>::Arreglo(){
    arreglo = new T[MAX];
    cont = 0;
    dim = MAX;
}

template <class T>
Arreglo<T>::~Arreglo(){
    delete[] arreglo;
}

template <class T>
void Arreglo<T>::insertarFinal(const T& v){
    if(cont == dim){
        expandir();
    }

    arreglo[cont++] = v;
}

template <class T>
void Arreglo<T>::insertarInicio(const T& v){
    if (cont == dim) {
        expandir();
    }

    for (size_t i = cont; i > 0; i--) {
        arreglo[i] = arreglo[i - 1]; 
    }
    arreglo[0] = v;
    cont++;
}

template <class T>
void Arreglo<T>::expandir(){
    T *nuevo = new T[dim + MAX];

    for(int i = 0; i < cont; i++){
        nuevo[i] = arreglo[i];
    }

    delete[] arreglo;
    arreglo = nuevo;
    dim += MAX;

}

template <class T>
size_t Arreglo<T>::size(){
    return cont;
}

template <class T>
void Arreglo<T>::insertar(const T& v, const size_t& p){
    if(p >= cont){
        cout << "Posicion invalida" << endl;
        return;
    }
    
    if (cont == dim) {
        expandir();
    }

    for (size_t i = cont; i > p; i--) {
        arreglo[i] = arreglo[i - 1]; 
    }

    arreglo[p] = v;
    cont++;
}

template <class T>
void Arreglo<T>::eliminarFinal(){
    if(cont == 0){
        cout << "Arreglo vacio" << endl;
        return;
    }

    cont--;
}

template <class T>
void Arreglo<T>::eliminarInicio(){
    if(cont == 0){
        cout << "Arreglo vacio" << endl;
        return;
    }

    for(int i = 0; i < cont - 1; i++){
        arreglo[i] = arreglo[i + 1];
    }

    cont--;
}

template <class T>
void Arreglo<T>::eliminar(const size_t& p){

    if(cont == 0){
        cout << "Arreglo vacio" << endl;
        return;
    }

    for(size_t i = p; i < cont - 1; i++){
        arreglo[i] = arreglo[i + 1];
    }

    cont--;
}

template <class T>
T* Arreglo<T>::buscar(const T& v){
    for(size_t i = 0; i < cont; i++){
        if(v == arreglo[i]){
            return &arreglo[i];
        }
    }

    return nullptr;
}


template <class T>
Arreglo<T*> Arreglo<T>::buscarTodos(const T& v){
    Arreglo<T*> ptrs;

    for(size_t i = 0; i < cont; i++){
        if(v == arreglo[i]){
            ptrs.insertarFinal(&arreglo[i]);
        }
    }

    return ptrs;
}