#include <iostream>
#include <iomanip>

using namespace std;

class SimuladorFinanciero {
private:
    float capitalInicial;
    float capitalActual;

public:
    SimuladorFinanciero(float capitalInicial) {
        this->capitalInicial = capitalInicial;
        this->capitalActual = capitalInicial;
    }

    void invertirMarketing(float cantidad, float porcentaje) {
        cout << "Porcentaje de retorno: " << porcentaje << "%" << endl;
        float beneficioEstimado = cantidad * (porcentaje / 100);
        capitalActual += beneficioEstimado - cantidad;
        cout << fixed << setprecision(0);
        cout << "Has invertido " << cantidad << " en marketing y tu nuevo capital es " << capitalActual << endl;
        if (capitalActual < 0) {
            cout << "-----------------------------" << endl;
            cout << "- ¡NOTA!                    -" << endl;
            cout << "-----------------------------" << endl;
            cout << "-  Te quedaste sin capital  -" << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void contratarPersonal(float salarioAnual, int numeroEmpleados) {
        float costoTotal = salarioAnual * numeroEmpleados;
        capitalActual -= costoTotal;
        cout << fixed << setprecision(0);
        cout << "Has contratado " << numeroEmpleados << " empleados por " << salarioAnual << " cada uno. Capital restante: " << capitalActual << endl;
        if (capitalActual < 0) {
            cout << "-----------------------------" << endl;
            cout << "- ¡NOTA!                    -" << endl;
            cout << "-----------------------------" << endl;
            cout << "-  Te quedaste sin capital  -" << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void expandirOperaciones(float costoExpansion) {
        // Asumamos que la expansión devuelve el doble
        float retornoEstimado = costoExpansion * 2;
        capitalActual += retornoEstimado - costoExpansion;
        cout << fixed << setprecision(0);
        cout << "Has expandido operaciones por " << costoExpansion << ". Capital estimado a largo plazo: " << capitalActual << endl;
        if (capitalActual < 0) {
            cout << "-----------------------------" << endl;
            cout << "- ¡NOTA!                    -" << endl;
            cout << "-----------------------------" << endl;
            cout << "-  Te quedaste sin capital  -" << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void mostrarCapital() {
        cout << fixed << setprecision(0);
        cout << "Capital actual: " << capitalActual << endl;
    }
};

int main() {
    cout << "Bienvenido al Simulador de Toma de Decisiones Financieras" << endl;
    cout << "----------------------------------------------------------" <<endl<<endl;

    float capitalInicial;
    cout << "Ingresa tu capital inicial: ";
    cin >> capitalInicial;

    SimuladorFinanciero simulador(capitalInicial);

    while (true) {
        cout << "\nOpciones:" << endl;
        cout << "1. Invertir en marketing" << endl;
        cout << "2. Contratar personal" << endl;
        cout << "3. Expandir operaciones" << endl;
        cout << "4. Mostrar capital actual" << endl;
        cout << "5. Salir" << endl <<endl;

        int opcion;
        cout << "Elige una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1: {
            float cantidad;
            float porcentaje;
            cout << "--------------------------------------------------------------------------------------------------" <<endl;
            cout << "Ingresa la cantidad a invertir en marketing: ";
            cin >> cantidad;
            cout << "--------------------------------------------------------------------------------------------------" <<endl;
            cout << "¿Cuánto espera que sea el porcentaje de retorno? (Ingrese solo el número, sin el símbolo de '%'): ";
            cin >> porcentaje;
            cout << "--------------------------------------------------------------------------------------------------" <<endl;
            simulador.invertirMarketing(cantidad, porcentaje);
            cout << "--------------------------------------------------------------------------------------------------" <<endl;
            break;
        }
        case 2: {
            float salarioAnual;
            int numeroEmpleados;
            cout << "----------------------------------------------------------" <<endl;
            cout << "Ingresa el salario anual por empleado: ";
            cin >> salarioAnual;
            cout << "Ingresa el número de empleados a contratar: ";
            cin >> numeroEmpleados;
            cout << "----------------------------------------------------------" <<endl;
            simulador.contratarPersonal(salarioAnual, numeroEmpleados);
            cout << "----------------------------------------------------------" <<endl;
            break;
        }
        case 3: {
            float costoExpansion;
            cout << "----------------------------------------------------------" <<endl;
            cout << "Ingresa el costo de la expansión: ";
            cin >> costoExpansion;
            cout << "----------------------------------------------------------" <<endl;
            simulador.expandirOperaciones(costoExpansion);
            cout << "----------------------------------------------------------" <<endl;
            break;
        }
        case 4:
            simulador.mostrarCapital();
            break;

        case 5:
            cout << "----------------------------------------------------------" <<endl;
            cout << "Saliendo del programa..." << endl;
            cout << "----------------------------------------------------------" <<endl;
            return 0;

        default:
            cout << "----------------------------------------------------------" <<endl;
            cout << "Opción no válida, intenta de nuevo." << endl;
            cout << "----------------------------------------------------------" <<endl;
            break;
        }
    }

    return 0;
}

