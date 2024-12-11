struct Libro {
    int ID;
    char Título[100];
    char Autor[50];
    int Año;
    char Estado[20];
};

void registrarLibros(struct Libro libro[20], int i);
void mostrarLibros(struct Libro libro[20], int n);
void buscarLibroPorId(struct Libro libro[20], int n);
void buscarLibroPorTituloOId(struct Libro libro[20], int n);
int eliminarLibros(struct Libro libro[20], int n);
void cambiarEstado(struct Libro libro[20], int n);
