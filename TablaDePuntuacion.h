/**
Archivo: TablaDePuntuacion.h
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
CLASE: Tabla De Puntuacion
INTENCION: Crear una tabla que mantenga el registro de los participantes y otros datos del juego y 
que ademas permita concer el turno de los participantes.
RELACIONES: Conoce las clases Lobby, Tablero y Cursor.
*/

#ifndef _TABLADEPUNTUACION_H_
#define _TABLADEPUNTUACION_H_

#include <iostream>
#include <vector>
#include "Lobby.h"
#include "Tablero.h"
#include "Cursor.h"

using namespace std;

class TablaDePuntuacion
{
    private:
        vector <string> lista_de_participantes;
        vector <int> puntuacion_de_los_participantes;
        vector <string> dificultad_de_los_participantes_bots;
        int turno = 0;
        HANDLE identificador_de_pantalla_de_la_tabla;
        COORD posicion_x_y_de_la_tabla;

    public:
        TablaDePuntuacion(Lobby un_lobby); /** Crea una tabla compuesta de varios vectores y cada una con un mismo numero de entradas, que contengan la informacion del juego */
        ~TablaDePuntuacion(); /** Destructor */
        void modificar_puntuacion(Tablero un_tablero, Cursor un_cursor); /** Aumenta un punto al jugador que acaba de marcar en caso de que haya construido uno o dos cuadro en el tablero */
        void pasar_turno(Tablero un_tablero, Cursor un_cursor); /** Pasa el turno al siguiente participante en caso de que este no haya logrado completar ni un cuadro */
        bool turno_de_un_bot(); /** Indica si es el turno de un bot o no */
        string devolver_dificultad_del_bot(); /** Indica cual es la dificultad del bot que va a realizar un movimiento */
        bool fin_del_juego(Lobby un_lobby); /** Indica si el juego ya acabo basandose en la suma de puntos que tienen todos los jugadores */
        string ganador(); /** Indica quien fue el ganador basandose en el la tabla de puntuacion */
};

#endif

