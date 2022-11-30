//Programa main para xestion de doentes dun centro sanitario

# include <iostream>

# include <cstring>

# include "estrutura.h"
# include "doente.h"
# include "util.h"
# include "arquivo.h"

using namespace std;

int menu();

int main() {
    int opcion;
    setDoentes variosDoentes;

    char ARQUIVO[] = "doentes.dat";

    // Carga inicial do arquivo

    cout << "Carga inicial de arquivo con datos de doentes" << endl;

    cargarArquivo (ARQUIVO, variosDoentes);

       cout << "\nBenvido a XesSANITAR--Sistema xestor de centros hospitalarios.\n";
    do {
        opcion = menu();
        switch ( opcion ) {
            case 1: listarDoentes(variosDoentes); // Funcionalidade proporcionada
                    break;
            case 2: engadirDoente(variosDoentes);
                    break;
            case 3: eliminarDoente(variosDoentes);
                    break;
            case 4: buscarDoenteCOD(variosDoentes);
                    break;
            case 5: buscarDoenteDNI(variosDoentes);
                    break;
            case 6: modificarDoente(variosDoentes);
                    break;
            case 7: mostrarPorConsulta(variosDoentes);
                    break;
            case 8: modificarArchivo(ARQUIVO);
                    break;
            case 9: guardarArchivo(ARQUIVO, variosDoentes);
                    break;
        }
    } while ( opcion != 9 );
    return 0;
}

int menu()
{
    int opcion;

    cout << "\n######################################################\n";
    cout << "\nQue operacion desexa realizar?";
    do {
        cout << "\n1. Listar doentes";
        cout << "\n2. Inserir doente";
        cout << "\n3. Eliminar doente";
        cout << "\n4. Buscar doente por codigo";
        cout << "\n5. Buscar doente por DNI";
        cout << "\n6. Modificar datos dun doente";
        cout << "\n7. Visualizar doentes por cada tipo de consulta";
        cout << "\n8. Modificar arquivo directamente";
        cout << "\n9. Gardar arquivo e rematar\n";
        cout << "\n######################################################\n";

        opcion = lerEnteiro ( "Opcion: ");

    } while ( opcion < 0 || opcion > 9 );

    return opcion;
}
