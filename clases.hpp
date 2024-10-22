#ifndef CLASES
#define CLASES

#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
public:
    Vehiculo(const string& marca, const string& modelo, const int anio, double kilometraje);
    virtual void ingresarInfo() = 0;
    virtual void mostrarInfo() const = 0;
    virtual void conducir(double km) = 0;

protected:
    string marca;
    string modelo;
    int anio;
    double kilometraje;    
};

class Electricidad {
public:
    Electricidad(double bateria);
    virtual void validarCarga() = 0;
    virtual void cargarBateria(double porcentaje) = 0;

protected:
    double bateria = 0;
};


class Auto : public Vehiculo{
public:
    Auto(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas);
    void ingresarInfo() override;
    void mostrarInfo() const override;
    void conducir(double km) override;

protected:
    int cantidadPuertas;    
};

class AutoElectrico : public Auto, public Electricidad{
public:
    AutoElectrico(const string& marca, const string& modelo, const int anio, double kilometraje, const int cantidadPuertas, double bateria);
    void ingresarInfo() override;
    void mostrarInfo() const override;
    void validarCarga() override;
    void cargarBateria(double porcentaje) override;
};

class Moto : public Vehiculo{
public:
    Moto(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar);
    void ingresarInfo() override;
    void mostrarInfo() const override;
    void conducir(double km) override;

protected:
    bool tieneSidecar;
};

class MotoElectrica : public Moto, public Electricidad{
public:
    MotoElectrica(const string& marca, const string& modelo, const int anio, double kilometraje, const bool tieneSidecar, double bateria);
    void ingresarInfo() override;
    void mostrarInfo() const override;
    void validarCarga() override;
    void cargarBateria(double porcentaje) override;
};

class Camion : public Vehiculo{
public:
    Camion(const string& marca, const string& modelo, const int anio, double kilometraje, const double capacidadCarga);
    void ingresarInfo() override;
    void mostrarInfo() const override;
    void conducir(double km) override;

protected:
    double capacidadCarga;
};

class CamionElectrico : public Camion, public Electricidad{
public:
    CamionElectrico(const string& marca, const string& modelo, const int anio, double kilometraje, const bool capacidadCarga, double bateria);
    void ingresarInfo() override;
    void mostrarInfo() const override;
    void validarCarga() override;
    void cargarBateria(double porcentaje) override;
};

#endif