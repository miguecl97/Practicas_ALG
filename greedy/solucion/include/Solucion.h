#ifndef SOLUCION_H
#define SOLUCION_H

#include "Problema.h"


class Solucion
{
    public:
        Solucion(); // Construye una solución vacía, con coste 0 y sin aristas
        Solucion(const Solucion & s); // Constructor de copia

        Solucion(const Problema & p); // Constructor con un problema

        ~Solucion(); // Destructor

        Solucion & operator=(const Solucion & s); // Operador de asignación


        int getCuadricula(int i, int j);

        int getCoste(); // Devuelve el coste de la solución


        /*
            Evalúa la solución actual en el problema "p". Como resultado, se modifica
            el coste de la solución actual. El coste será -1 si hay error al evaluar.
        */
        void Evaluar(Problema p);


        void addCuadricula(int i, int j, int candidato);

    private:

        int *sol;
        unsigned int N;
        unsigned int M;

        unsigned int coste; // Coste de la solución
};

#endif // SOLUCION_H
