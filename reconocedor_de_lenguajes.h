#include <stdio.h>
#include <string.h>

typedef struct {
    short cantidad_estados;
    short tamanio_alfabeto;
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
        return 0;
    }else
    {
        return 1;
    }

}

/*
int verificarArchivo(char nombre []){
    FILE *codigo = fopen(nombre, "r");
    if (codigo == NULL){
        prtinf("No se encuentra el archivo");
        return -1;
    }
}

int procesarArchivo(char nombre[]){
    verificarArchivo(nombre[]);
    while (fgets(cadena,sizeof(cadena)-1,codigo)!= NULL){
        if (verificar_lenguaje(tablaptr,cadena)== 1){
            printf("Se detecto un error lexico");
            return (0);
        }
        ***ACA DEBERIAMOS TENER UN BUFFER GLOBAL Y AHI IR AGREGANDO TODOS LOS TOKENS***
        }
    parsear(buffer);
    printf("No se detectaron errores de ningun tipo en el codigo");
    fclose(codigo);
    return (0);
}

int parsear(char buffer[]){
    ***HACER LO QUE HAGA EL PARSER***
    for (i=0, i= TAMAÑO BUFFER, i++){
        char tokenActual[] = buffer[i];
        char tokenSiguiente[] = buffer[i+1];
        ***HABRIA QUE TENER UN TOKEN FINAL***

        if (EL SIGUIENTE TOKEN NO ES EL CORRECTO){
            printf("Se detecto un error sintactico);
            return(1);
        }
    }
    return(0);
}
*/
void inicializar_lenguajes (void){

	//Lenguaje nombre_del_lenguaje = {"Nombre Completo", tamaño del alfabeto, cantidad de estados, cantidad de estados finales, {estados finales},{alfabeto}};
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
    short TTConstantes [12] [11] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,11},
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,11},
        {11,11,11,11,11,11,11,11,11,11, 3},
        { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,11},
        { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,11},
        {11,11,11,11,11,11,11,11,11,11, 6},
        { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,11},
        { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,11},
        { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,11},
        {10,10,10,10,10,10,10,10,10,10,11},
        {11,11,11,11,11,11,11,11,11,11,11},
        {11,11,11,11,11,11,11,11,11,11,11}
    };
    Lenguaje tiposDeDatos = {"Tipo de Datos",7,8,1,{3},{'i','n','t','c','h','a','r'}};
    Lenguaje *tiposDeDatosptr = &tiposDeDatos;
    short TTtiposDeDatos [8] [7] = {
		{1,7,7,4,7,7,7},
		{7,2,7,7,7,7,7},
		{7,7,3,7,7,7,7},
		{7,7,7,7,7,7,7},
		{7,7,7,7,5,7,7},
		{7,7,7,7,7,6,7},
		{7,7,7,7,7,7,3},
		{7,7,7,7,7,7,7},
	};
	pasar_matriz(identificadorptr, TTIdentificador);
    pasar_matriz(operadorptr, TTOperador);
    pasar_matriz(palabra_reservadaptr, TTPalabra_reservada);
    pasar_matriz(caracter_de_puntuacionptr, TTCaracter_de_puntuacion);
    pasar_matriz(constantesptr, TTConstantes);
    pasar_matriz(tiposDeDatosptr, TTtiposDeDatos);
}
