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
        printf("Es un/a %s.\n", lenguaje->nombre_lenguaje);
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
	Lenguaje identificador= {"Identificador", 29, 9, 1,{7},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+','#','*'}};
	Lenguaje *identificadorptr = & identificador;
	short TTIdentificador [9][29] = {
		{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,1,2,3},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,8,8},
		{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,8,8,8},
		{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,8},
		{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,8,8},
        {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,8,7,8},
		{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,7},
		{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
        {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}
	};
    Lenguaje operador= {"Operador", 9, 3, 1,{1},{'+','-','.','/','<','>','!','=','*'}};
    Lenguaje *operadorptr = &operador;
    short TTOperador [3] [9] = {
        {1,1,1,1,1,1,1,1,1},
        {3,3,3,3,3,3,3,3,3},
        {3,3,3,3,3,3,3,3,3}
    };
    Lenguaje palabra_reservada = {"Palabra Reservada", 28, 13, 1, {11}, {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','(',')'}};
    Lenguaje *palabra_reservadaptr = &palabra_reservada;
    short TTPalabra_reservada [13] [28] = {
      {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 1,12},
      { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,12,11},
      { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,12,11},
      { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,12,11},
      { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,12,11},
      { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,12,11},
      { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,12,11},
      { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,12,11},
      { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,12,11},
      {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,12,11},
      {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,11},
      {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
      {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12}
    };
    Lenguaje caracter_de_puntuacion = {"Caracter de Puntuacion", 6, 3, 1, {1}, {',',';','|','[',']','_'}};
    Lenguaje *caracter_de_puntuacionptr = &caracter_de_puntuacion;
    short TTCaracter_de_puntuacion [3] [6] = {
        {1,1,1,1,1,1},
        {2,2,2,2,2,2},
        {2,2,2,2,2,2}
    };
    Lenguaje constantes = {"Constante", 11, 12, 1, {10}, {'0','1','2','3','4','5','6','7','8','9','/'}};
    Lenguaje *constantesptr = &constantes;
    short TTConstantes;
    pasar_matriz(identificadorptr, TTIdentificador);
    pasar_matriz(operadorptr, TTOperador);
    pasar_matriz(palabra_reservadaptr, TTPalabra_reservada);
    pasar_matriz(caracter_de_puntuacionptr, TTCaracter_de_puntuacion);
    printf("Ingrese la cadena: ");
    fflush(stdin);
    fgets(cadena,sizeof(cadena)-1,stdin);
    verificar_lenguaje(operadorptr,cadena);
    verificar_lenguaje(identificadorptr, cadena);
    verificar_lenguaje(palabra_reservadaptr, cadena);
    verificar_lenguaje(caracter_de_puntuacionptr, cadena);
    return 0;
}
