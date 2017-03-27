#include "arreglo.h"

int main(){
	Arreglo array;
	
	int numero, numero2;
	int inicio, fin;
	int resultado, resultado2;
	
	string nombre;
	
	cout << "\n..::APERTURA DEL ARCHIVO::.." << endl;
	cout << " - Ingresa el nombre del archivo que deseas usar (Ej. archivo.txt): ";
	cin >> nombre;
	
	array.lecturaDatos(nombre);
	cout << "\n..::BÚSQUEDA SECUENCIAL::.." << endl;
	cout << " - Ingresa un número a buscar dentro del archivo: ";
	cin >> numero;
	
	resultado = array.busquedaSecuencial(numero);
	
	if (resultado == -1){
		cout << " - El número NO se encontró dentro del archivo (" << resultado << ")" << endl;
	}
	else{
		cout << " - El número se encontró en la posición [" << resultado << "] del arreglo" << endl;
	}
	
	
	cout << "\n..::BÚSQUEDA BINARIA::.." << endl;
	cout << "*NOTA: Los números dentro del archivo deben estar ordenados de menor a mayor." << endl;
	cout << " - Ingresa un número a buscar dentro del archivo: ";
	cin >> numero2;
	
	cout << " - Ingresa la posición inicial de la búsqueda: ";
	cin >> inicio;
	
	cout << " - Ingresa la posición final de la búsqueda: ";
	cin >> fin;
	
	resultado2 = array.busquedaBinaria(inicio,fin,numero2);
	
	if (resultado2 == -1){
		cout << " - El número NO se encontró dentro del archivo (" << resultado2 << ")" << endl;
	}
	
	else{
		cout << " - El número se encontró en la posición [" << resultado2 << "] del arreglo" << endl;
	}
	
	return 0;
}