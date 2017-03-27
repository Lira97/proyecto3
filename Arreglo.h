#ifndef ARREGLO_H
#define ARREGLO_H
#include <iostream> 
#include <fstream> 
#include <cstdlib>
#include <string> 
using namespace std; 
class Arreglo
{	
	private:
		int *arreglo;//se crea la variable arreglo con un puntera para que se pueda usar en todas la funciones  
		int tamano;//se crea la variable para el tamaño 
	public:
		Arreglo();
		void lecturaDatos(string archivo);//instancia la función lectura de datos 
		int busquedaSecuencial(int K);//instancia la función busquedaSecunecial  
		int busquedaBinaria(int inicio, int fin, int K);//instancia la funcion busquedaBinaria 
};
#endif

Arreglo::Arreglo()
{
	tamano=0; 
}
void Arreglo::lecturaDatos(string archivo)//recuerde que el string debe de ser con el nombre del archivo como "archivo.txt"
{
		int i = 0;//se declara la variable i y se iguala a cero 0
		fstream datos;//se instancia el archivo 
		datos.open(archivo); //se abre el archivo 
		string line; //se crea la variable línea  
		getline(datos,line);//se va a leer la primera línea del archivo la cual va a ser el tamaño del arreglo   
		tamano = stoi(line); //a continuación de leer el primer elemento y se convierte a un int 
		arreglo = new int[tamano];//creas un arreglo en forma de un puntero para que se pueda usar en otras funciones  
		
		while (!datos.eof())//si detecta el fin del archivo
		{
			datos.ignore(0,'\n'); //ignora la primera línea del archivo 
			getline (datos, line, '\n'); //toma la línea que se encuentra debajo de la otra 
			arreglo[i] = atoi (line.c_str());//la primera posición del arreglo se iguala a la trasformación del string a un numero 
			i++;//contador  
							
							
		}
		
		datos.close();//se cierra el archivo 
}

int Arreglo::busquedaSecuencial(int K)
{
	int respuesta, i;//se crea la variable i y respuesta 
	respuesta = -1; //respuesta se iguala a -1 
	for (i = 0; i < tamano; i++ )//se hace el ciclo for para poder ir checando en el arreglo 
	{
		if (K == arreglo[i])//si encuentra el número que se pidió entonces regresa la posición del arreglo en donde se encuentra el numero 
		{ 
			respuesta = i; 
			break;
		}
	}
	return respuesta; //regresa la respuesta con la posición del arreglo 
}

int Arreglo::busquedaBinaria(int primero,int ultimo,int k)
{

	int indice=0;//se crea la variable índice la cual indica la posición en la que se encuentra el arreglo 
	if (ultimo < primero)//el caso base analiza la primera posición y la última posición que le asigno el usuario 
		{
			indice= -1;//si la última posición es menor que la primera entonces regresa un -1
		}
	else 
		{
			int medio =(primero + ultimo)/2;//se crea una variable medio la cual divide la mitad del tamaño del arreglo 
			if (k ==arreglo[medio])//analiza el valor en la posición de en medio y si es igual entonces regresa la posición del arreglo 
			{
				indice = medio;
			}
			else if (k<arreglo[medio])//si el valor que se le dio es menor a la mitad del arreglo  
			{
				indice=busquedaBinaria(primero, medio-1,k);//entonces entra a una función recursiva cambiando el valor de la ultima posición restando le uno a la mitad del arreglo 
			}
			else 
			{
				indice =busquedaBinaria(medio+1, ultimo, k);//entonces entra a una función recursiva cambiando el valor de la ultima posición sumando le un a la mitad del arreglo   
			}
				
		}
	return indice; //cuando lo encuentre regresa la variable índice con la posición del arreglo y si no lo encuentra entonces regresa un -1
}


