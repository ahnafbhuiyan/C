#define N 4
void question3(int mat[][N]);

question3(int mat[][N]){
    for (int i=0;i<N;i++){// Prints the first section of the matrix
        for (int j=i; j>=0; j--){//Starts j at the current value of i, and counts down
            printf("%d ",mat[j][i-j]);
        }
    }

    int size = N-1;//Because C counts from 0, the N-1 is used to print the elements of the matrix
    for (int i=0; i<size; i++){//Prints the second section of the matrix
            for (int j=0; j<size-i; j++){
               printf("%d ", mat[size-j][i+j+1]);
            }

    }
}


