bool comprobar_parentesis(int **array, char c){
    
    bool esValido = true;
    int tamanio = strlen(*array); // Obtener el tamaño del array
    int ultimo = -1;
    if( tamanio > 0) ultimo = *array[tamanio - 1];


    if ( c == ')'){
        if ( ultimo == -1 || ultimo != 0 ){
            esValido = false;
        }else{
            *array = realloc(*array, (tamanio - 1) * sizeof(char));
            (*array)[tamanio - 2] = '\0'; // Añadir terminador nulo
        }
    }else if ( c == ']' ){
        if( ultimo == -1 || ultimo != 1 ){
            esValido = false;
        }else{
            *array = realloc(*array, (tamanio - 1) * sizeof(char));
            (*array)[tamanio - 2] = '\0'; // Añadir terminador nulo
        }
    }else if ( c == ']' ){
        if( ultimo == -1 || ultimo != 2 ){
            esValido = false;
        }else{
            *array = realloc(*array, (tamanio - 1) * sizeof(char));
            (*array)[tamanio - 2] = '\0'; // Añadir terminador nulo
        }
    }     

    if ( !esValido ){
        free(*array);
        *array = NULL;
    }else{
        *array = realloc(*array, (tamanio + 1) * sizeof(char));
        (*array)[tamanio] = c;
        (*array)[tamanio + 1] = '\0'; // Añadir terminador nulo
    }

    return esValido;
}

// (  --> 0
// [  --> 1
// {  --> 2
bool isValid(char* s) {
    
    int *array = malloc(sizeof(char)); // Inicializar el array
    int idx = 0;
    char caracter;
    bool esValido = true;

    while (s[idx] != '\0') { 
        caracter = s[idx];
        esValido = comprobar_parentesis(array, caracter );
        if (esValido == false) {
            free(array);
            array = NULL;
            break;
        }
        idx++;
    }
    
    return esValido;
}