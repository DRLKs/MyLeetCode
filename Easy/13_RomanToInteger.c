int obtenerPoderLetra( char c){
    char caracteres[7] = {'I', 'V', 'X', 'L', 'C', 'D','M'};

    int poder = -1;

    for( int idx = 0 ; (idx < 7) && poder == -1 ; ++idx ){
        if( c == caracteres[idx] ){
            poder = idx;
        }
    }

    return poder;
}

int romanToInt(char* s) {

    
    int values[7] = {1,5,10,50,100,500,1000};

    int powerLetterAnterior;
    int powerLetter;    // Poder de la letra, pos del caracter en el array de caracteres

    int valorComboActual = 0;
    int valorTotal = 0;
    int longitud = strlen(s);
    if( longitud > 0 ){
        powerLetterAnterior = obtenerPoderLetra( s[0] );
        valorComboActual = values[ powerLetterAnterior ];
    }
    for( int idx = 1 ; idx < longitud ; ++idx ){
        powerLetter = obtenerPoderLetra( s[idx] );
        if( powerLetterAnterior == powerLetter ){
            valorComboActual += values[powerLetter];
        }else if( powerLetterAnterior > powerLetter ){
            valorTotal += valorComboActual;
            valorComboActual = values[ powerLetter ];
        }else{
            valorTotal -= valorComboActual;
            valorComboActual = values[ powerLetter ];
        }
        powerLetterAnterior = powerLetter;
    }
    valorTotal += valorComboActual;
    return valorTotal;
}