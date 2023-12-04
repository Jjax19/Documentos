// HECHO POR MAURICIO VILLALOBOS Y JOSEPH FLORES
//DATOS ADMIN: admin, pass1234
//DATOS SUPER ADMIN: superadmin, MaxVerstappen

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "ClaseEmpleado.h"
#include "ClaseUsuario.h"

using namespace std;

struct IDcoincide {   //Este struct fue trabajo de investigación de Mau
    int id;
    IDcoincide(int id) : id(id) {}
    bool operator()(const Empleado& e) const {
        return e.id == id;
    }
};

int main() {	//La pantalla de login fue principalmente llevada por Mau
    Usuario admin("admin", "pass1234");
    Usuario superadmin("superadmin", "MaxVerstappen");

    string intentoUsername;
    string intentoContrasena;

    while (true) {
        cout << "Ingresa tu nombre de usuario: ";
        cin >> intentoUsername;
        cout << "Ingresa tu contraseña: ";
        cin >> intentoContrasena;

        if (admin.login(intentoUsername, intentoContrasena)) {
            cout << "Bienvenido admin.\n";
            break;
        } else if (admin.isLocked()) {
            cout << "Admin bloqueado, ingresar con superadmin.\n";
            admin.eliminarAdmin();
        } else if (superadmin.login(intentoUsername, intentoContrasena)) {
            cout << "Bienvenido superadmin.\n";
            break;
        } else {
            cout << "Datos invalidos.\n";
        }
    }
    vector<Empleado> empleados(3);

    // Crea primeros empleados
    for (int i = 0; i < 3; ++i) {	//Investigación de stringstream por Joseph
        stringstream ss;
        ss << (i + 1);
        string idStr = ss.str();
        empleados[i] = Empleado(i + 1, "user" + idStr);
    }
    int opcion;
    do {
        cout << "1. Agregar Empleado\n2. Mostrar Empleados\n3. Modificar Empleado\n4. Eliminar Empleado\n5. Asignar Salario y Bonos\n6. Salir\n";
        cin >> opcion;

        switch (opcion) {		//Planteamiento de los casos dirigida por Joseph, ejecución por los 2
        case 1: {
            int id;
            string nombre;
            cout << "Ingresa ID: ";
            cin >> id;
            cout << "Ingresa nombre: ";
            cin >> nombre;
            empleados.push_back(Empleado(id, nombre));
            break;
        }
        case 2: {   //Este caso fue planteado por Joseph, con observaciones de Mau
            for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
                cout << "ID: " << it->id << ", Nombre: " << it->nombre << ", Salario: " << it->sueldo <<", Bonos: "<< it->bonos <<", Deducciones: "<< it->deducciones<<"\n";
            }
            break;
        }
        case 3: { //Este caso fue modificado por Joseph y Mau
            int id;
            string nombre;
            cout << "Ingresa ID: ";
            cin >> id;
            cout << "Ingresa nuevo nombre: ";
            cin >> nombre;
            for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
                if (it->id == id) {
                    it->nombre = nombre;
                    break;
                }
            }
            break;
        }
        case 4: { //Este caso fue planteado por Joseph
            int id;
            cout << "Ingresa ID: ";
            cin >> id;
            empleados.erase(remove_if(empleados.begin(), empleados.end(), IDcoincide(id)), empleados.end());
            break;
	    }
        case 5: { //Este caso fue planteado por Joseph y con correcciones de Mau
            int id;
            double salarioBase, actividadesExtra, horasExtra, diasTarde;
            cout << "Ingresa ID: ";
            cin >> id;
            cout << "Ingresa salario base: ";
            cin >> salarioBase;
            cout << "Ingresa actividades extra: ";
            cin >> actividadesExtra;
            cout << "Ingresa horas extra: ";
            cin >> horasExtra;
            cout << "Ingresa dias con retraso: ";
            cin >> diasTarde;
            double salarioNuevo = salarioBase + actividadesExtra * 175 + horasExtra * 450 - diasTarde * 200;
            double bonosSueldo = actividadesExtra * 175 + horasExtra * 450;
            double deducciones = diasTarde * 200;
			for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
                if (it->id == id) {
                    it->sueldo = salarioNuevo;
                    it->bonos = bonosSueldo;
                    it->deducciones = deducciones;
                    break;
                }
            }
            break;
        }
        case 6:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}
//Conclusión (Joseph): Gracias a este trabajo pude mejorar mis habilidades con C++, lo cual fue un gran reto y me permitió crecer en las habilidades congnitivas. 
//Conlusión (Joseph): Con este reto pude darme una idea de como se elabora una base de datos la cual es muy basica, pero funcional para empezar con estos trabajos.
