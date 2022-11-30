#ifndef Doente_H_INCLUDED
#define Doente_H_INCLUDED

    # include "estrutura.h"

    // Declaracións das funcións necesarias específicas para xestionar doentes
    void buscarDoenteDNI(setDoentes &variosDoentes);
    void buscarDoenteCOD(setDoentes &variosDoentes);
    void mostrarPorConsulta(setDoentes &variosDoentes);
    int buscarPosicionDoenteDNI(setDoentes &variosDoentes, char buscador []);
    int buscarPosicionDoenteCodigo(setDoentes &variosDoentes, char buscador []);
    void engadirDoente (setDoentes &variosDoentes);
    bool comprobarFecha(int mes, int dia);
    void eliminarDoente(setDoentes &variosDoentes);
    void modificarDoente(setDoentes &variosDoentes);
    int obtenerTipoConsulta(setDoentes &variosDoentes);
    void guardarTipoConsulta(setDoentes &variosDoentes, Doente &d, int consulta);
    // Funcionalidades proporcionadas
    void amosarDoente ( Doente oDoente );
    void listarDoentes ( setDoentes &variosDoentes );


#endif // UTIL_H_INCLUDED
