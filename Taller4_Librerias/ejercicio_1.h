#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void ejercicio1();
void dividir(int a[], int inicial, int final);
void fusionar(int a[], int pinicial, int pfinal, int medio);

void ejercicio1(){
  ofstream archivo;
    archivo.open("ejercio1.txt");
    int A[100], n;
    cout<<"Ingresa la cantidad de elementos:";
    cin>>n;

    archivo << "Arreglo original: " ;
    srand(time(0));

    int mayor=0, menor,i;

    for (int i=0; i<n;i++)
    {
        //LLENAR ELEMENTOS AL ARREGLO EN UN INTERVALO DE 1-20
        A[i]=rand()%(100);
        if (mayor<A[i]){
          mayor=A[i];
        }
    }
    menor=mayor;

    for (int i=0; i<n;i++)
    {
          if (menor<A[i])
          {
            menor=A[i];
          }
    }
    cout << "El mayor es: "<< mayor << endl;
    cout << "El menor es: "<< A[i] << endl;

    for (int i=0; i<n;i++)
    {

        cout<<"|"<<A[i]<<"|";
        archivo << "|" << A[i] << "|";
    }

    dividir(A,0,n);

    cout<<endl;
    archivo <<"\nArreglo modificado: ";
    for (int i=0; i<n;i++)
    {

        cout <<"|"<<A[i]<<"|";
        archivo <<"|" << A[i] << "|";
    }
    archivo << "\nEl mayor es: "<< mayor << endl;
    archivo << "El menor es: "<< A[i] << endl;
    archivo.close();
}

void dividir(int a[], int inicial, int final)
{

    int mitad;

    if (inicial<final)
    {
        mitad=(inicial+final)/2;

        dividir(a,inicial,mitad);

        dividir(a,mitad+1,final);

        fusionar(a,inicial,final,mitad);
    }

}

void fusionar(int a[], int pinicial, int pfinal, int medio)
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
