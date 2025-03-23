void eliminarPorIndice(int arr[], int *n, int pos) {

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];  // Desplaza los elementos a la izquierda
    }

    (*n)--;  // Reduce el tamaño del array
}

int removeDuplicates(int* nums, int numsSize) {
    int k = 0;

    int aux;
    if( numsSize > 0 ){     // En caso de que el array si tenga elmentos tomamos el primero como referencia
        aux = nums[0];
        k++;
    }
    // Recorremos el array para buscar estos elementos repetidos
    for( int idx = 1 ; idx < numsSize; idx++ ){
        
        if( aux < nums[idx] ){
            k++;
            aux = nums[idx];
        }else{
            eliminarPorIndice(nums, &numsSize, idx);
            idx--;
        }
    }

    return k;
}