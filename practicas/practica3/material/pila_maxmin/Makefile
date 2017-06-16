SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usocolas $(BIN)/usolistas $(BIN)/usoVD $(BIN)/usopilas_maxmin $(BIN)/orden

$(BIN)/orden: $(OBJ)/orden.o
	$(CXX) -o $(BIN)/orden $(OBJ)/orden.o

$(OBJ)/orden.o: $(INC)/pila_maxmin.h $(INC)/pila_maxmin_VD.cpp $(INC)/pila_maxmin_Lista.cpp $(INC)/pila_maxmin_Cola.cpp $(SRC)/usopilas_maxmin.cpp $(SRC)/orden.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/orden.cpp -o $(OBJ)/orden.o
$(BIN)/usopilas_maxmin: $(OBJ)/usopilas_maxmin.o
	$(CXX) -o $(BIN)/usopilas_maxmin $(OBJ)/usopilas_maxmin.o

$(OBJ)/usopilas_maxmin.o: $(INC)/pila_maxmin.h $(INC)/pila_maxmin_VD.cpp $(INC)/pila_maxmin_Lista.cpp $(INC)/pila_maxmin_Cola.cpp $(SRC)/usopilas_maxmin.cpp  
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_maxmin.cpp -o $(OBJ)/usopilas_maxmin.o

$(BIN)/usoVD: $(OBJ)/usoVD.o
	$(CXX) -o $(BIN)/usoVD $(OBJ)/usoVD.o

$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o

$(BIN)/usolistas: $(OBJ)/usolistas.o
	$(CXX) -o $(BIN)/usolistas $(OBJ)/usolistas.o

$(OBJ)/usoVD.o: $(INC)/VD.h $(INC)/VD.cpp $(SRC)/usoVD.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usoVD.cpp -o $(OBJ)/usoVD.o -I$(INC)

$(OBJ)/usocolas.o: $(INC)/cola.h $(INC)/cola.cpp $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)

$(OBJ)/usolistas.o: $(INC)/lista.h $(INC)/lista.cpp $(SRC)/usolistas.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usolistas.cpp -o $(OBJ)/usolistas.o -I$(INC)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

