#include <iostream>
#ifndef PROYECTO_2_VIDEOCLUB_DISCO_H
#define PROYECTO_2_VIDEOCLUB_DISCO_H
using namespace std;

class Disco {
private:
    string titulo;
    float precio;
    bool esDVD;
    bool estaAlquilado;
public:
    /**
     * Constructor sin parametros del objeto Disco
     */
    Disco(){};

    /**
     * Constructor con parametros del objeto Disco
     * @param titulo el nombre del disco
     * @param precio al que se vende el disco
     * @param esDVD si el disco es DVD
     * @param esBLR si el disco es Blue-ray
     */
    Disco(string titulo,  float precio, bool esDVD){
        Disco::titulo = titulo;
        Disco::precio = precio;
        Disco::esDVD = esDVD;
        Disco::estaAlquilado = false;
    }

    /**
     * Getter para el titulo de un Disco
     * @return devuelve el titulo de un disco
     */
    string getTitulo() const {
        return titulo;
    }

    bool isEstaAlquilado() const {
        return estaAlquilado;
    }

    void setEstaAlquilado( bool estaAlquilado ) {
        Disco::estaAlquilado = estaAlquilado;
    }

    string toString() {
        return "*Titulo Disco: " +
               titulo +
               "\n Precio: " +
               to_string( precio ) +
               "\n En DVD: " +
               tipoDisco( esDVD );
    }

    string tipoDisco( bool variable ){
        string devolucion;
        if ( variable ){
            devolucion = "Si";
        }else{
            devolucion = "No";
        }
        return devolucion;
    }

};
#endif //PROYECTO_2_VIDEOCLUB_DISCO_H