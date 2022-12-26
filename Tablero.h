/**
Archivo: Tablero.h
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
CLASE: Tablero
INTENCION: Crear un tablero de juego que pueda ser modificado.
RELACIONES: Conoce a la clase Cursor. (Tambien se puede ver como contiene una copia de la clase Cursor por medio
de argumentos)
*/

#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include "Cursor.h"

class Tablero
{
	private:
		int dimension_x_del_tablero = 3;
		int dimension_y_del_tablero = 1;
		HANDLE identificador_de_pantalla_del_tablero;
		COORD posicion_x_y_del_tablero;
		vector <vector <vector<bool>>> posiciones_con_rayas;

	public:
		Tablero(int una_dimension_x_del_tablero, int una_dimension_y_del_tablero); /** Crea un tablero con dimensiones de 20 puntos por 20 puntos */
		~Tablero(); /** Destructor */
		void ver_tablero(); /** Genera en la consola el tablero creado */
		void modificar_tablero(Cursor un_cursor); /** Permite mover el cursor a lo largo y ancho del tablero */
		void guardar_modificacion_del_tablero(Cursor un_cursor); /** Guarda en el tablero una linea marcada por el jugador por el resto del juego */
		int cuadros_construidos(Cursor un_cursor); /** Indica cuantos cuadros se acaban de construir en el tablero */
};

#endif

