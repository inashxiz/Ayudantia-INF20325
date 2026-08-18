#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Videojuego{
    string nombre;
    int cantidad = 0;
};

struct Consola{
    int numVideojuegos;
    int capacidad = 10;
    Videojuego *videojuegos = new Videojuego[capacidad];
};

class Inventario{
    private:
    Consola PlayStation, Xbox, Nintendo;
    void aumentarCapacidad(Videojuego *&v, int &cap);

    // Método Auxiliar - OPCIONAl
    void referenciarConsola(Consola *&c, string cons);
  public:
    Inventario();
    ~Inventario();
    void agregar(string nom, string cons, int cant);
    void actualizar(string nom, string cons, int cant);
    void consultar(string nom, string cons);
    void stockConsola(string cons);
    void guardarInventario(string out_name);

    // Método Auxiliar - OPCIONAL
    bool existeEnInventario(string nom, string cons);
};

Inventario::Inventario(){
    PlayStation.numVideojuegos = 0;
    Xbox.numVideojuegos = 0;
    Nintendo.numVideojuegos = 0;
}

Inventario::~Inventario(){
    delete[] PlayStation.videojuegos;
    delete[] Xbox.videojuegos;
    delete[] Nintendo.videojuegos;
}

void Inventario::aumentarCapacidad(Videojuego *&v, int &cap){
    Videojuego *new_v  = new Videojuego[cap*2];
    for(int i = 0; i < cap; i++){
        new_v[i] = v[i];
    }

    delete[] v;
    v = new_v;
    cap *= 2;
}

void Inventario::referenciarConsola(Consola *&c, string cons){
    if(cons == "PlayStation"){
        c = &PlayStation;
    } else if(cons == "Xbox"){
        c = &Xbox;
    } else {
        c = &Nintendo;
    }   
}

void Inventario::agregar(string nom, string cons, int cant){
    Consola *c = nullptr;
    referenciarConsola(c, cons);
    if(c->numVideojuegos >= c->capacidad){
        aumentarCapacidad(c->videojuegos, c->capacidad);
    }

    c->videojuegos[c->numVideojuegos].nombre = nom;
    c->videojuegos[c->numVideojuegos].cantidad = cant;
    c->numVideojuegos++;
}

void Inventario::actualizar(string nom, string cons, int cant){
    Consola *c = nullptr;
    referenciarConsola(c, cons);
    for(int i = 0; i < c->numVideojuegos; i++){
        if(c->videojuegos[i].nombre == nom){
            c->videojuegos[i].cantidad = max(0, c->videojuegos[i].cantidad + cant);
        }
    }
}

void Inventario::consultar(string nom, string cons){
    Consola *c = nullptr;
    referenciarConsola(c, cons);

    for(int i = 0; i < c->numVideojuegos; i++){
        if(c->videojuegos[i].nombre == nom){
            cout << "Copias de " << c->videojuegos[i].nombre  <<" (" << cons << "): " << c->videojuegos[i].cantidad << endl;
        }
    }
}

void Inventario::stockConsola(string cons){
    Consola *c = nullptr;
    referenciarConsola(c, cons);

    int stock = 0;
    for(int i = 0; i < c->numVideojuegos; i++){
        stock += c->videojuegos[i].cantidad;
    }

    cout << "Stock de " << cons << ": " << stock << endl; 
}

void Inventario::guardarInventario(string out_name){
    ofstream output;
    output.open(out_name);

    output << "PlayStation:\n";
    for(int i = 0; i < PlayStation.numVideojuegos; i++){
        output << "    - " << PlayStation.videojuegos[i].nombre << ": " << PlayStation.videojuegos[i].cantidad << "\n";
    }

    output << "\n";
    output << "Xbox:\n";
    for(int i = 0; i < Xbox.numVideojuegos; i++){
        output << "    - " << Xbox.videojuegos[i].nombre << ": " << Xbox.videojuegos[i].cantidad << "\n";
    }

    output << "\n";
    output << "Nintendo:\n";
    for(int i = 0; i < Nintendo.numVideojuegos; i++){
        output << "    - " << Nintendo.videojuegos[i].nombre << ": " << Nintendo.videojuegos[i].cantidad << "\n";
    }

    output.close();
}

bool Inventario::existeEnInventario(string nom, string cons){
    Consola *c = nullptr;
        referenciarConsola(c, cons);

        for(int i = 0; i < c->numVideojuegos; i++){
            if(c->videojuegos[i].nombre == nom){
                return true;
            }
        }

        return false;
}

int main(){
    ifstream file;
    file.open("resumen.txt");

    int n;
    Inventario inv;
    
    file >> n;
    file.ignore();
    
    while(n--){
        string videojuego, consola;
        int cantidad;
        string linea;
        getline(file, linea);

        int posGuion = linea.find('-');
        int posPuntoComa = linea.find(';');

        videojuego = linea.substr(0, posGuion);
        consola = linea.substr(posGuion+1, posPuntoComa-(posGuion+1));
        cantidad = stoi(linea.substr(posPuntoComa+1));

        if(inv.existeEnInventario(videojuego, consola)){
            inv.actualizar(videojuego, consola, cantidad);
        } else {
            inv.agregar(videojuego, consola, cantidad);
        }
    }

    inv.consultar("Minecraft", "Xbox");
    inv.stockConsola("Nintendo");
    inv.guardarInventario("output.txt");
    file.close();
}