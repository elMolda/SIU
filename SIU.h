#ifndef __SIU__H__
#define __SIU__H__

#include <iostream>

#include <string>
#include <deque>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <ostream>
#include "Semestre.h"

typedef std::deque<Semestre> Semestres; 
class SIU
{

 public:
	SIU( );
	virtual ~SIU( );

	void leerArchivoA ( const std::string nombre_arc);
	void leerArchivoEst ( const std::string nombre_arc);
	const Semestres& GetSemestres(  ) const;
	void SetSemestres( const Semestres sem );

	void imprimirHorario(const std::string idSemestre, const std::string idEstudiante);
	
	bool insertarAsignatura(const std::string idSemestre, const std::string nombre, const std::string idAsignatura, 
			const std::string idClase, const std::string numero, const std::string dia, 
			const std::string horaInicio, const std::string horaFin, const std::string salon );
	bool insertarEstudiante( const std::string idSemestre, const std::string nombre, const std::string idAsignatura, 				  	 const std::string idClase,  const std::string idEstudiante );


 protected:

	Semestres semestres;
};

#endif

