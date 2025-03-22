char cambiarBit( char b ){  // Cambia BIT en ASCII
    if( b == '0' ){
        return '1';
    }else{
        return '0';
    }
}

int minChanges(char* s) {
    int changes = 0;
    int sizeS = strlen(s);
    if( sizeS > 1 ){
        int even = 0;
        char bitActual;
        char bitAnterior = s[0];

        for( int idx = 1; idx < sizeS ; ++idx ){
            bitActual = s[idx];
            if( bitActual == bitAnterior ){
                even = (even + 1) % 2;
            }else if( even == 0 ){
                bitActual = cambiarBit( bitActual );
                s[idx] = bitActual;
                ++changes;
                ++even;
            }else{
                even = 0;
            }
            bitAnterior = bitActual;
        }

    }
    return changes;
}