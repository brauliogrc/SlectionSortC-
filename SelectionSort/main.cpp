#include <iostream>
#include <locale.h>
#include <vector>
#include <string.h>

using namespace std;

class SortAlgorithms {
    public:
        SortAlgorithms();
        void SelectionSort(std::vector<double> &items);
        void showIterarion(std::vector<double>, int);
};

/** Constructor */
SortAlgorithms::SortAlgorithms() {

}

void SortAlgorithms::SelectionSort(std::vector<double> &items){
    int minimum;
    double swapping;
    int comparaciones = 0;
    for(int i = 0; i < items.size(); i++){
        minimum = i;
        for(int j = minimum + 1; j < items.size(); j++){
            if(items[j] < items[minimum]) {
                minimum = j;
            }
        }
        swapping = items[i];
        items[i] = items[minimum];
        items[minimum] = swapping;
        comparaciones ++;
        showIterarion(items, i+1);
    }
    cout << "Comparaciones: " << comparaciones << endl;
}

void SortAlgorithms::showIterarion(std::vector<double> items, int noI){
    if(noI == 0) cout << "\nOrden inicial: ";
    else cout << "\nIteración " << noI << ": ";

    /** Muestra en pantalla el oden de los valores despes de cada recorrido */
    for( int i = 0; i < items.size(); i++ ){
        if( i == items.size()-1 ){
                cout << items[i] << ", " << endl;
        }else{
            cout << items[i] << ", ";
        }
    }
}

int main()
{
    // Admición de caracteres especiales
    setlocale(LC_CTYPE, "Spanish");
    cout << "Selection sort" << endl;
    cout << "García Martínez Braulio Israel 220331615" << endl;

    SortAlgorithms sortA = SortAlgorithms();

    /** Definición de la longitud del vector */
    int noe;
    do{
        cout << "Ingrese la cantidad de datos que desea ordenar: ";
        cin >> noe;

        if( (noe < 2) || (noe >100) ){
            cout << "La cantidad mínima de elementos a ordenar son 2 y la cantidad máxima son 100" << endl;
        }
    }while( (noe < 2) || (noe > 100) );

    /** Ingreso de datos al vector */
    std::vector<double> items(noe);
    double value;
    for( int i = 0; i < items.size(); i++ ){
        cout << "Ingrese el valor " << i+1 << ": ";
        cin >> value;
        items[i] = value;
    }

    sortA.SelectionSort(items);
    return 0;
}
