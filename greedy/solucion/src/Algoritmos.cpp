#include "Algoritmos.h"
#include <cmath>
#include <iostream>

using namespace std;

Solucion AlgoritmoGreedyMural(Problema p) {
    Solucion s(p); // Solución a devolver
    bool *LC; // Lista de candidatos (false si está en LC, true si está en LCU)


    int TAM=p.getN() * p.getM(); //Tamaño del vector LC
    // Inicializar la lista de candidatos
    LC= new bool[TAM]; 
    for (int i= 0; i<TAM; i++)
        LC[i]= false;
    /*Algoritmo Greedy para encontrar la imagen del vector LC que más se parece a la de la matriz original
	*/
    for(int i=0; i<p.getN(); i++){
        for(int j=0; j<p.getM(); j++){
	    
//Tomamos el valor de la matriz original, inicialmente la posicion M[0][0]
            int valor=p.getValorCuadriculaIma(i,j);
            int k;
	    
//La variable ls_centinela nos indica si el elemento LC[k] esta usado o no LC=[true,true,true,false,false]
            bool lc_centinela=false;

            for(k=0; k<TAM && !lc_centinela; k++){
                lc_centinela=(LC[k]==false);
            }
 	    

            int pos_buscada=k-1;
//Calculamos la diferencia entre nuestra imagen candidata y la original
            int diferencia=abs(p.getValorCuadriculaCand(pos_buscada)-valor);
//Ahora actualizamos la diferencia hasta que encontremos la menor entre todos los elementos de LC
            for(; k<TAM; k++ )
                if(LC[k]==false)
//Si la diferencia es menor que la que hemos calculado en iteraciones anteriores, actualizamos nuestra imagen buscada pos_buscada=k
                    if(diferencia>abs(p.getValorCuadriculaCand(k)-valor)){
                        diferencia=abs(p.getValorCuadriculaCand(k)-valor);
			
                        pos_buscada=k;
                    }
//La marcamos como utilizada en la LC
            LC[pos_buscada]=true;
//La añadimos a la nueva imagen
            s.addCuadricula(i,j,p.getValorCuadriculaCand(pos_buscada));
        }

    }
//Liberamos memoria
    delete [] LC;
//Return de la imagen final
    return s;
}
