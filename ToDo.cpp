#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
};

struct Nodo{
Tarea T;
Nodo *Siguiente;
};

Nodo *CrearListaVacia(){
    return NULL;
}

Tarea* CargarTarea(int i){
    char desc[500];
    printf("ingrese una descripcion para la tarea[%d]:",i+1);
    gets(desc);
    Tarea *NuevaTarea;
    NuevaTarea = (Tarea*)malloc(sizeof(Tarea));
    NuevaTarea->TareaID = i+1;
    NuevaTarea->Descripcion = (char*)malloc(sizeof(char)*strlen(desc));strcpy(NuevaTarea->Descripcion,desc);
    NuevaTarea->Duracion = rand()%91+10;
    return NuevaTarea;
}


void CrearTareas(Nodo **Pendientes,int i){
    Nodo *NuevoNodo;
    NuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    NuevoNodo->T = *CargarTarea(i);
    NuevoNodo->Siguiente = NULL;

    if (*Pendientes == NULL)
    {
       NuevoNodo ->Siguiente = *Pendientes; //final de la lista a null
       *Pendientes = NuevoNodo; //null pasa a ser nuevonodo
    }else{
        Nodo *aux;
        aux = *Pendientes;
        while(aux->Siguiente != NULL){
            aux = aux->Siguiente;
        }
        aux->Siguiente = NuevoNodo;
    }
}

void MoverTarea (Nodo **Pendientes,Nodo **Realizadas){
    Nodo *Aux;
    Aux = *Pendientes;

    Nodo *Copia;
    Copia = (Nodo*)malloc(sizeof(Nodo));
    Copia->T = Aux->T;
    Copia->Siguiente = NULL;

    *Pendientes = Aux->Siguiente;
    free(Aux);

    *Realizadas = Copia;
}

void RealizarTareas(Nodo **Pendientes,Nodo **Realizadas){
    Nodo *AuxDesplazar;
    AuxDesplazar = *Pendientes;
    while(AuxDesplazar!= NULL){
        int confirm = -1;
        printf("ID:%d\n",AuxDesplazar->T.TareaID);
        printf("Descripcion:%s\n",AuxDesplazar->T.Descripcion);
        printf("Duracion:%d\n",AuxDesplazar->T.Duracion);

        while(confirm<0 || confirm>1){
        printf("Se realizo la tarea?[1/0]");
        scanf("%d",&confirm);
        }

        if (confirm == 1)
        {
            (*Pendientes)->Siguiente = AuxDesplazar->Siguiente;
            MoverTarea(&AuxDesplazar,Realizadas);
        }else{
            AuxDesplazar = AuxDesplazar->Siguiente;
        }

    }

}

void MostrarLista(Nodo **Lista){
    Nodo *Aux;
    Aux = *Lista;

    while(Aux != NULL){
        printf("ID:%d\n",Aux->T.TareaID);
        printf("Descripcion:%s\n",Aux->T.Descripcion);
        printf("Duracion:%d\n",Aux->T.Duracion);
        Aux = Aux->Siguiente;
    }

    
}

int main(){
    setvbuf(stdout,NULL,_IONBF,0);
	srand(time(NULL));
    int cantTareas;

    Nodo *Pendientes = CrearListaVacia();
    Nodo *Realizadas = CrearListaVacia();

    printf("Ingrese la cantidad de tareas:");
    scanf("%d",&cantTareas);

    for (int i = 0; i < cantTareas; i++)
    {
        CrearTareas(&Pendientes,i);
    }
    
    printf("\n\n===============LISTA DE TAREAS===============\n\n");

    RealizarTareas(&Pendientes,&Realizadas);


    printf("\n\n===============LISTA DE TAREAS PENDIENTES===============\n\n");
    MostrarLista(&Pendientes);
    printf("\n\n===============LISTA DE TAREAS REALIZADAS===============\n\n");
    MostrarLista(&Realizadas);
    return 0;
}