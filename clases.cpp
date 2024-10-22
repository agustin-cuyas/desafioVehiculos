#include "clases.hpp"


Vehiculo::Vehiculo(const string& marca, const string& modelo, const int anio, double kilometraje) : marca(marca), modelo(modelo), anio(anio), kilometraje(kilometraje) {} //member initializer list

Auto::Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas) : Vehiculo(marca, modelo, anio, kilometraje),cantidadPuertas(cantidadPuertas) {} //los constructores no tienen acceso a las variables heredadas, por eso llamo al otro constructor

void Auto::ingresarInfo()
{
    cout << "\nIngrese los datos del auto." << endl;
    cout << "Marca: ";
    getline(cin,marca);
    cout << "Modelo: ";
    getline(cin,modelo);
    cout << "Año: ";
    cin >> anio;
    cout << "Kilometraje: ";
    cin >> kilometraje;
    cout << "Cantidad de puertas: ";
    cin >> cantidadPuertas;
}

void Auto::mostrarInfo() const
{
    //cout << "Prueba Auto" << endl;

    cout << "Marca: " << marca << endl
         << "Modelo: " << modelo << endl
         << "Año: " << anio << endl
         << "Kilometraje: " << kilometraje << " km"<< endl
         << "Cantidad de puertas: " << cantidadPuertas << endl;
}

void Auto::conducir(double km)
{   
    if (km != -1){
        kilometraje+=km;
        cout << "El auto recorrio " << kilometraje << " km." << endl;
    }
}

Moto::Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar) : Vehiculo(marca, modelo, anio, kilometraje), tieneSidecar(tieneSidecar) {}

void Moto::ingresarInfo()
{
    cout << "\nIngrese los datos dela moto." << endl;
    cout << "Marca: ";
    getline(cin,marca);
    cout << "Modelo: ";
    getline(cin,modelo);
    cout << "Año: ";
    cin >> anio;
    cout << "Kilometraje: ";
    cin >> kilometraje;
    cout << "Tiene sidecar? (S/N): ";
    char tieneSC;
    cin >> tieneSC;
    tieneSC = tolower(tieneSC);
    if (tieneSC == 's')
        tieneSidecar = true;
    else if(tieneSC == 'n')
        tieneSidecar = false;
}

void Moto::mostrarInfo() const
{
    //cout << "Prueba Moto" << endl;

    cout << "Marca: " << marca << endl
         << "Modelo: " << modelo << endl
         << "Año: " << anio << endl
         << "Kilometraje: " << kilometraje << endl
         << "Tiene sidecar: " << (tieneSidecar ? "Si" : "No") << endl;
}

void Moto::conducir(double km)
{
    if (km != -1){
        kilometraje+=km;
        cout << "La moto recorrio " << kilometraje << " km." << endl;
    }
}

Camion::Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const double capacidadCarga) : Vehiculo(marca, modelo, anio, kilometraje), capacidadCarga(capacidadCarga) {}

void Camion::ingresarInfo()
{
    cout << "\nIngrese los datos del auto." << endl;
    cout << "Marca: ";
    getline(cin,marca);
    cout << "Modelo: ";
    getline(cin,modelo);
    cout << "Año: ";
    cin >> anio;
    cout << "Kilometraje: ";
    cin >> kilometraje;
    cout << "Capacidad de carga (kg): ";
    cin >> capacidadCarga;
}

void Camion::mostrarInfo() const
{
    //cout << "Prueba Camion" << endl;

    cout << "Marca: " << marca << endl
         << "Modelo: " << modelo << endl
         << "Año: " << anio << endl
         << "Kilometraje: " << kilometraje << endl
         << "Capacidad: " << capacidadCarga << endl;
}

void Camion::conducir(double km)
{
    if (km != -1){
        kilometraje+=km;
        cout << "El camion recorrio " << kilometraje << " km." << endl;
    }
}

Electricidad::Electricidad(double bateria): bateria(bateria){}

AutoElectrico::AutoElectrico(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas, double bateria): Auto(marca, modelo, anio, kilometraje, cantidadPuertas), Electricidad(bateria) {}

void AutoElectrico::ingresarInfo()
{
    Auto::ingresarInfo();
    do{
        cout << "Bateria: ";
        cin >> bateria;
    }while(bateria > 100 || bateria < 0);
    
}

void AutoElectrico::mostrarInfo() const
{
    Auto::mostrarInfo();
    cout << "Bateria: " << bateria << "%" << endl;
}

void AutoElectrico::validarCarga()
{
    double cargaPosible = 100 - bateria;
    double porcentaje;
    bool cargaValida = false;

    if(cargaPosible == 0)
        cout << "Bateria completa, no se puede cargar." << endl;
    
    else
    {    
        cout << "Resta cargar un " << cargaPosible << "% el auto." <<  endl;

        do{   
            try
            {
                cout << "Cuanto desea cargar? ";
                cin >> porcentaje;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    throw invalid_argument("Solo se pueden ingresar numeros");
                }
                    
                if (porcentaje > cargaPosible || porcentaje < 0)
                    throw out_of_range("No se puede superar la capacidad ni ingresar numeros negativos.");

                cargaValida = true; //si no hay excepciones, no se vuelve a pedir.

                cargarBateria(porcentaje);
            }
            catch(const invalid_argument& ex){
                cout << ex.what() << endl;
            }
            catch(const out_of_range& ex){
                cout << ex.what() << endl;
            }
        }while (!cargaValida);    
    }
}

void AutoElectrico::cargarBateria(double porcentaje)
{
    cout << "Cargando auto..." << endl;
    bateria += porcentaje;

    cout << "Auto cargado al " << bateria << "%" << endl;
}

MotoElectrica::MotoElectrica(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar, double bateria): Moto(marca, modelo, anio, kilometraje, tieneSidecar), Electricidad(bateria) {}

void MotoElectrica::ingresarInfo()
{
    Moto::ingresarInfo();
    do{
        cout << "Bateria: ";
        cin >> bateria;
    }while(bateria > 100 || bateria < 0);
}

void MotoElectrica::mostrarInfo() const
{
    Moto::mostrarInfo();
    cout << "Bateria: " << bateria << "%" << endl;
}

void MotoElectrica::validarCarga()
{
    double cargaPosible = 100 - bateria;
    double porcentaje;
    bool cargaValida = false;

    if(cargaPosible == 0)
        cout << "Bateria completa, no se puede cargar." << endl;

    else
    {
        cout << "Resta cargar un " << cargaPosible << "% la moto." <<  endl;
        do{   
            try
            {
                cout << "Cuanto desea cargar? ";
                cin >> porcentaje;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    throw invalid_argument("Solo se pueden ingresar numeros");
                }
                    
                if (porcentaje > cargaPosible || porcentaje < 0)
                    throw out_of_range("No se puede superar la capacidad ni ingresar numeros negativos.");

                cargaValida = true; //si no hay excepciones, no se vuelve a pedir.

                cargarBateria(porcentaje);
            }
            catch(const invalid_argument& ex){
                cout << ex.what() << endl;
            }
            catch(const out_of_range& ex){
                cout << ex.what() << endl;
            }
        }while (!cargaValida);
    }
}

void MotoElectrica::cargarBateria(double porcentaje)
{
    cout << "Cargando moto..." << endl;
    bateria += porcentaje;

    cout << "Moto cargada al " << bateria << "%" << endl;
}

CamionElectrico::CamionElectrico(const string &marca, const string &modelo, const int anio, double kilometraje, const bool capacidadCarga, double bateria) : Camion(marca, modelo, anio, kilometraje, capacidadCarga), Electricidad(bateria) {}

void CamionElectrico::ingresarInfo()
{
    Camion::ingresarInfo();
    do{
        cout << "Bateria: ";
        cin >> bateria;
    }while(bateria > 100 || bateria < 0);
}

void CamionElectrico::mostrarInfo() const
{
    Camion::mostrarInfo();
    cout << "Bateria: " << bateria << "%" << endl;
}

void CamionElectrico::validarCarga()
{
    double cargaPosible = 100 - bateria;
    double porcentaje;
    bool cargaValida = false;

    if (cargaPosible == 0.0)
        cout << "Bateria completa, no se puede cargar." << endl;

    else
    {
        cout << "Resta cargar un " << cargaPosible << "% el camion." <<  endl;
        do{   
            try
            {
                cout << "Cuanto desea cargar? ";
                cin >> porcentaje;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    throw invalid_argument("Solo se pueden ingresar numeros");
                }
                    
                if (porcentaje > cargaPosible || porcentaje < 0)
                    throw out_of_range("No se puede superar la capacidad ni ingresar numeros negativos.");

                cargaValida = true; //si no hay excepciones, no se vuelve a pedir.

                cargarBateria(porcentaje);
            }
            catch(const invalid_argument& ex){
                cout << ex.what() << endl;
            }
            catch(const out_of_range& ex){
                cout << ex.what() << endl;
            }
        }while (!cargaValida);
    }
}

void CamionElectrico::cargarBateria(double porcentaje)
{
    cout << "Cargando camion..." << endl;
    bateria += porcentaje;

    cout << "Camion cargado al " << bateria << "%" << endl;
}


