#include <stdio.h>

typedef struct {
    char nombre_lenguaje [30];
    short tamanio_alfabeto;
    short cantidad_estados;
    short cantidad_e_finales;
    short estados_finales[5];
    char alfabeto [30];
    short tabla [15] [30];
} Lenguaje;

void pasar_matriz (Lenguaje *lenguaje, short matriz[lenguaje->cantidad_estados][lenguaje->tamanio_alfabeto]){
	int fila, columna;
	for (fila = 0;fila<lenguaje->cantidad_estados; fila++){
		for (columna = 0;columna < lenguaje->tamanio_alfabeto;columna++){
			lenguaje->tabla [fila] [columna] = matriz [fila] [columna];
		}
	}
}

void imprimir_matriz (Lenguaje *lenguaje){
    int fila, columna;
	for (fila = 0;fila<lenguaje -> cantidad_estados; fila++){
		for (columna = 0;columna < lenguaje -> tamanio_alfabeto;columna++){
			printf("%d,", lenguaje -> tabla [fila] [columna]);
		}
		printf("\n");
	}
}

int es_final (Lenguaje* lenguaje, short estado){
    short auxiliar;
    /*while (lenguaje->estados_finales [auxiliar] < lenguaje->cantidad_e_finales && lenguaje->estados_finales [auxiliar] != estado) auxiliar ++;
    if (auxiliar < lenguaje->cantidad_e_finales) return 1;*/
    for (auxiliar = 0; auxiliar < lenguaje->cantidad_e_finales; auxiliar++){
        if (estado == lenguaje->estados_finales [auxiliar]) return 1;
    return 0;
    }
}

int verificar_lenguaje (Lenguaje* lenguaje, char cadena []){
    int numero_de_caracter = 0;
    int fila = 0;
    int columna = 0;
    while (cadena[numero_de_caracter] != '\0'){
        while (columna < lenguaje->tamanio_alfabeto && cadena [numero_de_caracter] != lenguaje->alfabeto[columna]) columna++;
        if (columna == lenguaje->tamanio_alfabeto){
//            printf("No pertenece al lenguaje.\n");
            return 0;
        }
        fila = lenguaje->tabla [fila] [columna];
        columna = 0;
        numero_de_caracter++;
    }
    if (es_final (lenguaje, fila) == 1){
        printf("Es un %s.\n", lenguaje->nombre_lenguaje);
        return 1;
    }else
    {
        return 0;
    }

}

int main (void){

    char cadena [30+1];
	/////////////////////////////////////////////////////
    //Definiendo el lenguaje de las palabras reservadas//
    //      Trabajarlo así lo hace más "generico"      //
    /////////////////////////////////////////////////////
	Lenguaje palabras_reservadas= {"Identificador",27, 5, 1,{3},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+'}};
	Lenguaje *palabras_reservadasptr = & palabras_reservadas;
	short TTPalabrasReservadas [5][27] = {
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
		};
    pasar_matriz(palabras_reservadasptr,TTPalabrasReservadas);
    imprimir_matriz(palabras_reservadasptr);
    printf("Ingrese la cadena: ");
    fflush(stdin);
    gets(cadena);
    verificar_lenguaje(palabras_reservadasptr, cadena);
    return 0;
}
