#include "Clase.h"
/*#include "Sesion.h"
#include "Estudiante.h"*/

// -------------------------------------------------------------------------
Clase::Clase( std::string idAsignatura,std::string idClase )
{
	this->idAsignatura = idAsignatura;
	this->idClase = idClase;
	Sesiones listaSesiones;
	this->listaSesiones = listaSesiones;
	Alumnos alumnos;
	this->alumnos = alumnos;
}

// -------------------------------------------------------------------------
Clase::~Clase( )
{
}

// -------------------------------------------------------------------------
void Clase::SetIdClase( const std::string& idClase )
{
	this->idClase = idClase;
}

// -------------------------------------------------------------------------
const std::string& Clase::GetIdClase( ) const
{
	return( this->idClase );
}

// -------------------------------------------------------------------------
bool Clase::insertarSesion( const std::string numero, const std::string dia, 
			  const std::string horaInicio, const std::string horaFin, const std::string salon )
{

	bool exitooperacion = false;

	if( this->listaSesiones.empty() )
	{
		Sesion nueva( this->GetIdClase(), numero, dia, horaInicio, horaFin, salon );
		this->listaSesiones.push_back( nueva );
		exitooperacion = true;
	}else
	{
		Sesiones::iterator it = this->listaSesiones.begin();
		bool flag = true;
		while(it!=this->listaSesiones.end() && flag)
		{
			if(it->GetNumero() == numero)
			{
				std::cout<<"Ya creo esta sesion"<<std::endl;
				exitooperacion = false;
				flag=false;
			}else
			{
				Sesion nueva( this->idClase, numero, dia, horaInicio, horaFin, salon );
				this->listaSesiones.push_back( nueva );		
				exitooperacion = true;
				flag=false;
			}
			it++;			
		}
	}
	return exitooperacion;
}

bool Clase::inscribirAlumnoClase(const std::string idEstudiante)
{
	bool exito = false;
	Alumnos::iterator it = this->alumnos.begin();
	bool flag = true;
	while( it != this->alumnos.end() && flag)
	{
		if((*it)==idEstudiante)
		{
			std::cout<<"Ya esta inscrito el estudiante"<<std::endl;
			exito = false;
			flag=false;
		}
		it++;
	}
	if(flag)
	{
		this->alumnos.push_back(idEstudiante);
		std::cout<<"Alumno asociado a clase"<<std::endl;
		exito = true;		
	}
	return exito;
}

void Clase::imprimirHorario()
{
	Sesiones::iterator it = this->listaSesiones.begin();
	std::cout<<"SESION: "<<std::endl;
	while (it != this->listaSesiones.end())
	{
		std::cout<<"Numero: "<<it->GetNumero()<<std::endl;
		std::cout<<"Hora Inicio: "<<it->GetHoraInicio()<<std::endl;
		std::cout<<"Salon: "<<it->GetSalon()<<std::endl;
		it++;
	}
}

