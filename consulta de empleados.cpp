#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    float salario;

public:
 
    Empleado() {}

    
    void setNombre(string nombre) { this->nombre = nombre; }
    void setApellido(string apellido) { this->apellido = apellido; }
    void setEdad(int edad) { this->edad = edad; }
    void setSalario(float salario) { this->salario = salario; }

    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    int getEdad() { return edad; }
    float getSalario() { return salario; }
};

int main() {
    int numEmpleados;
    cout << "Ingrese el número de empleados: ";
    cin >> numEmpleados;

  
    Empleado empleados[numEmpleados];

  
    for (int i = 0; i < numEmpleados; i++) {
        Empleado empleado;

        string nombre, apellido;
        int edad;
        float salario;

        cout << "Empleado " << i+1 << ":\n";
        cout << "Nombre: ";
        cin >> nombre;
        empleado.setNombre(nombre);

        cout << "Apellido: ";
        cin >> apellido;
        empleado.setApellido(apellido);

        cout << "Edad: ";
        cin >> edad;
        empleado.setEdad(edad);

        cout << "Salario: ";
        cin >> salario;
        empleado.setSalario(salario);

        empleados[i] = empleado;
    }

   
    ofstream archivo("empleados.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < numEmpleados; i++) {
            archivo << "Empleado " << i+1 << ":\n";
            archivo << "Nombre: " << empleados[i].getNombre() << "\n";
            archivo << "Apellido: " << empleados[i].getApellido() << "\n";
            archivo << "Edad: " << empleados[i].getEdad() << "\n";
            archivo << "Salario: " << empleados[i].getSalario() << "\n\n";
        }
        archivo.close();
        cout << "Los datos se han guardado correctamente en empleados.txt\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }

    return 0;
}
