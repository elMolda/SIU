#include <iostream>
#include "SIU.h"

void menu( );

int main ( int argc, char* argv[] )
{
	SIU siuprueba;
	unsigned int opcion = 0;

	do
	{	
		menu( );
		std::cin >> opcion;
		switch ( opcion )  
      	{  
         	case 1 :  
		
            	std::cout << "Cargar Informacion de Asignaturas.." << std::endl;
            	std::cout << "Digite 11 para ayuda, 12 para continuar" << std::endl;
            	std::cin >> opcion;
		if( opcion == 11 )
            	{
			std::string nombreArch;
		    	std::cout << "Digite el nombre de un archivo .csv con la  informacion de Asignaturas,";
			std::cout <<" las cuales seran cargadas al sistema" << std::endl;
			std::cin >> nombreArch;
		    	siuprueba.leerArchivoA(nombreArch);

            	}else if( opcion == 12 )
            			{	
					std::string nombreArch;
					std::cout << "Digite el nombre del archivo a abrir" << std::endl;
					std::cin >> nombreArch;
            				siuprueba.leerArchivoA(nombreArch);
				
						
            			}
		
            break;  

         	case 2 :  
            	std::cout << "Cargar Informacion de Estudiantes.." << std::endl;
            	std::cout << "Digite 11 para ayuda, 12 para continuar" << std::endl;
            	std::cin >> opcion;
            	if( opcion == 11 )
            	{
			std::string nombreArch;
            		std::cout << "Digite el nombre de un archivo .csv con la informacion de Estudiantes,";
			std::cout<<" los cuales seran cargados al sistema" << std::endl;
			std::cin >> nombreArch;
            		siuprueba.leerArchivoEst(nombreArch);

            	}else if( opcion == 12 )
            			{
            				std::string nombreArch;
					std::cout << "Digite el nombre del archivo a abrir" << std::endl;
					std::cin >> nombreArch;
            				siuprueba.leerArchivoEst(nombreArch);
            			}  
            break;  

            case 3 :
            	std::cout << "Mostrar Horario Estudiante.." << std::endl;
            	std::cout << "Digite 11 para ayuda, 12 para continuar" << std::endl;
            	std::cin >> opcion;
            	if( opcion == 11 )
            	{
			std::string idE;
			std::string idS;
            		std::cout << "Digite el id de un Estudiante y el id de un semestre ";
			std::cout << "para ver su Horario en dicho semestre" << std::endl;
			std::cout << "Digite el id del estudiante: "<<std::endl;
			std::cin >> idE;
			std::cout << "Digite el id del semestre: "<<std::endl;
			std::cin >> idS;
			siuprueba.imprimirHorario(idS,idE);

            	}else if( opcion == 12 )
            			{
            				std::string idE;
					std::string idS;
            				std::cout << "Digite el id del estudiante: "<<std::endl;
					std::cin >> idE;
					std::cout << "Digite el id del semestre: "<<std::endl;
					std::cin >> idS;
					siuprueba.imprimirHorario(idS,idE);
            			}
            	break;
            	
            case 4 :
            	std::cout << "Seccion de ayuda" << std::endl;
		std::cout << "Para cargar la informacion del sistema es necesario que usted";
		std::cout << "ingrese el nombre del archivo correspondiente y al final agregarle .csv ";
		std::cout << "para no tener problemas de subir la informacion al sistema "<<std::endl;
		std::cout << "Si desea ver el horario de un alumno en un semestre especifico";
		std::cout << "Debe sabe el id correspondiente de cada uno " <<std::endl;

		std::cout << "GRACIAS POR PREFERIRNOS " <<std::endl;
		
            	break;

            case 0 :
            	std::cout << "GRACIAS POR PREFERIRNOS" << std::endl;
            	break;

         	default:
         		std::cout << "Opcion incorrenta, inserte una opcion valida" << std::endl;  
            
      }  

	} while( opcion != 0 );

	return 0;
}

// -------------------------------------------------------------------------
void menu( )
{
	std::cout << "------SISTEMA DE INFORMACION UNIVERSITARIA-----" << std::endl << std::endl;
	std::cout << "Digite una opcion.." << std::endl;
	std::cout << "1 para cargar Informacion de Asignaturas" << std::endl;
	std::cout << "2 para cargar Informacion de Estudiantes" << std::endl;
	std::cout << "3 para ver el Horario de un Estudiante" << std::endl;
	std::cout << "4 para ayuda" << std::endl;
	std::cout << "0 para salir" << std::endl;
}

