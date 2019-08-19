#include <stdio.h>
#include <string.h>

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
    for (auxiliar = 0; auxiliar < lenguaje->cantidad_e_finales; auxiliar++){
        if (estado == lenguaje->estados_finales [auxiliar]) return 1;
    return 0;
    }
}

int verificar_lenguaje (Lenguaje* lenguaje, char cadena []){
    int numero_de_caracter = 0;
    int fila = 0;
    int columna = 0;
    while (numero_de_caracter < strlen(cadena)-1){
        while (columna < lenguaje->tamanio_alfabeto && cadena [numero_de_caracter] != lenguaje->alfabeto[columna]) columna++;
        if (columna == lenguaje->tamanio_alfabeto){
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
	Lenguaje identificador= {"Identificador", 27, 5, 1,{3},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+'}};
	Lenguaje *identificadorptr = & identificador;
	short TTIdentificador [5][27] = {
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
	};
    Lenguaje operador= {"Operador", 9, 3, 1,{1},{'+','-','.','/','<','>','!','=','*'}};
    Lenguaje *operadorptr = &operador;
    short TTOperador [3] [9] = {
        {1,1,1,1,1,1,1,1,1},
        {3,3,3,3,3,3,3,3,3},
        {3,3,3,3,3,3,3,3,3}
    };
    pasar_matriz(identificadorptr,TTIdentificador);
    pasar_matriz(operadorptr, TTOperador);
    printf("Ingrese la cadena: ");
    fflush(stdin);
    fgets(cadena,sizeof(cadena)-1,stdin);
    verificar_lenguaje(operadorptr,cadena);
    verificar_lenguaje(identificadorptr, cadena);
    return 0;
}
