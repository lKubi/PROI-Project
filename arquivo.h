#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

    #include <iostream>
    # include "estrutura.h"
    # include <fstream>

    using namespace std;

    // Declaracións das funcións necesarias específicas para xestionar doente

    // Funcionalidade proporcionada para a carga inicial do arquivo
    void cargarArquivo (char nome [ ], setDoentes &variosDoentes);
    void guardarArchivo (char nome [ ], setDoentes &variosDoentes);
    void modificarArchivo(char nome []);


#endif // ARQUIVO_H_INCLUDED
