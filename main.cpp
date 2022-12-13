#include <iostream>
#include <string>
#include "VectorPEL.h"
#include "Disco.h"
using namespace std;

/**
 * Funcion de tipo void que inicializa con ciertos discos el programa, para que ya haya discos cargados al inicio.
 * @param discos el vectorPEL donde voy a guardar los discos
 */
void inicializarDiscos(VectorPEL<Disco> &discos){
    Disco *disco = new Disco( "Star wars: the phantom menance" , 9.99f , true);
    Disco *disco1 = new Disco( "Star wars: attack of the clones" , 12.99f , false );
    Disco *disco2 = new Disco( "Star wars: revange of the sith" , 7.99f , true );
    Disco *disco3 = new Disco( "Star wars: a new hope" , 9.99f , false );
    Disco *disco4 = new Disco( "Star wars: the empire strikes back" , 8.99f , true );
    Disco *disco5 = new Disco( "Star wars: return of the jedi" , 13.99f , false );
    Disco *disco6 = new Disco( "Star wars: the force awakens" , 12.99f , true );
    Disco *disco7 = new Disco( "Rogue one: a star wars story" , 6.99f , false );
    Disco *disco8 = new Disco( "Star wars: the las jedi" , 9.99f , true );
    Disco *disco9 = new Disco( "Solo: a star wars story" , 15.99f , false  );
    Disco *disco10 = new Disco( "Star wars: the rise of skywalker" , 16.99f , true );
    discos.push_back(*disco);
    discos.push_back(*disco1);
    discos.push_back(*disco2);
    discos.push_back(*disco3);
    discos.push_back(*disco4);
    discos.push_back(*disco5);
    discos.push_back(*disco6);
    discos.push_back(*disco7);
    discos.push_back(*disco8);
    discos.push_back(*disco9);
    discos.push_back(*disco10);
}

/**
 * Funcion que me permite limpiar el cin, para evitar problemas.
 */
void cinearlo(){
    cin.ignore();
    cin.clear();
    cin.sync();
}

/**
 * Funcione mail del programa, donde se ejecuta el codigo dentro de main.cpp
 * @return
 */
int main() {
    VectorPEL<Disco> *discos = new VectorPEL<Disco>;
    inicializarDiscos(*discos);
    bool condicionLoop = true;
    cout << "---- Bienvenido a nuestro VIDEOCLUB, seleccione una de las opciones de nuestro menu------" << endl;
    int opcionMenu;
    //Entro al menu principal de la aplicacion donde voy a dar varias opciones para que los usuarios eligan.
    while ( condicionLoop ){
        cout << "Opciones Menu: \n1. Añadir Disco \n2. Mostar listado de todos los discos \n3. Buscar discos por titulo \n4. Mostrar libros disponibles para alquiler \n5. Alquilar disco \n6. Devolver disco \n7. Terminar programa" << endl;
        cin >> opcionMenu;
        switch ( opcionMenu ) {
            case 1: //caso numero 1, en donde se añade el disco
            {
                string titulo,precio,esDVD;
                float precioF;
                bool esDVDb;
                cout << "Ingrese el titulo: " << endl;
                cinearlo();
                getline(cin,titulo);
                cout << "Ingrese el precio: " << endl;
                cin >> precio;
                try{
                    precioF = stof( precio );
                }catch(...){
                    cout << "Error, no se ingreso un float" << endl;
                    break;
                }
                cout << "El disco esta en formato DVD? (s/n) : " << endl;
                cin >> esDVD;
                if(esDVD == "s"){
                    esDVDb = true;
                }else if(esDVD == "n"){
                    esDVDb = false;
                }
                Disco *discoToAdd = new Disco( titulo , precioF , esDVDb );
                discos->push_back(*discoToAdd);
                break;
            }
            case 2: //mostrar listado de todos los discos
            {
                for (int i = 0; i < discos->size(); ++i) {
                    cout << discos->now( i )-> toString() << endl;
                }
                break;
            }
            case 3: //buscar discos por titulo
            {
                string tituloABuscar;
                bool encontreDisco = false;
                cout << "Ingrese el titulo: " << endl;
                cinearlo();
                getline(cin,tituloABuscar);
                for (int i = 0; i < discos->size(); ++i) {
                    if( discos->now(i)->getTitulo() == tituloABuscar){
                        encontreDisco = true;
                        cout << discos->now( i )-> toString() << endl;
                    }
                }

                if( encontreDisco == false){
                    cout << "Este libro no existe, pruebe con otro porfavor." << endl;
                }
                break;
            }
            case 4: //mostrar disco disponibles para alquiler
            {
                cout << "Listado de discos disponibles para alquiler: " << endl;
                for (int i = 0; i < discos->size(); ++i) {
                    if( !(discos->now(i)->isEstaAlquilado())){
                        cout << discos->now( i )-> toString() << endl;
                    }
                }
                break;
            }
            case 5: //alquilar un disco
            {
                bool encontreDisco = false;
                cout << "Introduzca el nombre del disco que quiere alquilar: " << endl;
                string tituloABuscar;
                cinearlo();
                getline(cin,tituloABuscar);
                for (int i = 0; i < discos->size(); ++i) {
                    if( discos->now(i)->getTitulo() == tituloABuscar && !(discos->now(i)->isEstaAlquilado())){
                        discos->now(i)->setEstaAlquilado(true);
                        encontreDisco = true;
                        cout << "Se ha alquilado con exito el libro" << endl;
                    }
                }
                if( encontreDisco == false){
                    cout << "Este libro no existe, o ya esta alquilado.Pruebo con otro porfavor." << endl;
                }
                break;
            }
            case 6: //devolver un libro
            {
                bool encontreDisco = false;
                cout << "Introduzca el nombre del disco que quiere devolver: " << endl;
                string tituloABuscar;
                cinearlo();
                getline(cin,tituloABuscar);
                for (int i = 0; i < discos->size(); ++i) {
                    if( discos->now(i)->getTitulo() == tituloABuscar && discos->now(i)->isEstaAlquilado()){
                        discos->now(i)->setEstaAlquilado(false);
                        encontreDisco = true;
                        cout << "Se ha devuelto el libro con exito" << endl;
                    }
                }
                if( encontreDisco == false){
                    cout << "Este libro no existe, pruebe con otro porfavor." << endl;
                }
                break;
            }
            case 7: //terminar programa
                condicionLoop = false;
            default: //caso default por si me pasan algun dato que no es.
                cout << "-----Porfavor ingrese una opcion valida----" << endl;
                break;
        }
    }
    return 0;
}