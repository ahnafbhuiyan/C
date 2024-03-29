void efficient( const int source[], int val[], int pos[], int size);
void reconstruct( int source[], int m, const int val[], const int pos[], int n);

efficient(const int source[], int val[], int pos[], int size){
    int j= 0;//Variable to index the new val and pos arrays
    for(int i=0; i<size; i++){
        if(source[i]!=0){//Checks when the ith element of source is not 0
            val[j]= source[i];//Stores the current value of source
            pos[j]=i;// Stores the current value of i

            printf("i: %d\n", i);
            printf("j: %d\n", j);
            printf("val: %d \n", val[j]);
            printf("pos: %d \n", pos[j]);

            j++;
        }
    }
    //Prints Val and Pos respectively
    printf("Val: ");
    for (int k = 0; k<j; k++){
            printf("%d ", val[k]);
    }
    printf("\nPos: ");
    for (int l = 0; l<j; l++){
            printf("%d ", pos[l]);
    }
}

reconstruct( int source[], int m, const int val[], const int pos[], int n){

    for (int l=0; l<n; l++){// Stores each of of val at the pos[l] postion into source
            source[pos[l]] = val[l];
    }
    //Prints the recreated array
    printf("\nRecontruct: ");
    for (int k = 0; k<m; k++){
            printf("%d ", source[k]);
    }
}
