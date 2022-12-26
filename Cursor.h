/**
Archivo: cursor.h
Autores: Juan Sebastian Cifuentes Vallejo <juan.cifuentes.vallejo@correounivalle.edu.co>,
Jhonnier Albeiro Hernandez Brito <jhonnier.hernandez@correounivalle.edu.co>,
Natan Gabriel Medina Corea <natan.medina@correonivalle.edu.co>,
Mike Guzmán García <mike.guzman@correounivalle.edu.co>
Fecha de creacion: 2022-08-08
Fecha última modificación: 2022-08-08
Licencia: GPL
*/

/**
CLASE: Cursor
INTENCION: Crear un cursor que permita a los jugadores comunicarse con el programa y jugar.
RELACIONES: Ninguna.
*/

#ifndef _CURSOR_H_
#define _CURSOR_H_
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>

using namespace std;

class Cursor
{
	private:
		int limite_x_del_cursor = 3;
		int limite_y_del_cursor = 1;
		HANDLE cursor_cursor;
		COORD posicion_x_y_del_cursor;
		vector <vector <vector<bool>>> posiciones_prohibidas;

	public:
		Cursor(int un_limite_x_del_cursor, int un_limite_y_del_cursor); /** Crea un objeto de tipo cursor y le asigna una posicion (x,y) = (0,0) en la consola  */
		~Cursor(); /** Destructor del cursor */
		void mover(int px, int py); /** Aumenta o disminuye la posicion en el eje X o el eje Y del cursor (en la consola) */
		int posicion_x(); /** Devuelve un entero con la hubicacion en el eje X del cursor en la consola */
		int posicion_y(); /** Devuelve un entero con la hubicacion en el eje Y del cursor en la consola */
		void marcar_posicion_prohibida(); /** Marca las posiciones en el que el cursor no puede permanecer y deja el cursor en una posicion no prohibida*/
		void mover_a(int px, int py); /** Posiciona el cursor en una posicion del tablero */
		int devolver_limite_x_del_cursor(); /** Devuelve el valor maximo en el eje X sobre el que el cursor puede estar */
		int devolver_limite_y_del_cursor(); /** Devuelve el valor maximo en el eje Y sobre el que el cursor puede estar */
		bool posicion_prohibida(int px, int py); /** Indica si el cursor puede estar o no sobre una posicion especifica */
};

#endif
