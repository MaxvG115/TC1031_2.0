/*===============================*
<Autores>
+Vicente Viera Guízar, ID: A01639784
+Maximiliano Villegas Garcia. ID: A01635825
+Emma Gabriela Alfaro De la Rocha. ID: A01740229
</Autores>
=================================*
*/

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

struct record{
    public:
        string date;
        string IPqrt1;
        string IPqrt2; 
        string IPqrt3; 
        string IPqrt4;
        string port;
        string status;

        //funcion para comparar dos fechas
        bool operator<=(record& a){
            if(stoi(this->IPqrt1)<stoi(a.IPqrt1)){
                return true;
            }else if(stoi(this->IPqrt1)==stoi(a.IPqrt1)){
                if(stoi(this->IPqrt2)<stoi(a.IPqrt2)){
                    return true;
                }else if(stoi(this->IPqrt2)==stoi(a.IPqrt2)){
                    if(stoi(this->IPqrt3)<stoi(a.IPqrt3)){
                        return true;
                    }else if(stoi(this->IPqrt3)==stoi(a.IPqrt3)){
                        if(stoi(this->IPqrt4)<stoi(a.IPqrt4)){
                            return true;
                        }else if(stoi(this->IPqrt4)==stoi(a.IPqrt4)){
                            if(stoi(this->port)<=stoi(a.port)){
                                return true;
                            }
                        }
                    }
                }
            }
          return 0;
        }

        bool operator==(record& a){
            if(this->IPqrt1==a.IPqrt1 && this->IPqrt2==a.IPqrt2 && this->IPqrt3==a.IPqrt3 && this->IPqrt4==a.IPqrt4){
                return true;
            }else{
                return false;
            }
        }

        record(){
            this->date="";
            this->IPqrt1="";
            this->IPqrt2="";
            this->IPqrt3="";
            this->IPqrt4="";
        }

        //contructor para el formato de entrada
        record(string ip1,string ip2, string ip3, string ip4){
            this->date="";
            this->IPqrt1=ip1;
            this->IPqrt2=ip2;
            this->IPqrt3=ip3;
            this->IPqrt4=ip4;
        }
};

//funcion para leer archivo y guardar los datos en un vector
void readFile(vector<record>& Vector){
    record line;
    string aux;
    ifstream file;//objeto para leer archivo
    file.open("bitacora.txt");

    if(file.fail()){
        exit(0);
    }else{
        //ciclo para identificar el significado de los datos de cada registro
        while (!file.eof()){
            for(int i=0;i<3;i++){
                 getline(file, aux,' ');
                    line.date+=aux+' ';
            }
            getline(file, line.IPqrt1, '.');
            getline(file, line.IPqrt2, '.');
            getline(file, line.IPqrt3, '.');
            getline(file, line.IPqrt4, ':');
            getline(file, line.port, ' ');
            getline(file, line.status);

            //line.month=mon2num(line.month);
            Vector.push_back(line);
            line.date="";
        }
    }
    file.close();
}

//funcion para guardar los datos en una lista
void copyV2L(list<record>& li,vector<record>& vec){
    for(int i=0;i<vec.size();i++){
        li.push_back(vec[i]);
    }
}

//funcion para imprimir el documento ordenado completo
void createFile(list<record>& li){
    ofstream archivoResultados("bitacoraOrdenada-Eq#6.txt");
    list<record>::iterator it;

    if (archivoResultados.fail()){
        exit(0);
    }
    for (it = li.begin(); it != li.end(); it++){
        archivoResultados << it->date << " ";
        archivoResultados << it->IPqrt1 << ".";
        archivoResultados << it->IPqrt2 << ".";
        archivoResultados << it->IPqrt3 << ".";
        archivoResultados << it->IPqrt4 << ":";
        archivoResultados << it->port << " ";
        archivoResultados << it->status << endl;
    }
    archivoResultados.close();
}

//funcion de intercambio de variables
void swap(record *a, record *b) {
  record t = *a;
  *a = *b;
  *b = t;
}

//hacemos la particion de quicksort
int partition(vector<record>& v, int low, int high) {
  record pivot = v[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (v[j] <= pivot) {
      i++; 
      swap(&v[i], &v[j]);
    }
  }
  
  swap(&v[i + 1], &v[high]);
  return (i + 1);
}

//ordenamos el vector con quick sort
void quickSort(vector<record>& v, int low, int high) {
  if(low < high){
    int p = partition(v, low, high);
    quickSort(v, low, p - 1);
    quickSort(v, p + 1, high);
  }
}

//busqueda lineal para la lista
list<record>::iterator LinealSearchLi(list<record>& li, record& rec){
    list<record>::iterator it=li.begin();

    for(int i=0;i<li.size();i++){
        if(rec == *it){
            return it;
        }else{
            it++;
        }
    }
}

//funcion que imprima en un rango
void printR(list<record>::iterator ittop, list<record>::iterator itbottom){
    while(!(*ittop==*itbottom)){
        cout<<ittop->date<<" "<<ittop->IPqrt1<<"."<<ittop->IPqrt2<<"."<<ittop->IPqrt3<<"."<<ittop->IPqrt4<<":"<<ittop->port<<" "<<ittop->status<<endl;
        ittop++;
    }
    cout<<itbottom->date<<" "<<itbottom->IPqrt1<<"."<<itbottom->IPqrt2<<"."<<itbottom->IPqrt3<<"."<<itbottom->IPqrt4<<":"<<itbottom->port<<" "<<itbottom->status<<endl;
}



int main(){
    //creamos variables iniciales
    vector<record>* vec= new vector<record>();
    list<record> li;
    list<record>::iterator it=li.begin();
    list<record>::iterator it2=li.begin();


    readFile(*vec);
    //por alguna razon guarda los datos desde una posicion despues del prinipio del begin. para acceder al primer elemento es desde it++
    quickSort(*vec, 0, vec->size()-1);
    copyV2L(li,*vec);


    record r("1","47","156","72");
    record r2("3","68","452","75");
    it=LinealSearchLi(li,r);
    it2=LinealSearchLi(li,r2);

    printR(it,it2);



    

    createFile(li);
    return 0;
}
