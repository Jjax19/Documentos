#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Empleado {
public:
    int id;
    string nombre;
    double sueldo;
	double bonos = 0, deducciones = 0;

    Empleado() : id(0), nombre(""), sueldo(1000), bonos(0), deducciones(0) {}  
	Empleado(int id, string nombre) : id(id), nombre(nombre), sueldo(1000), bonos(0), deducciones(0) {}
};
