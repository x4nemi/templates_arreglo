#include "computadora.h"

using namespace std;

Computadora::Computadora(){ }

Computadora::Computadora(const string &nombre, const string &SO, const string &procesador, float RAM){
    this->nombre = nombre;
    this->SO = SO;
    this->procesador = procesador;
    this->RAM = RAM;
}

void Computadora::setNombre(const string &n){
    nombre = n;
}

void Computadora::setSO(const string &s){
    SO = s;
}

void Computadora::setProcesador(const string &p){
    procesador = p;
}

void Computadora::setRAM(int r){
    this->RAM = r;
}

string Computadora::getNombre(){
    return nombre;
}

string Computadora::getSO(){
    return SO;
}
string Computadora::getProcesador(){
    return procesador;
}

float Computadora::getRAM(){
    return RAM;
}