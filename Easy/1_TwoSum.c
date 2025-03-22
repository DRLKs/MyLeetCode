/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int numAux;
    int* res = (int*)malloc(2 * sizeof(int));    // Incializo el array
    *returnSize = 2;
    for( int idx = 0 ; (idx < numsSize - 1)  ; idx++ ){
        res[0] = idx;
        numAux = nums[idx]; 
        for( int idx1 = idx + 1 ; (idx1 < numsSize) ; idx1++ ){
            if( numAux + nums[idx1] == target  ){
                res[1] = idx1;
                return res;
            }
        }
        
    }
    free(res);  // Liberar la memoria si no hay solución
    *returnSize = 0;
    return NULL;
}