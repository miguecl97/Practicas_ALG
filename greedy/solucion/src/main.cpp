#include <iostream>
#include <iomanip>
#include "Problema.h"
#include "Solucion.h"
#include "Algoritmos.h"

using namespace std;

int main()
{
    Problema prob;
    Solucion sol;


    if (!prob.cargarDesdeFlujo("Problema.dat"))
        cout << "El fichero no se puede abrir" << endl;

    // Resolvemos con algoritmo greedy
    sol= AlgoritmoGreedyMural(prob);

    // La evaluamos
    sol.Evaluar(prob);

    cout << "Matriz original:\n";
    for(int i= 0; i<prob.getN(); i++){
	for(int j= 0; j<prob.getM(); j++)
	   cout << left << setw(6) << setfill(' ') << prob.getValorCuadriculaIma(i,j);
    cout << endl;
    }

    cout << "\nCuadriculas candidatas:\n";

    for ( int i = 0 ; i < prob.getN() * prob.getM(); ++i)
        cout << left << setw(4) << setfill(' ') << prob.getValorCuadriculaCand(i);


    // Mostramos la solución final
    cout<<"\n\nSOLUCIÓN:\n";
    for(int i= 0; i<prob.getN(); i++){ 
	for(int j= 0; j<prob.getM(); j++)
		cout << left << setw(6) << setfill(' ') << sol.getCuadricula(i,j);
	cout<< endl;
    }
    
    cout <<endl;
    cout << endl << "Coste total: " << sol.getCoste() << endl;
    return 0;
}
