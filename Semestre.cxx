#include "Semestre.h"
/*#include "Asignatura.h"
#include "Estudiante.h"*/
// -------------------------------------------------------------------------
Semestre::Semestre( std::string idSemestre )
{
	this->idSemestre = idSemestre;
	Asignaturas asignaturas;
	this->asignaturas = asignaturas;
	Alumnos al;
	this->alumnos = al;
}

// -------------------------------------------------------------------------
Semestre::~Semestre( )
{
}

// -------------------------------------------------------------------------
const std::string& Semestre::GetIdSemestre( ) const
{
	return( this->idSemestre );
}

// -------------------------------------------------------------------------
void Semestre::SetIdSemestre( const std::string& idSemestre )
{
	this->idSemestre = idSemestre;
}

// -------------------------------------------------------------------------
bool Semestre::insertarAsignatura( const std::string nombre,const std::string idAsignatura, 
			           const std::string idClase, const std::string numero, const std::string dia, 
			           const std::string horaInicio, const std::string horaFin, const std::string salon )
{
	bool exitooperacion = false;
	
	if( this->asignaturas.empty() )
	{
		Asignatura nueva( nombre, idAsignatura );
		exitooperacion = nueva.insertarClase(idClase, numero, dia, horaInicio, horaFin, salon);
		this->asignaturas.push_back( nueva );
		//llamado a insertar clase
	}else
	{
		Asignaturas::iterator it = this->asignaturas.begin();
		bool flag = true;
		while( it!=this->asignaturas.end() && flag )	
		{
			if( it->GetIdAsignatura() == idAsignatura )//la asignatura existe
			{
				exitooperacion = (*it).insertarClase(idClase, numero, dia, horaInicio, horaFin, salon);
				flag=false;

			}else//la asigntaura no existe
			{
				Asignatura nueva( nombre, idAsignatura );
				exitooperacion = nueva.insertarClase(idClase, numero, dia, horaInicio, horaFin, salon);
				this->asignaturas.push_back( nueva );
				flag=false;
				//llamado a insertar clase				
			}
			it++;
		}
	}
	
	return exitooperacion;
}

bool Semestre::agregarEstudiante( const std::string nombre, const std::string idAsignatura, 				  	 					  const std::string idClase,  const std::string idEstudiante )
{
	bool exito = false;
	if(this->alumnos.empty())
	{
		Estudiante nuevo(nombre,idEstudiante);
		exito = nuevo.inscribirEstudianteClase(idClase);
		this->alumnos.push_back(nuevo);
	}else
	{
		Alumnos::iterator it = this->alumnos.begin();
		bool flag = true;
		while( it != this->alumnos.end() && flag )
		{
			if(it->GetIdEstudiante() == idEstudiante)
			{
				if(this->inscribirEstudianteClase(idAsignatura,idClase,idEstudiante))
				{
					exito = (*it).inscribirEstudianteClase(idClase);
					flag = false;
				}

			}
			else
			{
				Estudiante nuevo(nombre,idEstudiante);
				exito = nuevo.inscribirEstudianteClase(idClase);
				this->alumnos.push_back(nuevo);
				flag = false;
			}
			it++;
		}
	return exito;		
	}
}

bool Semestre::inscribirEstudianteClase(const std::string idAsignatura,const std::string idClase,  const std::string idEstudiante ){
	bool exito = false;
	bool flag = true ;
	if(this->asignaturas.empty())
	{
		std::cout<<"No hay info de asignaturas"<<std::endl;
		exito = false;
	}else
	{
		Asignaturas::iterator it = this->asignaturas.begin();
		bool flag = true;
		while( it!= this->asignaturas.end() && flag )
		{
			if(it->GetIdAsignatura() == idAsignatura)
			{
				exito = (*it).inscribirAlumnoClase(idClase,idEstudiante);
				flag = false;
			}
			it++;
		}
	}
	if(flag)
	{
	  std::cout<<"No se encuentra la asginatura"<<std::endl;
	  exito=false;
	}
	return exito;
}
	

void Semestre::imprimirHorario(const std::string idEstudiante)
{
	if(this->alumnos.empty())
	{
		std::cout<<"No hay alumnos "<<std::endl;
	}else
	{
		Alumnos::iterator it = this->alumnos.begin();
		bool flag =true;
		while(it!=this->alumnos.end()&&flag)
		{
			if(it->GetIdEstudiante() == idEstudiante)
			{
				std::deque< std::string > Clases;
				Clases = (*it).imprimirHorario();
				flag = false;
				std::deque< std::string > ::iterator s = Clases.begin();
				while(s != Clases.end())
				{
					std::string asi;
					asi = (*s);
					Asignaturas::iterator as = this->asignaturas.begin();
					while(as != asignaturas.end())
					{
						(*as).imprimirHorario(asi);
						as ++;
					}
				s ++;
				}
			}
		it ++;
		}
	}
}
