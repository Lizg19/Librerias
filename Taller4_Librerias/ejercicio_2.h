#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void ejercicio2();

void entrada(int a[], int n);
void imprimir(int a[], int n);
void dividir1(int a[], int inicial, int fin);
void fusionar1 (int a[], int pinicial, int pfinal, int medio);
int busqueda (int a[], int n, int dato);

ofstream lectura;
void ejercicio2(){

  string nombre;

  cout << "Ingrese el nombre del archivo: ";
  cin >> nombre;
  lectura.open(nombre, ios::app);
  int a[100], n, b;
  cout << "Ingresa la cantidad de elementos: ";
  cin >> n;
  entrada(a, n);
  cout << "Elementos ingresados: ";
  lectura << "Arreglo antes: ";
  imprimir(a, n);
  dividir1(a, 0 , n);
  lectura << "Arreglo despues: ";
  cout << "Elementos ordenados: ";
  imprimir(a, n);
  cout << "Ingrese el elemento a buscar: ";
  cin >> b;
  if(busqueda (a, n, b) == -1){
        cout << "Elemento no encontrado";
        lectura << "Elemento no encontrado";
    }
    else{
        cout << "Elemento encontrado en la posicion: " << busqueda (a, n, b);
        lectura << "Elemento encontrado en la posicion: " << busqueda (a, n, b);
    }

}
void entrada(int a[], int n){
  for (int i = 0; i < n; i++){
    cout << "Ingrese el elemento al vector:";
    cin >> a[i];
  }
}

void imprimir(int a[], int n){
  for (int i = 0; i < n; i++){
    cout << " " << a[i];
    lectura <<  " " << a[i];
  }
  cout << endl;
  lectura << endl;
}

void dividir1(int a[], int inicial, int final)
{

    int mitad;

    if (inicial<final)
    {
        mitad=(inicial+final)/2;

        dividir(a,inicial,mitad);

        dividir(a,mitad+1,final);

        fusionar1(a,inicial,final,mitad);
    }

}

void fusionar1(int a[], int pinicial, int pfinal, int medio)
{
    int i, j, k, temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;

	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}
}


int busqueda (int a[], int n, int dato)
{
  for (int i=0; i <= n; i++)
  {
    if (a[i] == dato){
    return i+1;
    }
  }
  return -1;
}
