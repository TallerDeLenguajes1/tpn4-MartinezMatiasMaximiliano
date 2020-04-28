#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea{
    int TareaID;
    char *Descripcion;
    int Duracion; //91+10;
};

//funciones
void CargarTareas(Tarea *tarea,int cantTareas);
void RealizarTareas(Tarea *Pendiente,Tarea *Realizado,int cantTareas);
void MostrarPendientes(Tarea *Pendientes);
void MostrarRealizadas(Tarea *Realizadas);

int main(){
    srand(time(NULL));
    int cantTareas = 0;
    printf("Ingrese la cantidad de tareas a realizar:");
    scanf("%d",&cantTareas);

    Tarea *TareasPendientes = (Tarea*)malloc((sizeof(Tarea))*cantTareas);
    CargarTareas(TareasPendientes,cantTareas);
    Tarea *TareasRealizadas =(Tarea*)malloc((sizeof(Tarea))*cantTareas);
    RealizarTareas(TareasPendientes,TareasRealizadas,cantTareas);
    MostrarPendientes(TareasPendientes);
    MostrarRealizadas(TareasRealizadas);
    return 0;
}

void CargarTareas(Tarea *tarea,int cantTareas){
    Tarea nueva;
    for (int i = 0; i < cantTareas; i++)
    {
        nueva.TareaID = i+1;

        char *Descripcion;
        int tamanio=0;
        char descrip[500];
        printf("Ingrese una descripcion para la tarea [%d]:",i+1);
            fflush(stdin);
            gets(descrip);
            tamanio = strlen(descrip);
            nueva.Descripcion = (char*)malloc(sizeof(char)*tamanio);
            strcpy(nueva.Descripcion,descrip);

        nueva.Duracion = rand()%91+10;

        *tarea = nueva;
        tarea++;
    }    
}

void RealizarTareas(Tarea *Pendiente,Tarea *Realizado,int cantTareas){
    Tarea mostrarTarea;
    char confirmar;
    for(int i=0;i < cantTareas;i++){
        mostrarTarea = *Pendiente;    
        printf("\n\n=========Tarea [%d]=========\n\n",i+1);
        printf("ID:%d\n",mostrarTarea.TareaID);
        printf("Descripcion:%s\n",mostrarTarea.Descripcion);
        printf("Duracion:%d\n",mostrarTarea.Duracion);
        
        if(confirmar != 'Y' || confirmar != 'N' || confirmar != 'n' || confirmar != 'y'){
        printf("Se realizo la tarea?[Y/N]");
        fflush(stdin);
        confirmar = getchar();
        }
        
       /*
        if(confirmar == 'Y'){
            *Realizado = mostrarTarea;
            Realizado++; 
            Pendiente++;
        }else{
            Pendiente++;
        }
        */
    }
}

void MostrarPendientes(Tarea *Pendientes){
    printf("\n\n=========TAREAS PENDIENTES=========\n\n");
    while(Pendientes != NULL){
        Tarea aux;
        aux = *Pendientes;
        printf("ID:%d\n",aux.TareaID);
        printf("Descipcion:%s\n",aux.Descripcion);
        printf("Duracion%d\n",aux.Duracion);
        printf("\n----------------\n");
        Pendientes++; 
    }
}

void MostrarRealizadas(Tarea *Realizadas){
    printf("\n\n=========TAREAS REALIZADAS=========\n\n");
    while(Realizadas != NULL){
        Tarea aux;
        aux = *Realizadas;
        printf("ID:%d\n",aux.TareaID);
        printf("Descipcion:%s\n",aux.Descripcion);
        printf("Duracion%d\n",aux.Duracion);
        printf("\n----------------\n");
        Realizadas++; 
    }
}
