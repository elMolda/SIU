#ifndef __Clase__H__
#define __Clase__H__

#include <iostream>

#include <string>
#include <deque>
#include "Sesion.h"
#include "Estudiante.h"


class Clase
{
 public:
	Clase( std::string idAsignatura,std::string idClase );
	virtual ~Clase( );

	void SetIdClase( const std::string& idClase );
	
	bool insertarSesion( const std::string numero, const std::string dia, 
			  const std::string horaInicio, const std::string horaFin, const std::string salon );
	bool inscribirAlumnoClase(const std::string idEstudiante);

	void imprimirHorario();


	const std::string& GetIdClase( ) const;
	
 protected:
	typedef std::deque<Sesion> Sesiones;
	typedef std::deque<std::string> Alumnos;

 protected:
	
	std::string idAsignatura;
	std::string idClase;
	Sesiones listaSesiones;
	Alumnos alumnos;
};
#endif
