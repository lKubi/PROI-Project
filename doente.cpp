# include <iostream>

# include <cstring>

# include "doente.h"
# include "util.h"
# include "estrutura.h"

using namespace std;

void amosarDoente( Doente oDoente )
{
    char meses [ ][ 12 ] = {"xaneiro", "febreiro", "marzo", "abril", "maio", "xunho", "xullo", "agosto", "setembro", "outubro", "novembro", "decembro"};      // Para visualizar os meses
    cout << "\n\tNome: " << oDoente.nome;
    cout << "\n\tDNI: " << oDoente.DNI;
    cout << "\n\tDomicilio: " << oDoente.domicilio;
    cout << "\n\tCodigo: " << oDoente.codigo;
    cout << "\n\tTipoConsulta: " << oDoente.tipoConsulta;
    cout << "\n\tData de nacemento: " << oDoente.nacemento.dia << " de " << meses [ oDoente.nacemento.mes -1 ] << " de " << oDoente.nacemento.ano << endl;
    cout << "\n------------------------------------------------------\n";
}

void listarDoentes( setDoentes &variosDoentes )  // Listar todas os doentes
{
    int i;
    if ( variosDoentes.numDoentes == 0 ) {
        cout << "\nNon existen doentes que listar.\n";
    }
    else {
        cout << "\nListando doentes...\n";
        for (i = 0; i < variosDoentes.numDoentes; i++ ) {
            cout << "\nDoente : " << i+1;
            amosarDoente( variosDoentes.Doentes[ i ] );
        }
    }
}

int buscarPosicionDoenteDNI(setDoentes &variosDoentes, char buscador []){
    int indice = -1;
    for(int i = 0; i<variosDoentes.numDoentes; i++){
        if(strcmp(variosDoentes.Doentes[i].DNI, buscador) == 0){
            indice = i;
        }
    }

    return indice;
}

void buscarDoenteDNI(setDoentes &variosDoentes){
    Doente d;
    bool existe = false;
    char dni [MAXDNI];

    lerCadea("Introduce el DNI que desees buscar: ", dni);

    int indiceDoente = buscarPosicionDoenteDNI(variosDoentes, dni);

    if(indiceDoente != -1){
        d = variosDoentes.Doentes[indiceDoente];
        amosarDoente(d);
    }else{
        cout<<"Paciente no encontrado";
    }
}

int buscarPosicionDoenteCodigo(setDoentes &variosDoentes, char buscador []){
    int indice = -1;
    for(int i = 0; i<variosDoentes.numDoentes; i++){
        if(strcmp(variosDoentes.Doentes[i].codigo, buscador) == 0){
            indice = i;
        }
    }

    return indice;
}

void buscarDoenteCOD(setDoentes &variosDoentes){
    Doente d;
    bool existe = false;
    char cod [MAXCODIGO];

    lerCadea("Introduce el codigo que desees buscar: ", cod);

    int indiceDoente = buscarPosicionDoenteCodigo(variosDoentes, cod);

    if(indiceDoente != -1){
        d = variosDoentes.Doentes[indiceDoente];
        amosarDoente(d);
    }else{
        cout<<"No existe un paciente con ese codigo" << endl;
    }
}

int obtenerTipoConsulta(setDoentes &variosDoentes){

    int opcion;
    do{
        opcion = lerEnteiro("Introduce la busqueda: \n1) Externa\n2) Hospitalizacion\nOpcion: ");
    }while(opcion<1 || opcion > 2);

    return opcion;
}

void guardarTipoConsulta(setDoentes &variosDoentes, Doente &d, int consulta){

    if(consulta == 1){
        strcpy(d.tipoConsulta, tipoConsulta1);
    }else{
        strcpy(d.tipoConsulta, tipoConsulta2);
    }
}

void mostrarPorConsulta(setDoentes &variosDoentes){
    int opcion;

//  const char tipoConsulta1 [] = "externa";
//  const char tipoConsulta2 [] = "hospitalizacion";

    opcion = obtenerTipoConsulta(variosDoentes);


}

bool comprobarFecha(int dia, int mes, int ano){

    //31: 1, 3, 5, 7, 8, 10, 12
    //30: 4,6,9,11
    //28-29: 2
    int limite;

    if(mes == 2){
        if(ano%4 == 0){
            limite = 29;
        }else{
            limite = 28;
        }
    }else if(mes == 1 || mes == 3 || mes == 5 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        limite = 31;
    }else{
        limite = 30;
    }

    if((dia >= 1) && dia < limite){
        cout<<dia << " " << mes << " " << ano << " " << limite << " true" << endl;
        return true;
    }else{
        cout<<dia << " " << mes << " " << ano << " " << limite <<  " false" << endl;
        return false;
    }
}

void engadirDoente (setDoentes &variosDoentes){

    int indice;

    lerCadea("\nIntroducir el nombre completo del paciente: ", variosDoentes.Doentes[variosDoentes.numDoentes].nome);

    do{
        lerCadea("\nIntroduce el DNI del paciente: ", variosDoentes.Doentes[variosDoentes.numDoentes].DNI);
        indice = buscarPosicionDoenteDNI(variosDoentes, variosDoentes.Doentes[variosDoentes.numDoentes].DNI);
        if(indice != -1 ){
            cout<<"\nEl DNI ya se encuentra en la base de datos!";
        }
    }while(indice != -1);

    lerCadea("\nIntroduce el domicilio del paciente: ", variosDoentes.Doentes[variosDoentes.numDoentes].domicilio);

    do{
        lerCadea("\nIntroduce el codigo del paciente (10 digitos alfanumericos): ", variosDoentes.Doentes[variosDoentes.numDoentes].codigo);
        indice = buscarPosicionDoenteCodigo(variosDoentes, variosDoentes.Doentes[variosDoentes.numDoentes].codigo);
        if(indice != -1 ){
            cout<<"\nEl codigo ya se encuentra en la base de datos!";
        }
    }while(indice != -1);

    int opcion = 0;

    do{
        opcion = lerEnteiro("\n1) Externa\n2) Hospitalizacion\nOpcion: ");
    }while(opcion<1 || opcion > 2);

    if(opcion == 1){
        strcpy(variosDoentes.Doentes[variosDoentes.numDoentes].tipoConsulta, tipoConsulta1);
    }else{
        strcpy(variosDoentes.Doentes[variosDoentes.numDoentes].tipoConsulta, tipoConsulta2);
    }

    do{
        variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.ano = lerEnteiro("\nIntroduce el ano de nacimiento: ");
    }while(variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.ano > 2022);

    do{
        variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.mes = lerEnteiro("\nIntroduce el mes de nacimiento (1-12): ");
    }while(variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.mes < 1 || variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.mes > 12);

    int dia;
    bool fechavalida;

    do{
        dia  = lerEnteiro("\nIntroduce el dia de nacimiento ");
        fechavalida = comprobarFecha(dia, variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.mes, variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.ano);
    }while(!fechavalida);

    variosDoentes.Doentes[variosDoentes.numDoentes].nacemento.dia = dia;

    variosDoentes.numDoentes++;
}

void eliminarDoente(setDoentes &variosDoentes){
        int opcion;
    do{
        opcion = lerEnteiro("\nIntroduce la opcion por la que deseas buscar al paciente.\n1) DNI\n2) Codigo\nOpcion: ");
    }while(opcion < 1 || opcion > 2);


    char verificacion;
    if(opcion == 1){
        char dni [MAXDNI];
        lerCadea("\nIntroduce el DNI que desees buscar: ", dni);
        int indice = buscarPosicionDoenteDNI(variosDoentes, dni);

        if(indice == -1 ){
            cout<<"\nNo se ha encontrado ningun paciente con ese DNI!";
        }else{
            amosarDoente(variosDoentes.Doentes[indice]);
            verificacion = lerEnteiro("Deseas eliminar este paciente? (Introducir '1' si estas seguro, sino, introducir cualquier numero menos el 1): ");
            if(verificacion == 1){
                cout<<"\nEliminando paciente...\n";
                for(int i = indice; i<variosDoentes.numDoentes; i++){
                    variosDoentes.Doentes[i] = variosDoentes.Doentes[i+1];
                }
                cout<<"\nPaciente eliminado!";
                variosDoentes.numDoentes--;
            }else{
                cout<<"\nCancelando accion!";
            }
        }
    }else{

        char codigo [MAXCODIGO];
        lerCadea("\nIntroduce el codigo que desees buscar: ", codigo);
        int indice = buscarPosicionDoenteCodigo(variosDoentes, codigo);

        if(indice == -1 ){
            cout<<"\nNo se ha encontrado ningun paciente con ese codigo!";
        }else{
            amosarDoente(variosDoentes.Doentes[indice]);
            verificacion = lerEnteiro("Deseas eliminar este paciente? (Introducir '1' si estas seguro, sino, introducir cualquier numero menos el 1): ");
            if(verificacion == 1){
                cout<<"\nEliminando paciente...\n";
                for(int i = indice; i<variosDoentes.numDoentes; i++){
                    variosDoentes.Doentes[i] = variosDoentes.Doentes[i+1];
                }
                cout<<"\nPaciente eliminado!";
                variosDoentes.numDoentes--;
            }else{
                cout<<"\nCancelando accion!";
            }
        }
    }

}

void modificarDoente(setDoentes &variosDoentes){

    int opcion;

    do{
        opcion = lerEnteiro("Que criterio quieres usar para buscar:\n1) DNI \n2) Codigo\nOpcion: ");
    }while(opcion < 1 || opcion > 2);

    int indice;

    if(opcion == 1){
        char dni [MAXDNI];

        lerCadea("Introduce el DNI del paciente: ", dni);
        indice = buscarPosicionDoenteDNI(variosDoentes, dni);
        cout<<"Mostrando paciente...\n";
        amosarDoente(variosDoentes.Doentes[indice]);

//Copiar a partir de aqui

        cout<<"Nombre actual: " << variosDoentes.Doentes[indice].nome << endl;
        lerCadea("Nuevo nombre: ", variosDoentes.Doentes[indice].nome);

        cout<<"DNI actual: " << variosDoentes.Doentes[indice].DNI << endl;
        do{
            lerCadea("Nuevo DNI: ", dni);
            if(buscarPosicionDoenteDNI(variosDoentes, dni) != -1){
                cout<<"El DNI ya se encuentra en la base de datos\n";
            }
        }while(buscarPosicionDoenteDNI(variosDoentes, dni) != -1);

        strcpy(variosDoentes.Doentes[indice].DNI, dni);

        cout<<"Codigo actual: " << variosDoentes.Doentes[indice].codigo << endl;
        lerCadea("Nuevo Codigo: ", variosDoentes.Doentes[indice].codigo);

        cout<<"Domicilio actual: " << variosDoentes.Doentes[indice].domicilio << endl;
        lerCadea("Nuevo domicilio: ", variosDoentes.Doentes[indice].domicilio);

        cout<<"Tipo de consulta actual: " << variosDoentes.Doentes[indice].tipoConsulta << endl;
        int consulta;
        consulta = obtenerTipoConsulta(variosDoentes);
        guardarTipoConsulta(variosDoentes, variosDoentes.Doentes[indice], consulta);

        cout<<"Ano actual: " << variosDoentes.Doentes[indice].nacemento.ano;
        do{
            variosDoentes.Doentes[indice].nacemento.ano = lerEnteiro("\nIntroduce el nuevo ano de nacimiento: ");
        }while(variosDoentes.Doentes[indice].nacemento.ano > 2022);

        cout<<"Mes actual: " << variosDoentes.Doentes[indice].nacemento.mes;
        do{
            variosDoentes.Doentes[indice].nacemento.mes = lerEnteiro("\nIntroduce el nuevo mes de nacimiento (1-12): ");
        }while(variosDoentes.Doentes[indice].nacemento.mes < 1 || variosDoentes.Doentes[indice].nacemento.mes > 12);

        int dia;
        bool fechavalida;
        cout<<"Dia actual: " << variosDoentes.Doentes[indice].nacemento.dia;
        do{
            dia  = lerEnteiro("\nIntroduce el nuevo dia de nacimiento ");
            fechavalida = comprobarFecha(dia, variosDoentes.Doentes[indice].nacemento.mes, variosDoentes.Doentes[indice].nacemento.ano);
        }while(!fechavalida);

        variosDoentes.Doentes[indice].nacemento.dia = dia;

    }else{
        char codigo [MAXCODIGO];
        char dni [MAXDNI];
        lerCadea("Introduce el codigo del paciente: ", codigo);
        indice = buscarPosicionDoenteCodigo(variosDoentes, codigo);
        cout<<"Mostrando paciente...\n";
        amosarDoente(variosDoentes.Doentes[indice]);


        cout<<"Nombre actual: " << variosDoentes.Doentes[indice].nome << endl;
        lerCadea("Nuevo nombre: ", variosDoentes.Doentes[indice].nome);

        cout<<"DNI actual: " << variosDoentes.Doentes[indice].DNI << endl;
        do{
            lerCadea("Nuevo DNI: ", dni);
            if(buscarPosicionDoenteDNI(variosDoentes, dni) != -1){
                cout<<"El DNI ya se encuentra en la base de datos\n";
            }
        }while(buscarPosicionDoenteDNI(variosDoentes, dni) != -1);

        strcpy(variosDoentes.Doentes[indice].DNI, dni);

        cout<<"Codigo actual: " << variosDoentes.Doentes[indice].codigo << endl;
        lerCadea("Nuevo Codigo: ", variosDoentes.Doentes[indice].codigo);

        cout<<"Domicilio actual: " << variosDoentes.Doentes[indice].domicilio << endl;
        lerCadea("Nuevo domicilio: ", variosDoentes.Doentes[indice].domicilio);

        cout<<"Tipo de consulta actual: " << variosDoentes.Doentes[indice].tipoConsulta << endl;
        int consulta;
        consulta = obtenerTipoConsulta(variosDoentes);
        guardarTipoConsulta(variosDoentes, variosDoentes.Doentes[indice], consulta);

        cout<<"Ano actual: " << variosDoentes.Doentes[indice].nacemento.ano;
        do{
            variosDoentes.Doentes[indice].nacemento.ano = lerEnteiro("\nIntroduce el nuevo ano de nacimiento: ");
        }while(variosDoentes.Doentes[indice].nacemento.ano > 2022);

        cout<<"Mes actual: " << variosDoentes.Doentes[indice].nacemento.mes;
        do{
            variosDoentes.Doentes[indice].nacemento.mes = lerEnteiro("\nIntroduce el nuevo mes de nacimiento (1-12): ");
        }while(variosDoentes.Doentes[indice].nacemento.mes < 1 || variosDoentes.Doentes[indice].nacemento.mes > 12);

        int dia;
        bool fechavalida;
        cout<<"Dia actual: " << variosDoentes.Doentes[indice].nacemento.dia;
        do{
            dia  = lerEnteiro("\nIntroduce el nuevo dia de nacimiento ");
            fechavalida = comprobarFecha(dia, variosDoentes.Doentes[indice].nacemento.mes, variosDoentes.Doentes[indice].nacemento.ano);
        }while(!fechavalida);
        variosDoentes.Doentes[indice].nacemento.dia = dia;
    }

}
