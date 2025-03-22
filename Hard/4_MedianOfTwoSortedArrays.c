double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int tam = nums1Size + nums2Size;
    int par = 0;
    if( tam % 2 == 0 ){
        par = 1;
    }
    int medianaPos = tam / 2;   // En el caso de que sea Par, será este y el anterior
    int pos1 = 0;
    int pos2 = 0;
    double mediana = 0.0;


    for( int idx = 0; idx < medianaPos - par; ++idx ){
        
        if( pos1 < nums1Size && pos2 < nums2Size){
            if( nums2[pos2] < nums1[pos1] ){
                ++pos2;
            }else{
                ++pos1;
            }
        }else if( pos1 < nums1Size ){
            ++pos1;
        }else{
            ++pos2;
        }
    }

    for( int idx = medianaPos - par; idx <= medianaPos; ++idx ){
        
        if( pos1 < nums1Size && pos2 < nums2Size){
            if( nums2[pos2] < nums1[pos1] ){
                mediana += (double)nums2[pos2];
                ++pos2;
            }else{
                mediana += (double)nums1[pos1];
                ++pos1;
            }
        }else if( pos1 < nums1Size ){
            mediana += (double)nums1[pos1];
            ++pos1;
        }else{
            mediana += (double)nums2[pos2];
            ++pos2;
        }
    }

    if(  par == 1 ){
        mediana /= 2.0;
    }
        
    

    return mediana;
}