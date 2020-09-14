#include <iostream>
#include <fstream>

void ingresarProveedor();
void ingresarProductos();

void ingresarProveedor(){
  ofstream archiv;
  string codigo,nombreP,ciudad , telefono;
  archiv.open ("produtos.txt", ios::app);
  cout << "\tDATOS DEL PROVEEDOR" << endl;
  cout << "Ingrese los siguientes datos: "<< endl;
  cout << "Codigo: ";
  cin>> codigo;
  cout << "Nombre: ";
  cin >> nombreP;
  cout << "Ciudad: ";
  cin>> ciudad;
  cout << "Telefono: ";
  cin >> telefono;

  archiv<< "***** DATOS DEL PROVEEDOR *******\n";
      archiv << "Codigo\t\tNombre\t\tCiudad\t\tTelefono\n";
      archiv <<codigo<< "\t\t"<< nombreP <<"\t"<<ciudad << "\t\t"<< telefono <<"\n";
  archiv.close();
}

void ingresarProductos(){
    ofstream archiv;
    archiv.open ("produtos.txt", ios::app);
    string nombre, estado;
    double precio[5], valor[5];
    double sumaprod, precio1;
    int cantidad[5];
    int contador=0;
    cout << "\tDATOS DEL PRODUCTO\n";
    archiv << "\n***** DATOS DEL PRODUCTO *******\n";
    archiv << "Nombre\t\tPrecio\t\tCantidad\tEstado\n";
    cout << "Nombre( * para terminar): ";
    cin >> nombre;
    while( nombre != "*"){
        cout << "Precio: " ;
        cin>> precio[contador];
        cout << "Cantidad: " ;
        cin>> cantidad [contador] ;
        cout << "estado: ";
        cin>> estado;
    valor[contador]= precio[contador]* cantidad [contador];
    sumaprod= sumaprod + cantidad [contador];
    precio1= precio1 + valor[contador];
    archiv <<nombre<< "\t\t"<< precio[contador] <<"\t\t"<< cantidad[contador] << "\t\t"<< estado <<"\n";
    cout << "Nombre: ";
    cin >> nombre;
    contador ++;
    }
    cout<< "Numero total de productos adquiridos: "<< contador << endl;
    cout << "Cantidad de prodcutos adquirido: "<<  sumaprod <<endl;
    cout << "El valor total: " <<  precio1 << endl;

    archiv<< "Numero de productos adquiridos: "<< contador << endl;
    archiv<< "Cantidad de prodcutos adquiridos: "<<  sumaprod<<endl;
    archiv<< "El valor total: " <<  precio1 << endl;
    archiv.close();
}

