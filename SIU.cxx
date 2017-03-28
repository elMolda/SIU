#include "SIU.h"
/*#include "Semestres.h"
#include "Estudiante.h"*/

// -------------------------------------------------------------------------
SIU::SIU(  )
{
	Semestres sem;
	this->semestres = sem;
}

// -------------------------------------------------------------------------
SIU::~SIU( )
{
}
// -------------------------------------------------------------------------
const Semestres& SIU::GetSemestres(  ) const
{
	return( this->semestres );
}

// -------------------------------------------------------------------------
void SIU::SetSemestres( const Semestres sem )
{
	this->semestres = sem;
}
void SIU::leerArchivoA ( const std::string nombre_arc)
{
	std::ifstream archivo;
	archivo.open( nombre_arc );
	std::string linea;
	

	if( archivo.is_open( ) )
	{
          std::getline(archivo,linea); //Lee la primera linea de la infromacion que no es util 
	  do
	  {
		std::string evaluar="Y";
		
		std::string idSemestre;
		std::string idAsignatura;
		std::string nombre;
		std::string idClase;
		std::string numero;
		std::string dia;
		std::string horaInicio;
		std::string horaFin;
		std::string salon;

                std::getline(archivo,linea);

		char* lineacpy;
		lineacpy = new char[linea.size() + 1];
		memcpy(lineacpy, linea.c_str(), linea.size() + 1);

		
		char * pch;

		pch = strtok (lineacpy,",\"");
		if(pch!=NULL)
			idSemestre.append(pch);
		
		pch = strtok (NULL,",\"");//preg
		pch = strtok (NULL,",\"");
		pch = strtok (NULL,",\"");
		pch = strtok (NULL,",\"");

		pch = strtok (NULL,",\"");
		if(pch!=NULL)
			idAsignatura.append(pch);
		
		pch = strtok (NULL,",\"");
		if(pch!=NULL)
			nombre.append(pch);
		
		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
			idClase.append(pch);

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
			numero.append(pch);
		
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string lun(pch);
		if(evaluar.compare(lun)==0)
		    dia = "Lunes";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string mar(pch);
		if(evaluar.compare(mar)==0)
		    dia = "Martes";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string mie(pch);
		if(evaluar.compare(mie)==0)
		    dia = "Miercoles";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string jue(pch);
		if(evaluar.compare(jue)==0)
		    dia = "Jueves";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string vie(pch);
		if(evaluar.compare(vie)==0)
		    dia = "Viernes";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string sab(pch);
		if(evaluar.compare(sab)==0)
		    dia = "Sabado";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
		{
		std::string dom(pch);
		if(evaluar.compare(dom)==0)
		    dia = "Domingo";
		}

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
			horaInicio.append(pch);
		
		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
			horaFin.append(pch);
		
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");

		pch = strtok (NULL, ",\"");
		if(pch!=NULL)
			salon.append(pch);
		
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");
		pch = strtok (NULL, ",\"");
		
		bool crea = this->insertarAsignatura(idSemestre, nombre, idAsignatura, idClase, numero, dia,horaInicio, horaFin, salon);

		if( crea )
		{
			std::cout << "Insertado con exito" << std::endl;
		}else{
			std::cout << "Error insertando" << std::endl;			
		     }
		
		if( archivo.eof( ) )
  				archivo.close( );
	  } while( !archivo.eof( ) );
	 			
	}
	else 
		std::cout <<	 "Archivo no compatible "  <<std::endl;	
	archivo.close( );		
}
// -------------------------------------------------------------------------
bool SIU::insertarAsignatura(const std::string idSemestre, const std::string nombre, const std::string idAsignatura, 
			const std::string idClase, const std::string numero, const std::string dia, 
			const std::string horaInicio, const std::string horaFin, const std::string salon )
{
	//Semestres sem = this->GetSemestres();
	bool exitooperacion = false;
	//Verificar si la lista de semestres esta vacia
	if( this->semestres.empty() )
	{
		Semestre nuevo( idSemestre );
		exitooperacion=nuevo.insertarAsignatura( nombre, idAsignatura, idClase, numero, dia, horaInicio, horaFin, salon );
		this->semestres.push_back( nuevo );
	}else
	{
		//Verificar si el semestre que viene esta en la lista
		Semestres::iterator it = this->semestres.begin();
		bool flag = true;
		while(it!=this->semestres.end()&& flag)
		{
			if( it->GetIdSemestre() == idSemestre )//el semestre existe
			{
				exitooperacion = (*it).insertarAsignatura( nombre, idAsignatura, 
									idClase, numero, dia, horaInicio, horaFin, salon );
				flag=false;

			}else//el semestre no existe
			{
				Semestre nuevo( idSemestre );
				exitooperacion=nuevo.insertarAsignatura( nombre, idAsignatura,
									 idClase, numero, dia, horaInicio, horaFin, salon );
				this->semestres.push_back( nuevo );
				flag=false;
			}
			it++;
		}
	
	}

	return exitooperacion;

}

// -------------------------------------------------------------------------
void SIU::leerArchivoEst ( const std::string nombre_arc)
{
	std::ifstream archivo;
	archivo.open( nombre_arc );
	std::string linea;
	

	if( archivo.is_open( ) )
	{
          std::getline(archivo,linea); //Lee la primera linea de la infromacion que no es util 
	  do
	  {
		std::string idSemestre;
		std::string idAsignatura;
		std::string idEstudiante;
		std::string nombre;
		std::string idClase;

       		std::getline(archivo,linea);

		char* lineacpy;
		lineacpy = new char[linea.size() + 1];
		memcpy(lineacpy, linea.c_str(), linea.size() + 1);

		
		char * pch;

		pch = strtok (lineacpy,",\"");
		if(pch!=NULL)//idSem
			idSemestre.append(pch);
		
		pch = strtok (NULL,",\"");//id estudiante
		if(pch!=NULL)
			idEstudiante.append(pch);		
		
		pch = strtok (NULL,",\"");//apellidos
		std::string apel;
		if(pch!=NULL)
			apel.append(pch);
		
		pch = strtok (NULL,",\"");//nombre
		if(pch!=NULL){
			nombre.append(apel);
			nombre.append(pch);		
		}

		pch = strtok (NULL,",\"");
		pch = strtok (NULL,",\"");
		pch = strtok (NULL,",\"");
		pch = strtok (NULL,",\"");
		pch = strtok (NULL,",\"");
		
		pch = strtok (NULL,",\"");//id asignatura
		if(pch!=NULL)
			idAsignatura.append(pch);
		
		pch = strtok (NULL,",\"");//id clase 
		if(pch!=NULL)
			idClase.append(pch);
		bool crear = insertarEstudiante(idSemestre,nombre,idAsignatura,idClase,idEstudiante);
		if( crear )
		{
			std::cout << "Insertado con exito" << std::endl;
		}else{
			std::cout << "Error insertando" << std::endl;			
		     }
		
		if( archivo.eof( ) )
  				archivo.close( );
	  } while( !archivo.eof( ) );
	 			
	}
	else 
		std::cout <<	 "Archivo no compatible "  <<std::endl;	
	archivo.close( );
}

//-------------------------------------------------------------------------------------------------------------------------
bool SIU::insertarEstudiante( const std::string idSemestre, const std::string nombre, const std::string idAsignatura, 				  	 const std::string idClase,  const std::string idEstudiante )
{
	bool exito = false;
	if(this->semestres.empty())
	{
		std::cout << "No hay info de semestres"<< std::endl;
		exito = false;
	}
	else
	{
		Semestres::iterator it = this->semestres.begin();
		bool flag = true;
		while( it!= this->semestres.end() && flag )
		{
			if( it->GetIdSemestre () == idSemestre)
			{
				exito = (*it).agregarEstudiante(nombre,idAsignatura,idClase,idEstudiante);
				flag = false;
			}else
			{
				std::cout<<"No existe este semestre"<<std::endl;
				exito = false;
				flag = false;			
			}
			it++;
		}		
	}
	return exito;
	
}
// -------------------------------------------------------------------------
void SIU::imprimirHorario(const std::string idSemestre, const std::string idEstudiante)
{
	bool exito = false;
	bool flag = true;
	if(this->semestres.empty())
	{
		std::cout<<"No hay semestres cargados"<<std::endl;
		exito = false;		
	}else
	{
		Semestres::iterator it = this->semestres.begin();
		
		while(it!=this->semestres.end() && flag)
		{
			if(it->GetIdSemestre() == idSemestre)
			{
				std::cout<<"Semestre: "<< idSemestre <<std::endl;
				(*it).imprimirHorario(idEstudiante);
				flag = false; 			
			}
			it++;
		}		
	}
	if(flag)
	{
		std::cout<<"No existe ese semestre"<<std::endl;
	}	
}
