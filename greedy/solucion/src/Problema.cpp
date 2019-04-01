#include "Problema.h"
#include <fstream>
#include <iostream>

using namespace std;

Problema::Problema() {

    N=0;
    M=0;
}


Problema::Problema(const Problema & p) {

    *this= p;
}


Problema & Problema::operator=(const Problema &p) {

    if (&p == this) // Para evitar cosas como mivariables= mivariables
        return *this;


    if (N*M > 0) { // Liberar la memoria previa
        delete [] cuadriculas_candidatas;
        delete [] imagen_original;
    }

    N= p.N; // Reserva de memoria nueva si es necesario y copia
    M=p.M;

    if (N*M>0) {

        cuadriculas_candidatas= new int[N*M];
        imagen_original = new int[N*M];

        for (unsigned int i= 0; i<N*M; i++) {

            cuadriculas_candidatas[i]= p.cuadriculas_candidatas[i];
            imagen_original[i]= p.imagen_original[i];

        }

    }


    return *this;
}


Problema::~Problema() {

    if (N*M > 0) { // Liberar la memoria previa
        delete [] cuadriculas_candidatas;
        delete [] imagen_original;
    }

    N=0;
    M=0;
}



int Problema::getValorCuadriculaIma(int i, int j) {

    if (i<0 || i>=(int)N || j<0 || j>=(int)M)
        return -1;

    return imagen_original[i*M+j];
}

int Problema::getValorCuadriculaCand(int i) {

    if (i<0 || i>=(int)(N*M) )
        return -1;

    return cuadriculas_candidatas[i];
}



bool Problema::cargarDesdeFlujo(const char *nombreFichero) {


    // Liberar memoria si la hubiese
    if (N*M > 0) { // Liberar la memoria previa
        delete [] cuadriculas_candidatas;
        delete [] imagen_original;
    }

    // Inicializar a problema vacío
    N= 0;
    M=0;

    ifstream fichero;

    fichero.open( nombreFichero );
    if ( !fichero )
        return false;

    fichero >> N;
    fichero >> M;
    if (N*M<=0) {
        fichero.close();
        N= 0;
        M=0;
        return false;
    }

    // Reserva de la memoria para el "N*M" nuevo
    cuadriculas_candidatas= new int[N*M];
    imagen_original= new int[N*M];

    for (unsigned int i= 0; i<N*M; i++)
        fichero >> imagen_original[i];

    for (unsigned int i= 0; i<N*M; i++)
        fichero >> cuadriculas_candidatas[i];


    fichero.close();


    return true;
}

int Problema::getN() const {return N;} // Devuelve el número de filas


int Problema::getM() const {return M;} // Devuelve el número de columnas





