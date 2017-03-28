#include "Asignatura.h"
/*#include "Clase.h"
#include "Estudiante.h"*/

// -------------------------------------------------------------------------
Asignatura::Asignatura( std::string nombre, std::string idAsignatura )
{
	this->nombre = nombre;
	this->idAsignatura = idAsignatura;
	Clases clasesOfertadas;
	this->clasesOfertadas =	clasesOfertadas;
}

// -------------------------------------------------------------------------
Asignatura::~Asignatura( )
{
}

// -------------------------------------------------------------------------
void Asignatura::SetNombre( const std::string& nombre )
{
	this->nombre = nombre;
}

// -------------------------------------------------------------------------
void Asignatura::SetIdAsignatura( const std::string& idAsignatura )
{
	this->idAsignatura = idAsignatura;
}

// -------------------------------------------------------------------------
const std::string& Asignatura::GetNombre( ) const
{
	return( this->nombre );
}

// -------------------------------------------------------------------------
const std::string& Asignatura::GetIdAsignatura( ) const
{
	return( this->idAsignatura );
}

// -------------------------------------------------------------------------
bool Asignatura::insertarClase( const std::string idClase, const std::string numero, 
			 const std::string dia, const std::string horaInicio, const std::string horaFin,
			 const std::string salon )
{
	bool exitooperacion = false;
	if( this->clasesOfertadas.empty() )
	{
		Clase nueva( this->idAsignatura, idClase );
		exitooperacion = nueva.insertarSesion( numero, dia, horaInicio, horaFin, salon );
		this->clasesOfertadas.push_back( nueva );		
	}
	else
	{
		Clases::iterator it = this->clasesOfertadas.begin();
		bool flag = true;
		while(it!=this->clasesOfertadas.end() && flag)
		{
			if(it->GetIdClase() == idClase)
			{
				exitooperacion = (*it).insertarSesion( numero, dia, horaInicio, horaFin, salon );//llamado		
				flag=false;
			}
			else
			{
				Clase nueva( this->idAsignatura, idClase );
				exitooperacion = nueva.insertarSesion( numero, dia, horaInicio, horaFin, salon );
				this->clasesOfertadas.push_back( nueva );	
				flag=false;
			}			
			it++;
		}		
	}
	
	return exitooperacion;
}


bool Asignatura::inscribirAlumnoClase(const std::string idClase,const std::string idEstudiante)
{
	bool exito = false;
	bool flag = true;
	if(this->clasesOfertadas.empty())
	{
		std::cout<<"No hay clases de esta asignatura"<<std::endl;
		exito =false;
	}else
	{
		Clases::iterator it = this->clasesOfertadas.begin();
		bool flag = true;
		while(it != this->clasesOfertadas.end() && flag)
		{
			if(it->GetIdClase() == idClase)
			{
				exito = (*it).inscribirAlumnoClase(idEstudiante);
				flag=false;				
			}
			it++;
		}
	}
	if(flag)
	{
	  std::cout<<"No se encuentra la clase"<<std::endl;
	  exito=false;
	}
	return exito;

}

void Asignatura::imprimirHorario(const std::string idClase){

	bool flag = false;
	Clases::iterator it = this->clasesOfertadas.begin();
	while(it != this->clasesOfertadas.end() && flag )
	{
		if(it->GetIdClase() == idClase)
			{
				std::cout<<"CLASE: "<<idClase<<std::endl;
				(*it).imprimirHorario();
				flag=true;				
			}
			it++;
	}
}

