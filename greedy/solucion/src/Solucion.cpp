#include "Solucion.h"
#include <cmath>

Solucion::Solucion() {

    N=0;
    M= 0;

    coste= 0;
}

Solucion::Solucion(const Problema & p) {

    N= p.getN();
    M= p.getM();

    if (N*M>0) {
        sol= new int[N*M];

        for (unsigned int i= 0; i<N*M; i++)
            sol[i]= -1;
    }
    coste=-1;
}

Solucion::Solucion(const Solucion & s) {

    N=0;
    M= 0;
    coste= 0;
    *this= s;
}


Solucion::~Solucion() {
    // Liberar memoria si la hubiese
    if (N*M > 0) { // Liberar la memoria previa
        delete [] sol;
    }
}


Solucion & Solucion::operator=(const Solucion & s) {

    if (this == &s)
        return *this;

    if (N*M > 0) { // Liberar la memoria previa
        delete [] sol;
    }

    N= s.N;
    M=s.M;

    coste= s.coste;

    if (N*M>0) {
        sol = new int[N*M];

        for (unsigned int i= 0; i<N*M; i++) {
            sol[i]= s.sol[i];
        }

    }

    return *this;
}



int Solucion::getCuadricula(int i, int j) {
    if (i<0 || i>=(int)N || j<0 || j>=(int)M)
        return -1;

    return sol[i*M+j];
}



int Solucion::getCoste() {
    return coste;
}



void Solucion::Evaluar(Problema p) {
    //N=p.getN();
    //M=p.getM();


    coste= 0;

    for (unsigned int i= 0; i<N; i++) {
        for(unsigned int j=0; j<M; j++){
            //int costeCuad;

            coste+= abs(getCuadricula(i,j) - p.getValorCuadriculaIma(i,j));
        }
    }
}

void Solucion::addCuadricula(int i, int j, int candidato){
    sol[i*M+j]=candidato;
}



