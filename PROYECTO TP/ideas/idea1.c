

         /***

Se desea guardar los datos de hasta 10 choferes.
De cada cliente se sabe nombre,  apellido , CUIT y nro de chasis.
Imprimir búsqueda por nombre.
Imprimir búsqueda por CUIT.
imprimir busuqeda por chasis
Se debe poder buscar un chofer por nombre y apellido,
y poder cambiar cualquiera de sus datos personales.

/**/
    //*

//FUNCIONA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
  char nombre[20];
  char apellido[20];
  char CUIT[12];
  char nro_chasis[23];
  struct nodo *psig;
};

void liberarLista(struct nodo **pinicial);
void mostrarLista(struct nodo *pinicial);


void enlazarNodoAlFinal(struct nodo *pinicial, struct nodo *pnodo);
void agregarNodo(struct nodo **pinicial);

//opcion 1
void agregarNodoAlPrincipio(struct nodo **pinicial);

void buscar_Nombre(struct nodo **p_lista, char *nombre);
void buscar_chasis(struct nodo **p_lista, char *chasis);
void buscar_Apellido(struct nodo **p_lista, char *apellido);
void cambiar_datos(struct nodo **p_lista,char *dato);
void leer_archivo(struct nodo **pinicial);

//
  int main() {

    struct nodo *pINI = 0;

    int opcion = 0;

    while (opcion != 10){
        printf("\nMENU\n");
        printf("1: Ingresar datos\n");
        printf("2: Buscar por nombre\n");
        printf("3: Buscar por apellido\n");
        printf("4: Buscar por NRO CHASIS\n");
        printf("5: Cambiar datos\n");
        printf("6: Mostrar lista\n");
        printf("7: Liberar lista\n");
        printf("8: leer los datos del archivo\n");
        printf("9: agregar archivo al nodo\n");
        printf("10: Terminar ejecucion\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            agregarNodoAlPrincipio(&pINI);
            break;
        case 2: {
            char nombreABuscar[20];
            printf("Ingrese el nombre a buscar: ");
            scanf("%s", nombreABuscar);
            buscarNombre(&pINI, nombreABuscar);
            break;
            }
        case 3: {
            char apellidoABuscar[20];
            printf("Ingrese el apellido a buscar: ");
            scanf("%s", apellidoABuscar);
            buscarApellido(&pINI, apellidoABuscar);
            break;
              }
        case 4: {
            char chasisABuscar[12];
            printf("Ingrese el Chasisa buscar: ");
            scanf("%s", chasisABuscar);
            buscar_chasis(&pINI, chasisABuscar);
            break;
             }
        case 5: {
            char datoABuscar[12];
            printf("Ingrese el Dato a buscar: ");
            scanf("%s", datoABuscar);
            cambiar_datos(&pINI, datoABuscar);
            break;
               }
        case 6:
            mostrarLista(pINI);
            break;
        case 7:
            liberarLista(&pINI);
            break;
        case 8:
            leer_archivo(&pINI);
            break;
        case 9:agregarNodo(&pINI);

            break;
        case 10:
            printf("Cerrando programa\n");

            break;
        default:
            printf("Opcion invalida\n");
        }
    }

    return 0;
}

//--------------------
void leer_archivo(struct nodo **pinicial)
 {
   struct nodo *aux =pinicial;

   aux = (struct nodo *)malloc(sizeof(struct nodo));

   FILE*ptrCf;


   if ( ( ptrCf = fopen( "empleadoSANPEDRO.dat", "r" ) ) == NULL ) {
      printf( "El archivo no pudo abrirse\n" );
   }
   else {
      printf( "%-10s%-13s%-13s%-13s\n", "Nombre","Apellido", "CUIT", "CHASIS" );
    fscanf( ptrCf, "%s %s %s %s", aux->nombre,aux->apellido,aux->CUIT,aux->nro_chasis);


      while ( !feof( ptrCf ) ) {
         printf("%-10s%-13s%-13s%-13s\n", aux->nombre,aux->apellido,aux->CUIT,aux->nro_chasis);
         fscanf( ptrCf, "%s %s %s %s", aux->nombre,aux->apellido,aux->CUIT,aux->nro_chasis );

      }
      fclose( ptrCf );
   }

 }

//-----------------------


//agregar nodo lleva 2 punteros
void agregarNodo(struct nodo ** pinicial)
{

    struct nodo * paux=(*pinicial);

    if((*pinicial)==0)
    {//lista vacia
     //agregar Primer Nodo
       printf("esta vacia");

    }else
    {//lista no vacia.
     //agrego nodos al enlazarNodoAlFinal
        while((paux)->psig  !=0)
        {
        (paux)=(paux)->psig;
        }

        (paux)->psig=(struct nodo *) malloc(sizeof(struct nodo));//creo un nodo
        (paux)=(paux)->psig;
        (paux)->psig=0;//hago 0 al psig del nodo creado


    }

printf("AGREGADO");
}




void cambiar_datos(struct nodo **p_lista, char *dato) {
    struct nodo *aux = *p_lista;
    int estadoEncontrado = 0;

    // Buscar el nodo con el dato especificado
    while (aux != NULL) {
        if (strcmp(aux->apellido, dato) == 0 || strcmp(aux->nombre, dato) == 0 ||
            strcmp(aux->nro_chasis, dato) == 0 || strcmp(aux->nro_chasis, dato) == 0) {

            printf("Datos actuales:\n");
            printf("Nombre y apellido: %s %s\n", aux->nombre, aux->apellido);
            printf("CUIT: %s\n", aux->CUIT);
            printf("CHASIS: %s\n", aux->nro_chasis);

            // Pedir nuevos datos
            printf("Ingrese nuevo nombre: ");
            scanf("%s", aux->nombre);
            printf("Ingrese nuevo apellido: ");
            scanf("%s", aux->apellido);
            printf("Ingrese nuevo CUIT: ");
            scanf("%s", aux->CUIT);
            printf("Ingrese nuevo CHASIS: ");
            scanf("%s", aux->nro_chasis);

            estadoEncontrado = 1;

        }
        aux = aux->psig;
    }

    if (!estadoEncontrado) {
        printf("No se encontró ningún nodo con el dato proporcionado.\n");
    }
}



void buscarApellido(struct nodo **p_lista, char *apellido)
{
  struct nodo *aux = *p_lista;
  int estadoEncontrado = 0;

  while (aux != NULL) {
    if (strcmp(aux->apellido,apellido) == 0)
     {
      printf("Nombre y apellido: %s %s\n", aux->nombre, aux->apellido);
      printf("CUIT: %s\n", aux->CUIT);
      printf("CHASIS: %s\n", aux->nro_chasis);
      estadoEncontrado = 1;
     }
    aux = aux->psig;
  }

  if (estadoEncontrado == 0) {
    printf("no encontrado");
  }
}


void buscar_chasis(struct nodo **p_lista, char *chasis)
{
  struct nodo *aux = *p_lista;
  int estadoEncontrado = 0;

  while (aux != NULL) {
    if (strcmp(aux->nro_chasis,chasis) == 0)
     {
      printf("CUIT: %s\n", aux->CUIT);
      printf("Nombre y apellido: %s %s\n", aux->nombre, aux->apellido);
      printf("CHASIS: %s\n", aux->nro_chasis);
      estadoEncontrado = 1;
     }
    aux = aux->psig;
  }

  if (estadoEncontrado == 0) {
    printf("no encontrado");
  }
}

void liberarLista(struct nodo **pinicial) {
  struct nodo *pactual = 0;
  struct nodo *psiguiente = 0;

  pactual = (*pinicial);

  while (pactual != 0) {
    psiguiente = pactual->psig;
    free(pactual);
    (*pinicial) = 0;
    pactual = psiguiente;
  }
  printf("LISTA LIBERADA");
}

void agregarNodoAlPrincipio(struct nodo **pinicial) {

  struct nodo *paux = (*pinicial);

  if ((*pinicial) == 0) { // lista vacia     //agregar Primer Nodo
    (*pinicial) = (struct nodo *)malloc(sizeof(struct nodo));
    (*pinicial)->psig = 0; // hago
                           //  0 al psig del nodo creado
    printf("Ingrese un nombre\n");
    scanf("%s", (*pinicial)->nombre);
    printf("Ingrese el apellido\n");
    scanf("%s", (*pinicial)->apellido);
    printf("Ingrese el cuit\n");
    scanf("%s", (*pinicial)->CUIT);
    printf("Ingrese el chasis\n");
    scanf("%s", (*pinicial)->nro_chasis);
  } else { // lista no vacia
    (*pinicial) = (struct nodo *)malloc(sizeof(struct nodo));
    (*pinicial)->psig = paux;
    printf("Ingrese un nombre\n");
    scanf("%s", (*pinicial)->nombre);
    printf("Ingrese el apellido\n");
    scanf("%s", (*pinicial)->apellido);
    printf("Ingrese el cuit\n");
    scanf("%s", (*pinicial)->CUIT);
    printf("Ingrese el chasis\n");
    scanf("%s", (*pinicial)->nro_chasis);
                } for (int i = 0; i < 2; i++) {
   //agregarNodoAlPrincipio(&pINI);
}
  }
//}

void mostrarLista(struct nodo *pinicial) {
  if (pinicial == 0) {
    printf("Lista Vacia");
  } else {
    while (pinicial != 0) {
      printf(" %s  %s %s  %s\n", pinicial->nombre,
             pinicial->apellido, pinicial->nro_chasis, pinicial->CUIT);
      pinicial = pinicial->psig;
    }
  }
}

void buscarNombre(struct nodo **p_lista, char *nombre) {
  struct nodo *aux = *p_lista;
  int estadoEncontrado = 0;

  while (aux != NULL) {
    if (strcmp(aux->nombre, nombre) == 0) {
      printf("Nombre y apellido: %s %s\n", aux->nombre, aux->apellido);
      printf("CUIT: %s\n", aux->CUIT);
      printf("CHASIS: %s\n", aux->nro_chasis);
      estadoEncontrado = 1;
    }
    aux = aux->psig;
  }

  if (estadoEncontrado == 0) {
    printf("no encontrado");
  }
}

void enlazarNodoAlFinal(struct nodo *pinicial, struct nodo *pnodo) {
  // busco el ultimo nodo
  struct nodo *pultimo =pinicial;

  while (pultimo->psig != 0) {
    pultimo = pultimo->psig;
  }

  pultimo->psig = pnodo;
  pnodo->psig = 0;


}

    //*/
