#include <iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
#include <algorithm>

template <class T>
void cambia(int a, int b, vector <T> &vect){ //pos a, pos b, y vector
    T aux;
    aux = vect[a];
    vect[a] = vect [b];
    vect[b] = aux;  
}

void imprimirPos(int &pos){
    if (pos != -1){
        cout << "El elemento buscado esta en la posicion " << pos <<endl;
    }else{
        cout << "El elemento buscado no existe dentro del arreglo " << pos <<endl;
    }
    pos = 0;
}

template<class T>
void imprime(int cant, vector <T> &vect){
    cout <<"\n";
    for (auto i = vect.cbegin(); i != vect.cend(); i++){
        cout << *i << " ";
    }
    cout <<endl;
}

void imprimeDatos(int c, int i, double t){
    cout<<"Comparaciones: " << c 
        <<"     Intercambios: " << i 
        <<"     Tiempo de Ejecucion: " << t << " segundos" 
        <<endl;
}

template<class T>
void intercambio (int cant, vector<T> &vect){
    unsigned t0, t1;
    t0 = clock();
    int compas = 0 , inter = 0;
    for (int j=0; j<cant-1; j++){
        for(int i =j+1; i<cant; i++){
            compas++;//contador de Comparaciones realizadas en la función
            if (vect[j] > vect[i]){
                cambia(j, i, vect);
                //imprime(cant, vect);
                inter ++; // contador de Intercambios realizados en la función
            }
        }
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    imprimeDatos(compas, inter, time);
}

template<class T>
void Inserccion(int cant, vector<T> &vect){
    unsigned t0, t1;
    t0 = clock();
    int compas = 0 , inter = 0;
    for (int i = 1; i <cant; i++){
        compas++;
        if (vect[i] < vect[i-1]){ //comparar con el elemento anterior de al lado
            cambia(i, i-1, vect);
            //imprime(cant, vect);
            inter ++;
            //imprime(cant, vect);
            if (i!=1){ //en la primera instancia no se puede comparar con elementos anteriores
                for (int j = i-1; j>0; j--){
                    compas++;
                    if (vect[j] < vect[j-1]){ //comparacion con elementos anteriores
                        cambia(j, (j-1), vect);
                        //imprime(cant, vect);
                        inter++;
                        //imprime(cant, vect);
                    }
                }
            }
        }
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    imprimeDatos(compas, inter, time);
}


template<class T>
void merge(vector<T> &vect, int inicio, int mitad, int fin){
    unsigned t0, t1;
    t0 = clock(); 
    vector<T> Izq; //lista de la izquierda
    vector<T> Der; //lista de la derecha
    int pos, cant1, cant2, i, j; //variables auxiliares
    pos =inicio; //posicion del arreglo original al que se va a arreglar
    cant1 = mitad-inicio + 1; //cant de elementos lista izq
    cant2 = fin - mitad; //cant de elementos lista der
    for (i=0; i<cant1; i++){
        Izq.push_back(vect[inicio+i]);//actualizar la lista Izq
    }

    for (j=0; j<cant2; j++){
        Der.push_back(vect[mitad+1+j]);//Actualizar la lista Der
    }

    i =0;
    j = 0;
    while( (i<cant1) && (j<cant2)){ //mientras el contador sea menor a la cantidad de elementos de Izq y j menor a cant2
        if(Izq[i] <= Der[j] ){
            vect[pos] = Izq[i];
            i++;
        }else{
            vect[pos] = Der[j];
            j++;
        }
        pos++;
    }
    //ayudan a vaciar los elementos pendientes despues de que se acabaron los elementos para comparar
    while(i<cant1){
        vect[pos] = Izq[i];
        i++;
        pos++;
    }
    while(j<cant2){
        vect[pos] = Der[j];
        j++;
        pos++;
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    cout<<"El tiempo de ejecucion: " << time <<endl;
}

template<class T>
void mergeSort(vector<T> &vect, int beg, int fin){
    unsigned t0, t1;
    t0 = clock(); 
    if (beg < fin){ // beg = indice de izquierda  fin = indice de derecha
        int mitad = (beg+fin)/2; //medio para separar en 2 la lista (izquierda y derecha) Promedio entre inicio y fin
        //Para encontrar las primeras mitades
        mergeSort(vect, beg, mitad);//primera lista: de inicio a medio
        mergeSort (vect, mitad+1, fin); // segunda lista: de medio hasta fin
        merge (vect, beg, mitad, fin); // metodo para unir ambas listas: beg = 0, mitad = 0, fin = 1
    }
}

template<class T>
void quickSort(vector<T> &vect, int cant){
    unsigned t0, t1;
    t0 = clock(); 
    
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
   // imprimeDatos(compas, inter, time);
}

template<class T>
void burbuja (int cant, vector<T> &vect){
    unsigned t0, t1;
    t0 = clock();
    int compas = 0 , inter = 0;
    for(int i = cant; i>0; i--){
        for(int ele = 1; ele<i; ele++){
            compas++;//contador de Comparaciones realizadas en la función
            if (vect [ele] < vect [ele-1] ){
                cambia(ele, (ele-1), vect);
                //imprime(cant, vect);
                inter ++;// contador de Intercambios realizados en la función
            }
        }
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    imprimeDatos(compas, inter, time);
}


template<class T>
void seleccionDirecta(int cant, vector<T> &vect){
    unsigned t0, t1;
    t0 = clock();
    int compas = 0 , inter = 0; 
    int min;
    for (int i=0; i<cant; i++){
        min = i;
        for (int j =i+1 ; j<cant; j++){ // for para encontrar la posición del minimo elemento de todo el vector 
            compas++;//contador de Comparaciones realizadas en la función
            if ( vect[min] > vect[j]){
                min = j;
            }
        }
        cambia(min, i, vect);
        //imprime(cant, vect);
        inter++;// contador de Intercambios realizados en la función
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    imprimeDatos(compas, inter, time);
}

template<class T>
int busqIter(int cant, vector<T> &vect){
    unsigned t0, t1;
    t0 = clock();
    T ele; //Elemento que digite el usuario
    cout << "Digite el elemento a buscar"<<endl;
    cin >> ele;
    int i=0;
    int pos = -2;
    bool found = false;
    while( (found == false) && (i<cant)){
        if(vect[i] == ele){
            pos = i;
            found = true;
        }
        i++;
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    cout <<"     Tiempo de Ejecucion: " << time << " segundos" <<endl;
    return pos+1;
}


template<class T>
int busqBin(int cant, vector<T> &vect){
    sort(vect.begin(), vect.end());
    unsigned t0, t1;
    t0 = clock();
    T ele; //Elemento que digite el usuario
    cout << "Digite el elemento a buscar"<<endl;
    cin >> ele;  
    bool found = false;
    int low, high, mid;
    int result = -1;
    low = 0; // El primer elemento del vector 
    high = cant-1; // El ultimo elemento del vector

    while( (found == false) && (high!=0) ){
        mid = (high + low)/2;
        
        if (ele == vect[low]){
            result = 1;
            found = true;
        }else{            
            if (ele < vect[mid]){
                high = mid -1;
            }
            else if (ele > vect[mid]){
                low = mid +1;
            }
            else{ // encontrado, el elemento coincide con el del medio
                result = mid +1;
                found = true;
            } } 
    }
    t1 = clock();
    double time = (double (t1-t0)/CLOCKS_PER_SEC);
    cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl;
    return result;
}


template<class T>
void crearVectorNum (int cant, vector<T> &vect){
    srand(time(NULL));
    for (int i=0; i <cant; i++){
        vect.push_back(rand () % 100);
    }
    cout << "Vector Registrado: ";
    imprime(cant, vect);
}

void crearVectorChar (int cant, vector<char> &vect){
    char c, c1;
    int r;
    srand(time(NULL));
    for (int i=0; i <cant; i++){
        r = rand () % 26;
        c = 'a' + r;
        vect.push_back(c);
    }
    cout << "Vector Registrado: ";
    imprime(cant, vect);
}

void crearVectorStr (int cant, vector<string> &vect){
    cout << "Digite sus elementos strings" <<endl;
    string ele;
    for (int i=0; i <cant; i++){
        cin >> ele;
        cout << "Nuevo Elemento: " << ele <<endl;
        vect.push_back(ele);
    }
    cout << "Vector Registrado: ";
    imprime(cant, vect);
}

int pideTipoDato(int &cant){
    int ans;
    ans = 0;
    cout<< "Digita la cantidad de elementos" <<endl;
    cin >> cant;

    while ((ans <1) || (ans>4) ){
        cout <<"Seleccione tipo de dato"
        << "\n 1. int"
        << "\n 2. Double"
        << "\n 3. String"
        << "\n 4. Char" 
        <<endl;
        cin >> ans;
    }
    return ans;
}

char menu(){ //Funcion que muestra el menu de acciones
    char ans;
    cout << "\n *** MENU *** " 
        << "\n a) Cambiar tipo de dato"
        << "\n b) Orden por Burbuja" 
        << "\n c) Orden por Seleccion"
        << "\n d) Orden por Intercambio" 
        << "\n e) Orden por Insercion"
        << "\n f) Búsquedas Iterativa"
        << "\n g) Busqueda Binaria"
        << "\n h) Orden por MergeSort"
        << "\n i) Orden por QuickSort"
        << "\n z) Salir"
        << endl;
    cin >> ans;
    cout << "\n" <<endl;
    return ans;
}

template<class T>
char metodoOrd(int cant,vector<T> &vect ){ //PROBAR
    bool salir = false;
    char opc;
    vector<T> vect1, vect2;
    char ans = menu();//Pedir tipo de dato
    vect2 = vect;
    while( salir == false){
        vect1 = vect;
        switch (ans){
            case 'a'://cambiar tipo de dato
                vect.clear();
                vect1.clear();
                opc = 'n';
                salir = true;
                break;
            case 'd'://Metodo Intercambio
                imprime(cant, vect); //imprimir vector original
                intercambio(cant,vect1);
                imprime (cant,vect1);
                break;
            case 'b': //Metodo burbuja
                imprime(cant, vect); //imprimir vector original
                burbuja(cant,vect1);
                imprime (cant,vect1);
                break;
            case 'c'://Metodo Seleccion Directa
                imprime(cant, vect); //imprimir vector original
                seleccionDirecta(cant, vect1);
                imprime (cant, vect1);
                break;
            case 'e'://Metodo por Inserccion
                imprime(cant, vect); //imprimir vector original
                Inserccion(cant, vect1);
                imprime (cant, vect1);
                break;
            case 'f': //Metodo de busqueda iterativa
                int pos; 
                imprime(cant, vect); //imprimir vector original
                pos = busqIter(cant, vect2);
                imprimirPos(pos);
                break;
            case 'g': //Metodo de busqueda binaria
                imprime(cant, vect); //imprimir vector original
                pos = busqBin(cant, vect);
                imprimirPos(pos);
                break;
            case 'h'://Método Merge-Sort
                imprime(cant, vect); //imprimir vector original
                mergeSort(vect1, 0, (cant-1)); 
                imprime(cant, vect1);
                break;
            case 'i':
                imprime(cant, vect); //imprimir vector original
                //quickSort(cant, vect1);//Método Quick-Sort
                imprime(cant, vect1);
                break;
            case 'z':
                salir =true;
                opc = 's';
                break;
            default: //En el caso de que digite mal
                cout << "Digita nuevamente una opcion de respuesta" <<endl;
                break;
        }
        vect2 = vect1;
        vect1.clear();
        if(salir == false){
            ans = menu();
        }
    }
    return opc;
}

int main(){
    //Declarar los vectores
    srand(time(NULL));// Para evitar numeros repetidos
    vector <int> vectI;
    vector <double> vectD;
    vector <string> vectS;
    vector <char> vectC;

    int n; //Variable Cantidad de elementos del vector
    char ans; //Variable de respuesta
    ans = pideTipoDato(n); //Llamar a función para cambiar de dato
    char exit = 'n'; // variable para salir

    while(exit == 'n'){
        switch(ans){
            case 1: // Tipo: Int
                crearVectorNum(n, vectI);
                exit = metodoOrd(n, vectI);
            break;
            case 2:// Tipo: Double
                crearVectorNum(n, vectD);
                exit = metodoOrd(n, vectD);
            break;
            case 3:// Tipo: String
                crearVectorStr(n, vectS);
                exit = metodoOrd(n, vectS);
            break;
            case 4:// Tipo: Char
                crearVectorChar(n, vectC);
                exit = metodoOrd(n, vectC);
            break;
        }
        if(exit == 'n'){
            ans = pideTipoDato(n);
        }
    }
    cout <<"programa terminado con Exito" <<endl;
    return 0;
}
