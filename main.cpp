#include <iostream>
#include <vector>
#include "clases.hpp"

using namespace std;

enum Opcion
{
    agregar = 1,
    mostrar,
    salir
};

enum enumVehiculo   //si pongo Vehiculo lo confunde con la clase
{
    enumauto = 1,   //si pongo auto lo confunde con el tipo de dato
    moto,
    camion
};

double conducirVehiculo();

void agregarVehiculo(vector<Vehiculo*>& flota) {
    int tipo;
    char esElectrico;

    cout << "\nIngrese el tipo de vehiculo:\n";
    cout << "1. Auto\n";
    cout << "2. Moto\n";
    cout << "3. Camion\n";
    cout << "Elija una opcion: ";
    cin >> tipo;

    Vehiculo* vehiculo = nullptr; // variable temporal para crear y configurar un nuevo vehiculo

    switch (tipo) {
        case enumVehiculo::enumauto:
            do {
                cout << "\nEl auto es electrico? (S/N): ";
                cin >> esElectrico;
                esElectrico = tolower(esElectrico);
                cin.ignore();
            } while (esElectrico != 's' && esElectrico != 'n');
            if (esElectrico == 'n') 
                vehiculo = new Auto("", "", 0, 0.0, 0);
            else if (esElectrico == 's') 
                vehiculo = new AutoElectrico("", "", 0, 0.0, 0, 0.0);
            break;
        case enumVehiculo::moto:
            do {
                cout << "\nLa moto es electrica? (S/N): ";
                cin >> esElectrico;
                esElectrico = tolower(esElectrico);
                cin.ignore();
            } while (esElectrico != 's' && esElectrico != 'n');
            if (esElectrico == 'n') 
                vehiculo = new Moto("", "", 0, 0.0, false);
            else if (esElectrico == 's')
                vehiculo = new MotoElectrica("", "", 0, 0.0, false, 0.0);
            break;
        case enumVehiculo::camion:
            do {
                cout << "\nEl camion es electrico? (S/N): ";
                cin >> esElectrico;
                esElectrico = tolower(esElectrico);
                cin.ignore();
            } while (esElectrico != 's' && esElectrico != 'n');
            if (esElectrico == 'n') 
                vehiculo = new Camion("", "", 0, 0.0, 0.0);
            else if (esElectrico == 's')
                vehiculo = new CamionElectrico("", "", 0, 0.0, 0.0, 0.0);
            break;        
        default:
            cout << "Opcion invalida.\n";
            return;
    }

    vehiculo->ingresarInfo();
    flota.push_back(vehiculo);
    cout << "Vehiculo agregado exitosamente.\n";
}

void mostrarVehiculos(const vector<Vehiculo*>& flota) {

    if(flota.size()==0)
        cout << "\nNo tiene vehiculos cargados." << endl;
    else
    {    for (size_t i = 0; i < flota.size(); ++i) {    //size() devuelve una variable type_t, por eso defino i asi
            cout << "\nVehiculo " << i + 1 << ":\n";
            flota[i]->mostrarInfo();

            Vehiculo* vehiculo = flota[i];
            Electricidad* vehiculoElectrico = dynamic_cast<Electricidad*>(vehiculo); //vehiculoElectrico es un puntero auxiliar para confirmar si vehiculo deriva de la clase Electricidad

            if(vehiculoElectrico){     //si es un puntero no nulo ingresa al if
                cout << "\nEl vehiculo es electrico\n"
                     << "Desea recargarlo? (S/N): ";
                char recargar;
                cin >> recargar;
                tolower(recargar);

                if(recargar == 's')
                    vehiculoElectrico->validarCarga();
                
            }
            
            cout << "\n";
        }

        //Luego de mostrar todos se pueden conducir
        char conducir;
        bool quiereConducir = false;
        do
        {   cout << "\nDesea conducir algun vehiculo? (S/N): ";
            cin >> conducir;
            tolower(conducir);
            
            if(conducir == 's'){
                quiereConducir = true;

                int indice;
                do{
                    cout << "Ingrese el numero de vehiculo: ";
                    cin >> indice;
                    }while(indice<1 || indice > flota.size());

                Vehiculo* vehiculo = flota[indice - 1];
                vehiculo->conducir(conducirVehiculo());
            }

            else if(conducir == 'n')
                quiereConducir = false;

        }while(quiereConducir);
    }
}

double conducirVehiculo(){
    
    double km;
    
    bool ingresoValido = false;

    do{   
        try
        {
            cout << "Cuantos kilometros desea conducir? ";
            cin >> km;

            if(cin.fail()){
                cin.clear();
                cin.ignore();
                throw invalid_argument("Solo se pueden ingresar numeros");
            }

            ingresoValido = true;

        }

        catch(const invalid_argument& ex){
        cout << ex.what() << endl;
        }

    }while(!ingresoValido);

    return km;
}

int main() {
    vector<Vehiculo*> flota; //coleccion que mantiene todos los vehiculos creados
    int opcion;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Agregar vehiculo\n";
        cout << "2. Mostrar vehiculos\n";
        cout << "3. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case Opcion::agregar:
                agregarVehiculo(flota);
                break;
            case Opcion::mostrar:
                mostrarVehiculos(flota);
                break;
            case Opcion::salir:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 3);

    for (auto vehiculo : flota) {
        delete vehiculo;
    }

    return 0;
}
