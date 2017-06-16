SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c 


all: $(BIN)/prueba 
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(OBJ)/CF.o: $(SRC)/conjuntofrases.cpp $(INC)/VD.h $(INC)/VD.cpp $(INC)/conjuntofrases.h $(INC)/Frase.h
	$(CXX) $(CPPFLAGS) $< -o $@
$(OBJ)/Frase.o: $(SRC)/Frase.cpp $(INC)/VD.h $(INC)/VD.cpp $(INC)/Frase.h 
	$(CXX) $(CPPFLAGS) $< -o $@ 
$(OBJ)/Prueba.o: $(SRC)/pruebatrad_test.cpp $(SRC)/conjuntofrases.cpp $(INC)/VD.h $(INC)/VD.cpp 
	$(CXX) $(CPPFLAGS) $< -o $@ 

$(BIN)/prueba: $(OBJ)/Prueba.o $(LIB)/libtraductor.a 
	$(CXX) $< -L$(LIB) -ltraductor -o $@ 

# ************ Biblioteca **********

$(LIB)/libtraductor.a: $(OBJ)/CF.o $(OBJ)/Frase.o 
	ar rvs $(LIB)/libtraductor.a $(OBJ)/CF.o $(OBJ)/Frase.o

# ************ Limpieza ************
clean :
	-rm $(BIN)/* $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
