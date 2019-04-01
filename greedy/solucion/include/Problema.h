#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>

using namespace std;


class Problema
{
    public:
        Problema();
        Problema(const Problema & p);
        Problema & operator=(const Problema &p);
        ~Problema();

        int getValorCuadriculaCand(int i);
        int getValorCuadriculaIma(int i, int j);

        bool cargarDesdeFlujo(const char *nombreFichero); // Carga un problema
                                                    // desde el fichero dado por argumento.
                                                    // Devuelve true si ok, y false
                                                    // si error al cargarlo

        int getN() const; // Devuelve el número de filas
        int getM() const; // Devuelve el número de columnas

    protected:

        unsigned int N; // Num. de filas
        unsigned int M; // Num. de columnas

        int *cuadriculas_candidatas; // Vector con las cuadriculas candidatas
        int *imagen_original;

    private:
};

#endif // PROBLEMA_H
