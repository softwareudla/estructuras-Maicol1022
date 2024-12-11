#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarLibros(struct Libro libro[20], int i)
{
    int len;
    int opc1;
    printf("Ingrese el ID del Libro  %d:\n", i + 1);
    scanf("%d", &libro[i].ID);
    printf("Ingrese el titulo %d del Libro:\n", i + 1);
    fflush(stdin);
    fgets(libro[i].Título, 100, stdin);
    
    len = strlen(libro[i].Título) - 1;
    libro[i].Título[len] = '\0';
    printf("Ingrese el autor del Libro %d:\n", i + 1);
    fflush(stdin);
    fgets(libro[i].Autor, 50, stdin);
    len = strlen(libro[i].Autor) - 1;
    libro[i].Autor[len] = '\0';
    printf("Ingrese el anio del Libro %d:\n", i + 1);
    scanf("%d", &libro[i].Año);
    printf("Seleccione el Estado del libro (1. Disponible, 2. Prestado): ");
    scanf("%d", &opc1);
    switch (opc1)
    {
    case 1:
        strcpy(libro[i].Estado, "Disponible");
        break;
    case 2:
        strcpy(libro[i].Estado, "Prestado");
        break;
    default:
        printf("\nNúmero incorrecto. Se asignará 'Disponible' por defecto.\n");
        strcpy(libro[i].Estado, "Disponible");
    }
}

void mostrarLibros(struct Libro libro[20], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (libro[i].ID != 0)
        {
            printf("|--------------------------------------------------------------------|\n");
            printf("|Id\t\tTitulo\t\tAutor\t\tAnio\t\tEstado|\n");
            printf("|--------------------------------------------------------------------|\n");
            printf("|%d\t\t%s\t\t%s\t\t%d\t\t%s|\n", libro[i].ID, libro[i].Título, libro[i].Autor, libro[i].Año, libro[i].Estado);
        }
    }
}

void buscarLibroPorId(struct Libro libro[20], int n)
{
    int id;
    printf("Ingrese el ID del libro a buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (libro[i].ID == id)
        {
            printf("\nLibro encontrado:\n");
            printf("|--------------------------------------------------------------------|\n");
            printf("|Id\t\tTitulo\t\tAutor\t\tAnio\t\tEstado|\n");
            printf("|--------------------------------------------------------------------|\n");
            printf("|%d\t\t%s\t\t%s\t\t%d\t\t%s|\n", libro[i].ID, libro[i].Título, libro[i].Autor, libro[i].Año, libro[i].Estado);
            return;
        }
    }
    printf("\nNo se encontró un libro con el ID %d.\n", id);
}

void buscarLibroPorTituloOId(struct Libro libro[20], int n)
{
    int subopc;
    printf("\nSeleccione como desea buscar el libro:\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por Titulo\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &subopc);

    switch (subopc)
    {
    case 1:
    {
        buscarLibroPorId(libro, n);
        break;
    }
    case 2:
    {
        char titulo[100];
        printf("Ingrese el titulo del libro a buscar: ");
        fflush(stdin);
        fgets(titulo, 100, stdin);
        titulo[strcspn(titulo, "\n")] = '\0';

        for (int i = 0; i < n; i++)
        {
            if (strcmp(libro[i].Título, titulo) == 0)
            {
                printf("\nLibro encontrado:\n");
                printf("|--------------------------------------------------------------------|\n");
                printf("|Id\t\tTitulo\t\tAutor\t\tAnio\t\tEstado|\n");
                printf("|--------------------------------------------------------------------|\n");
                printf("|%d\t\t%s\t\t%s\t\t%d\t\t%s|\n", libro[i].ID, libro[i].Título, libro[i].Autor, libro[i].Año, libro[i].Estado);
                return;
            }
        }
        printf("\nNo se encontro un libro con el titulo \"%s\".\n", titulo);
        break;
    }
    default:
        printf("Opcion invalida. Volviendo al menu principal.\n");
    }
}
void cambiarEstado(struct Libro libro[20], int n) {
    mostrarLibros(libro, n);
    int id, opc;
    printf("Ingrese el ID del Libro que desea cambiar: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (libro[i].ID == id) {
            printf("Seleccione el nuevo Estado del libro (1. Disponible, 2. Prestado): ");
            scanf("%d", &opc);
            switch (opc) {
                case 1:
                    strcpy(libro[i].Estado, "Disponible");
                    printf("Estado actualizado a 'Disponible'.\n");
                    break;
                case 2:
                    strcpy(libro[i].Estado, "Prestado");
                    printf("Estado actualizado a 'Prestado'.\n");
                    break;
                default:
                    printf("Opción inválida. El estado no se ha cambiado.\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontró un libro con el ID %d.\n", id);
    }
}

int eliminarLibros(struct Libro libro[20], int n)
{
    mostrarLibros(libro, n);
    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (libro[i].ID == id)
        {
            for (int j = i; j < n - 1; j++)
            {
                libro[j] = libro[j + 1];
            }
            printf("Libro con ID %d eliminado.\n", id);
            return n - 1;
        }
    }
    printf("No se encontró un libro con el ID %d.\n", id);
    return n;
}
