# include <cstring>
# include "arquivo.h"
# include "doente.h"

using namespace std;


void cargarArquivo (char nome [ ], setDoentes &variosDoentes) {
    ifstream fentrada;
    Doente oDoente;
    variosDoentes.numDoentes = 0;

    fentrada.open ( nome, ios::in | ios::binary );
    if ( !fentrada ) {
        cout << "Erro na apertura do arquivo.";
        exit ( -1 );
    }
    else {
        fentrada.read( (char *) &oDoente, sizeof ( Doente ) );
        while( ! fentrada.eof() ) {
            variosDoentes.Doentes [variosDoentes.numDoentes++] = oDoente;
            fentrada.read( (char *) &oDoente, sizeof ( Doente ) );
    };
    fentrada.close ( );
    }
}

void guardarArchivo (char nome [ ], setDoentes &variosDoentes) {
    ofstream fsalida;
    Doente oDoente;

    fsalida.open ( nome, ios::out | ios::binary );
    if ( !fsalida ) {
        cout << "Error al guardar el archivo.";
        exit ( -1 );
    }
    else {
        for(int i = 0; i<variosDoentes.numDoentes; i++){
            oDoente = variosDoentes.Doentes[i];
            fsalida.write( (char *) &oDoente, sizeof ( Doente ) );
        }
    fsalida.close ( );
    }
}

void modificarArchivo(char nome []){
    setDoentes DoenteActivo;
    cargarArquivo(nome, DoenteActivo);
    modificarDoente(DoenteActivo);
    guardarArchivo(nome, DoenteActivo);

}



