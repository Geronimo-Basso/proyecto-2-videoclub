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

    /**
     * Getter para saber si un Disco esta alquilado o no
     * @return
     */
    bool isEstaAlquilado() const {
        return estaAlquilado;
    }

    /**
     * Setter para poder configurar el estado de alquiler de un Disco
     * @param estaAlquilado
     */
    void setEstaAlquilado( bool estaAlquilado ) {
        Disco::estaAlquilado = estaAlquilado;
    }

    /**
     * Metodo toString para poder devolver toda la información dentro de la clase Disco.
     * @return devuelvo el string en un formato lindo de leer que voy a imprimir más adelante.
     */
    string toString() {
        return "*Titulo: " +
               titulo +
               "\n Precio: " +
               to_string( precio ) +
               "\n En DVD: " +
               tipoDisco( esDVD ) +
                "\n En BLR: " +
                tipoDisco( !esDVD ) +
                "\n ¿Esta alquilado? " +
                tipoDisco(estaAlquilado);
    }

    /**
     * Metodo tipoDisco, el cual devuelve si un disco es DVD O BLR.
     * @param variable bool que le paso para cheequear.
     * @return string que uso luego en el toString.
     */
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