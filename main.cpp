#include <iostream>
#include "VectorPEL.h"
#include "Disco.h"
using namespace std;

void inicializarDiscos(VectorPEL<Disco> &discos){
    Disco *disco = new Disco( "Star wars: the phantom menance" , 9.99f , true , false );
    Disco *disco1 = new Disco( "Star wars: attack of the clones" , 12.99f , false , true );
    Disco *disco2 = new Disco( "Star wars: revange of the sith" , 7.99f , true , false );
    Disco *disco3 = new Disco( "Star wars: a new hope" , 9.99f , false , true );
    Disco *disco4 = new Disco( "Star wars: the empire strikes back" , 8.99f , true , false );
    Disco *disco5 = new Disco( "Star wars: return of the jedi" , 13.99f , false , true );
    Disco *disco6 = new Disco( "Star wars: the force awakens" , 12.99f , true , false );
    Disco *disco7 = new Disco( "Rogue one: a star wars story" , 6.99f , false , true );
    Disco *disco8 = new Disco( "Star wars: the las jedi" , 9.99f , true , false );
    Disco *disco9 = new Disco( "Solo: a star wars story" , 15.99f , false , true );
    Disco *disco10 = new Disco( "Star wars: the rise of skywalker" , 16.99f , true , false );
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

int main() {
    VectorPEL<Disco> *discos = new VectorPEL<Disco>;
    inicializarDiscos(*discos);
    bool condicionLoop = true;
    cout << "---- Bienvenido a nuestro VIDEOCLUB, seleccione una de las opciones de nuestro menu------" << endl;
    char opcionMenu;
    while ( condicionLoop ){
        cout << "1. Mostar listado disco \n2. Buscar discos por titulo \n3. Alquilar disco \n4. Devolver disco \n5. Terminar programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                condicionLoop = false;
            default:
                cout << "-----Porfavor ingrese una opcion valida----" << endl;
                break;
        }
    }
    return 0;
}
