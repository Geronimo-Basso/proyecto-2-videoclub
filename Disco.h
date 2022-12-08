#include <iostream>
#ifndef PROYECTO_2_VIDEOCLUB_DISCO_H
#define PROYECTO_2_VIDEOCLUB_DISCO_H
using namespace std;

class Disco {
private:
    string titulo;
    float precio;
    bool esDVD;
    bool esBLR;
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
    Disco(string titulo,  float precio, bool esDVD, bool esBLR){
        Disco::titulo = titulo;
        Disco::precio = precio;
        Disco::esBLR = esBLR;
        Disco::esDVD = esDVD;
    }

    /**
     * Getter para el titulo de un Disco
     * @return devuelve el titulo de un disco
     */
    string getTitulo() const {
        return titulo;
    }
};
#endif //PROYECTO_2_VIDEOCLUB_DISCO_H