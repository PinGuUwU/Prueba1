#include <stdio.h>
#include <stdlib.h>

typedef struct rsueldo {
    int cod_suc;
    int cod_emp;
    float sueldo;
} rsueldo;


void mostrar_todas_suc();
void mostrar_una_suc();
void menu();
void pausa();

int main(){
    char archivo[]="sueldos.txt";
    menu(archivo);
    return 0;
}

void menu(char archivo[]){
    int opc,control=1;
    while(control){
        printf("Eliga una opcion:\n 1-Mostrar reposrte de todas las sucursales.\n 2-Mostrar reporte de una sucursal.\n 0-Salir\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                mostrar_todas_suc(archivo);
            break;
            case 2:
                mostrar_una_suc(archivo);
            break;
            case 0:
                control=0;
            break;
        }
        pausa();
    }
}

void mostrar_todas_suc(char name_arch[]){
    FILE * suel = fopen(name_arch,"r");
    rsueldo sueldos;
    int cod_suc=0,cod_emp=0;
    float sueldo=0;
    int control=1;
    fscanf(suel, "%d %d %f", &sueldos.cod_suc, &sueldos.cod_emp, &sueldos.sueldo);
    float suc_ant,total_suc=sueldos.sueldo;
    printf("\tREPORTE DE sueldos.sueldo\n\n");
    while(!feof(suel)){
        suc_ant=sueldos.cod_suc;
        printf("SUCURSAL %d\n\n",sueldos.cod_suc);
        printf("Codigo empleado\t\tsueldos.sueldo\n\n");
        while(control && suc_ant==sueldos.cod_suc){
            printf("%d\t\t\t$ %.2f\n\n", sueldos.cod_emp, sueldos.sueldo);
            fscanf(suel, "%d %d %f", &sueldos.cod_suc, &sueldos.cod_emp, &sueldos.sueldo);
            total_suc+= sueldos.sueldo;
            if(feof(suel)){
                printf("%d\t\t\t$ %.2f\n", sueldos.cod_emp, sueldos.sueldo);
                control=0;
            }
        }
        
        printf("Total Sucursal\t\t$ %.2f\n\n",total_suc);
        total_suc=0;
    }
    fclose(suel);
}

void mostrar_una_suc(char name_arch[]){
    FILE * suel = fopen(name_arch,"r");
    rsueldo sueldos;
    int num=0,cod_suc=0,cod_emp=0;
    float sueldo=0;
    printf("Ingrese numero de sucursal a consultar:");
    scanf("%d",&num);
    fscanf(suel,"%d %d %f", &sueldos.cod_suc, &sueldos.cod_emp, &sueldos.sueldo); 
    printf("\nSUCURSAL %d\n\n", sueldos.cod_suc);
    printf("Codigo empleado\t\tsueldos.sueldo\n\n");        
    while(!feof(suel)){
        while(sueldos.cod_suc==num && !feof(suel)){
            printf("%d\t\t\t$ %.2f\n",sueldos.cod_emp, sueldos.sueldo);            
            fscanf(suel,"%d %d %f", &sueldos.cod_suc, &sueldos.cod_emp, &sueldos.sueldo);
            if(feof(suel)){
                printf("%d\t\t\t$ %.2f\n", sueldos.cod_emp, sueldos.sueldo);
            }
        }
        fscanf(suel,"%d %d %f", &sueldos.cod_suc, &sueldos.cod_emp, &sueldos.sueldo);
    }
    fclose(suel);
}


void pausa(){
    getc(stdin);
    printf("\tPresione entres para continuar\n");
    getc(stdin);
}