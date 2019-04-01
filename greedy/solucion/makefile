SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++
AR = ar rvs		
AR_MACOSX = libtool -static -o  
CPPFLAGS = -Wall -g  -I$(INC) -c



all: $(BIN)/problemamural 
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/problemamural: $(OBJ)/main.o $(LIB)/libProblema.a $(LIB)/libSolucion.a $(LIB)/libAlgoritmos.a
	$(CXX) -o $(BIN)/problemamural $(OBJ)/main.o -I$(INC) -L$(LIB) -lProblema -lSolucion -lAlgoritmos

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INC)

$(LIB)/libProblema.a: $(OBJ)/Problema.o
	$(AR) $(LIB)/libProblema.a $(OBJ)/Problema.o

$(LIB)/libSolucion.a: $(OBJ)/Solucion.o
	$(AR)  $(LIB)/libSolucion.a $(OBJ)/Solucion.o

$(LIB)/libAlgoritmos.a: $(OBJ)/Algoritmos.o
	$(AR)  $(LIB)/libAlgoritmos.a $(OBJ)/Algoritmos.o

$(OBJ)/Problema.o: $(SRC)/Problema.cpp $(INC)/Problema.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Problema.o $(SRC)/Problema.cpp -I$(INC)

$(OBJ)/Solucion.o: $(SRC)/Solucion.cpp $(INC)/Solucion.h $(INC)/Problema.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Solucion.o $(SRC)/Solucion.cpp -I$(INC)

$(OBJ)/Algoritmos.o: $(SRC)/Algoritmos.cpp $(INC)/Algoritmos.h $(INC)/Problema.h $(INC)/Solucion.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Algoritmos.o $(SRC)/Algoritmos.cpp -I$(INC)



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
