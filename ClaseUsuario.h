#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Usuario {
private:
    string username;
    string password;
    int loginIntentos;

public:
    Usuario(string username, string password) : username(username), password(password), loginIntentos(0) {}

    bool login(string intentoUsername, string intentoContrasena) {
        if (intentoUsername == username && intentoContrasena == password) {
            loginIntentos = 0;
            return true;
        } else {
            loginIntentos++;
            return false;
        }
    }

    bool isLocked() {
        if (username == "admin" && loginIntentos >= 3) {
            return true;
        } else {
            return false;
        }
    }

    void eliminarAdmin() {
        username = "";
        password = "";
    }
};
