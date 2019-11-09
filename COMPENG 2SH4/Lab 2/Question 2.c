#define N 4

int is_diag_dom( int mat[ ][N]);
double fabs(double x);
double sum=0,diag,temp;
int check = 1;// The value which is outputted


is_diag_dom(int mat[][N]){
     for (int i=0; i<N;i++){
        diag = mat[i][i];// Finds the diagonal element of the current row
        sum=0;// Resets the sum
        for (int j=0;j<N;j++){
            if (j!=i){// Makes it so the diagonal element is not included into the sum
            temp = mat[i][j];//Stores the matrix element into a temporary double
            sum = sum + fabs(temp);// Sums each value in the row except for the diagonal
        }
    }
    if (fabs(diag)<sum){//Checks if the diagonal is bigger or not, and changes the check value depending
            check = 0;
    }
}

return check;
}
