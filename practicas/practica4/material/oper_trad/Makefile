SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebatraductor
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebatraductor: $(OBJ)/pruebatraductor.o $(LIB)/libtraductor.a
	$(CXX) $< -L$(LIB) -ltraductor -o $@

$(OBJ)/pruebatraductor.o: $(SRC)/pruebatraductor.cpp $(OBJ)/CF.o $(OBJ)/Frase.o

$(OBJ)/CF.o: $(SRC)/conjuntofrases.cpp  $(INC)/conjuntofrases.h $(INC)/Frase.h
	$(CXX) $(CPPFLAGS) $< -o $@
$(OBJ)/Frase.o: $(SRC)/Frase.cpp $(INC)/Frase.h 
	$(CXX) $(CPPFLAGS) $< -o $@


# ************ Biblioteca **********

$(LIB)/libtraductor.a: $(OBJ)/CF.o $(OBJ)/Frase.o 
	ar rvs $(LIB)/libtraductor.a $(OBJ)/CF.o $(OBJ)/Frase.o




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
