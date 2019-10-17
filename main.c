#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    short cantidad_estados;
    short tamanio_alfabeto;
    short cantidad_e_finales;
    short estados_finales[5];
    char alfabeto [20];
    short tabla_t [37] [20];
} Tabla;

void pasar_matriz (Tabla *tabla, short matriz[tabla->cantidad_estados][tabla->tamanio_alfabeto]){
	int fila, columna;
	for (fila = 0;fila<tabla->cantidad_estados; fila++){
		for (columna = 0;columna < tabla->tamanio_alfabeto;columna++){
			tabla->tabla_t [fila] [columna] = matriz [fila] [columna];
		}
	}
}

int es_final (Tabla* tabla, short estado){
    short auxiliar;
    for (auxiliar = 0; auxiliar < 5; auxiliar++){
            printf("%d", tabla->estados_finales[auxiliar]);
        if (estado == tabla->estados_finales [auxiliar]) return 1;
    return 0;
    }
}

int verificar_lenguaje (Tabla* tabla, char cadena []){
    int numero_de_caracter = 0;
    int fila = 36;
    int columna = 0;
    while (numero_de_caracter < strlen(cadena)-1){
        while (columna < tabla->tamanio_alfabeto && cadena [numero_de_caracter] != tabla->alfabeto[columna]) columna++;
        if(isdigit(cadena[numero_de_caracter])) columna = 19;
        if(isalpha(cadena[numero_de_caracter])) columna = 0;
        printf("%d %d \n",fila, columna);
        if (columna == tabla->tamanio_alfabeto){
            return 0;
        }
        fila = tabla->tabla_t [fila] [columna];
        columna = 0;
        numero_de_caracter++;
    }
    if (es_final (tabla, fila) == 1){
        switch (fila){
            case 7:
                printf("Identificador");
                break;
            case 9:
                printf("Operador");
                break;
            case 21:
                printf("Palabra35eservada");
                break;
            case 23:
                printf("Caracter de Puntuacion");
                break;
            case 34:
                printf("Constantes");
                break;
        }
        return 0;
    }
    printf("%d", es_final(tabla, fila));
    printf("No es nada. Estado: %d", fila);
    return 1;
}

int main (void){

    char cadena [30+1];

	Tabla tabla= {37,20,5,{7,9,21,23,34},{'a','+','-', '.','/','<','>','!','=','*',';','|','[',']','_','#','(',')','d'}};
	Tabla *tablaptr = & tabla;
	short TT[37][20] = {
		{35,1,35,35,35,35,35,35,35,2,35,35,35,35,35,35,3,35,35,35},
        {4,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {5,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {6,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {4,7,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {5,35,35,35,35,35,35,35,35,7,35,35,35,35,35,35,35,35,35,35},
        {6,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,7,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,9,9,9,9,9,9,9,9,9,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,11,35,35},
        {12,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {13,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {14,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {15,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {16,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {17,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {18,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {19,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {20,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,21,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,23,23,23,23,23,23,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,25},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,26},
        {35,35,35,35,27,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,28},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,29},
        {35,35,35,35,30,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,31},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,32},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,33},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,34},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
        {35,9,8,22,8,8,8,8,8,8,22,22,22,22,22,22,3,10,10,24}
	};
	pasar_matriz(tablaptr, TT);
    printf("Ingrese la cadena: ");
    fflush(stdin);
    fgets(cadena,sizeof(cadena)-1,stdin);
    verificar_lenguaje(tablaptr,cadena);

    return 0;
}
