/**
Archivo: Lobby.h
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
  CLASE: Lobby
  INTENCIÓN: Desarrollar una clase donde se permita recolectar el numero de participantes y 
  la dificultad deseada del o de los bots.
  RELACIONES: Ninguna.
*/

#ifndef _LOBBY_H_
#define _LOBBY_H_

#include <iostream>
#include "windows.h"
#include <vector>

using namespace std;

class Lobby
{
    private:
        HANDLE identificador_de_pantalla_del_lobby;
        COORD posicion_x_y_del_lobby;
        bool continuar;
        int numero_de_jugadores = 0;
        vector <string> nombres_de_jugadores;
         int numero_de_bots = 0;
        vector <string> nombres_de_bots;
        vector <string> dificultad_de_bots;
        int ancho_del_tablero = 0;
        int alto_del_tablero = 0;

    public:
        Lobby(); /** Genera la pantalla de inicio del juego */
        ~Lobby(); /** Destructor */
        void preguntar_las_dimenciones_del_tablero(); /** Solicita las dimensiones de la tabla que se requiera generar */
        void preguntar_por_jugadores(); /** Solicita el numero de jugadores que van a jugar y sus nombres */
        void preguntar_por_bots(); /**  Solicita el numero de bots que van a jugar y sus dificultades  */
        int devolver_dimencion_x(); /** Devuelve el ancho de la tabla que se requiera generar */
        int devolver_dimencion_y(); /** Devuelve el alto de la tabla que se requiera generar */
        int devolver_numero_de_jugadores(); /** Devuelve el numero de personas que van a jugar */
        string devolver_jugador(int numero_de_jugador); /** Devuelve el nombre de una persona que van a jugar */
        int devolver_numero_de_bots(); /** Devuelve el numero de bots que van a jugar */
        string devolver_bot(int numero_de_bot); /** Devuelve el nombre de un bot que van a jugar */
        string devolver_dificultad_del_bot(int numero_de_bot); /** Devuelve la dificultad de un bot que van a jugar */
};

#endif

