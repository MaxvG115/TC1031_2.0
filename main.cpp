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

int main(){
    //creamos variables iniciales
    vector<record>* vec= new vector<record>();
    list<int> li;

    readFile(*vec);
    cout<<vec->at(0).IPqrt1<<vec->at(0).IPqrt2<<vec->at(0).IPqrt3<<vec->at(0).IPqrt4<<vec->at(0).port;
    return 0;
}