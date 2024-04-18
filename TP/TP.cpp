#include <iostream>
#include <fstream>

using namespace std;

int main(){

    int dim_clientes{8};
    int dim_prod{5};
    int clientes, prod;
    float cant, kilm;
    float distancia[dim_clientes][dim_prod]{};
    float peso[dim_clientes][dim_prod]{};
    float vec_kilm_fmay[dim_prod];
    int entregas[dim_clientes]{};
    int prodsxcliente[dim_clientes]{};
    string nom_clientes[dim_clientes];
    string productos[dim_prod];
    int vec_aux[dim_prod];
    int imin, temp;
    int fmay{0};

    ifstream registros;
    registros.open("Datos.txt");
    if (!registros){
        cout << "Error al abrir el archivo";
        return 1;
    }

    while (registros >> clientes >> prod >> cant >> kilm){
        distancia[clientes][prod] += kilm;
        peso[clientes][prod] += cant;
        entregas[prod]++;
    }
    registros.close();

    ifstream nombres;
    nombres.open("Nombres.txt");
    if (!nombres){
        cout << "Error al abrir el archivo";
        return 1;
    }

   for (int i = 0; i < dim_clientes; i++){
        nombres >> nom_clientes[i];
   }

   for (int i = 0; i < dim_prod; i++){
        nombres >> productos[i];
   }
   nombres.close();

 //Punto 1

    cout << "========================Punto 1========================" << endl;

    for (int i = 0; i < dim_clientes; i++){
        for (int j = 0; j < dim_prod; j++){
            if (peso[i][j] > 13000){
                prodsxcliente[i]++;
                cout << nom_clientes[i] << " transporto mas de 13000 Kg de: " << 
                productos[j] << endl;
            }
        }
    }
      
 //Punto 2

    cout << "========================Punto 2========================" << endl;

    for (int i = 1; i < dim_clientes; i++){
        if (prodsxcliente[i] > prodsxcliente[fmay]){
            fmay = i;
        }
    }

    cout << "El clientes: " << nom_clientes[fmay] << " transporto mas cantidad de productos, estos son: " << endl;

    for (int i = 0; i < dim_prod; i++){
        vec_kilm_fmay[i] = distancia[fmay][i];
    } 

    for (int i = 0; i < dim_prod-1; i++){
        imin = i;
        for (int j = i + 1; j < dim_prod; j++)
            if (vec_kilm_fmay[j] < vec_kilm_fmay[imin])
                imin = j;       
        swap(vec_kilm_fmay[i], vec_kilm_fmay[imin]);
        swap(productos[i], productos[imin]);  
        swap(entregas[i], entregas[imin]);  
    }

    for (int i = 0; i < dim_prod; i++){
        cout << "Para el producto: " << productos[i] << " se realizaron: " <<
        vec_kilm_fmay[i] << " kilometros" << endl;
        
    }

 //Punto 3

    cout << "========================Punto 3========================" << endl;

    cout << "Para el producto: " << productos[dim_prod-1] << " se realizaron: " 
    << entregas[dim_prod-1] << " entregas" << endl;

}


    