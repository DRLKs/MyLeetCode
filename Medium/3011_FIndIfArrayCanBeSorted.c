void swap(int nums[], int pos1, int pos2) {
    int aux = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = aux;
}

int numBits1( int num ){
    int contador = 0;
    while (num > 0) {
        if (num & 1) { // Verifica si el bit menos significativo es 1, es igual que (num % 2 == 1)
            contador++;
        }
        num >>= 1; // Desplaza los bits hacia la derecha
    }
    return contador;
}

bool canSortArray(int* nums, int numsSize) {
    
    bool sortable = true;
    int idx = 0;
    while( idx < (numsSize -1) && sortable ) {
        if( nums[idx] > nums[idx+1] ){
            if( numBits1( nums[idx] ) == numBits1( nums[idx + 1] ) ){
                swap( nums, idx ,idx+1 );
                if( idx > 0){
                    --idx;
                }
            }else{
                sortable = false;
            }
        }else{
            ++idx;
        }
    }
    return sortable;
}