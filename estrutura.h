#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED

    # define MAXDOENTES 200
    # define MAXDNI 10
    # define MAXCODIGO 11
    # define MAXNOME 50
    # define MAXDOMICILIO 50
    # define MAXTIPOCONSULTA 16

    const char tipoConsulta1 [] = "externa";
    const char tipoConsulta2 [] = "hospitalizacion";

    struct data {
        unsigned int dia;
        unsigned int mes;
        unsigned int ano;
    };

    struct Doente {
        char nome [ MAXNOME ];
        char DNI [ MAXDNI ];
        char domicilio [ MAXDOMICILIO ];
        char codigo [ MAXCODIGO ];
        char tipoConsulta [ MAXTIPOCONSULTA ];
        data nacemento;
    };

    struct setDoentes {
        Doente Doentes[ MAXDOENTES ];  // Array onde almacenamos todos os doentes
        int numDoentes;  // numero total de doentes existentes no vector Doentes
    };

#endif // ESTRUTURA_H_INCLUDED
