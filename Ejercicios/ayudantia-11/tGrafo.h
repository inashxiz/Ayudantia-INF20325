using tVertice = int;

class tGrafo {
  public:
    tGrafo(int n); // inicializa grafo para n vertices
    int nVertex(); // retorna cantidad de vertices
    int nEdges();  // retorna cantidad de arcos
    tVertice
    first(tVertice v); // retorna vecino de v con el menor identificador
    tVertice
    next(tVertice v,
         tVertice w); // retorna vecino de v con mayor identificador que w
                      // si no existe, retorna la cantidad total de vértices
    void setEdge(tVertice v1, tVertice v2,
                 int p); // agrega arco entre v1 y v2 con peso p
                         // v1 y v2 DEBEN existir en el grafo
    void deleteEdge(tVertice v1,
                    tVertice v2); // elimina arco existente entre v1 y v2
    bool isEdge(tVertice v1, tVertice v2); // retorna true si existe arco entre
                                           // v1 y v2 false en otro caso
    int weight(tVertice v1, tVertice v2); // retorna peso del arco entre v1 y v2
                                          // retorna 0 si dicho arco no existe
    int getMark(tVertice v);              // obtiene marca asignado al vertice v
    int setMark(tVertice v, int marca);   // asigna una marca al vertice v
};
