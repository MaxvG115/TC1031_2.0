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

void createFile(){
    ofstream archivoResultados;
    archivoResultados.open("bitacoraOrdenada-Eq#6.txt");
    
    archivoResultados.close();
}

int main(){
    //creamos variables iniciales
    vector<record>* vec= new vector<record>();
    list<record> li;
    list<record>::iterator it=li.begin();

    readFile(*vec);
    //por alguna razon guarda los datos desde una posicion despues del prinipio del begin. para acceder al primer elemento es desde it++
    copyV2L(li,*vec);

    return 0;
}