#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea{
    int TareaID;
    char *Descripcion;
    int Duracion; //91+10;
};

void CargarTarea(Tarea **TareaLocal,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        Tarea *nueva = (Tarea*)malloc(sizeof(Tarea));
        nueva->TareaID = i+1;
        
        printf("Ingrese una descripcion para la tarea [%d]:",i+1);
        fflush(stdin);
        char *Descripcion;
        char descrip[500];
        gets(descrip);
        nueva->Descripcion = (char*)malloc(sizeof(char)*strlen(descrip));
        strcpy(nueva->Descripcion,descrip);

        nueva->Duracion = rand()% 91+10;

        *TareaLocal = nueva;

        *TareaLocal++;
    }
    
}
void RealizarTarea(Tarea **TareaLocal,Tarea **TareaRLocal,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        int confirm;
        printf("TareaID:%d\n",TareaLocal[i]->TareaID);
        printf("Descripcion:%s\n",TareaLocal[i]->Descripcion);
        printf("Duracion:%d\n",TareaLocal[i]->Duracion);
        printf("\n");

        printf("Se realizo la tarea?[1/0]");
        scanf("%d", &confirm);
        
        while(confirm < 0 || confirm > 1){
            printf("Se realizo la tarea?[1/0]");
            scanf("%d", &confirm);
            printf("\n");
        }

        if (confirm == 1) {
            TareaRLocal[i] = TareaLocal[i];
            TareaLocal[i] = NULL;
        } else {
            TareaRLocal[i] = NULL;
        }
        
    }
    
}

void MostrarLista(Tarea **Lista,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        if(Lista[i] != NULL){
        printf("TareaID:%d\n",Lista[i]->TareaID);
        printf("Descripcion:%s\n",Lista[i]->Descripcion);
        printf("Duracion:%d\n",Lista[i]->Duracion);
        printf("\n"); 
        }
    }
    
}



int main(){
    int cantTareas;
    
    printf("Ingrese la cantidad de tareas:");
    scanf("%d",&cantTareas);
    

   Tarea **TareasPendientes = (Tarea**)malloc(sizeof(Tarea*)*cantTareas);
   Tarea **TareasRealizadas = (Tarea**)malloc(sizeof(Tarea*)*cantTareas);

    CargarTarea(TareasPendientes,cantTareas);
    printf("\n\n=============LISTA DE TAREAS=============\n\n");
    RealizarTarea(TareasPendientes,TareasRealizadas,cantTareas);

    printf("\n\n=============LISTA DE TAREAS PENDIENTES=============\n\n");
    MostrarLista(TareasPendientes,cantTareas);
    printf("\n\n=============LISTA DE TAREAS REALIZADAS=============\n\n");
    MostrarLista(TareasRealizadas,cantTareas);
    
    

    return 0;
}