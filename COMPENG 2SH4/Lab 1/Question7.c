int question7(){
    int m,sum= 0;

    printf("Input a number greater than 1: ");//Asks for the input of m, to check if it is a perfect number
    scanf("%d",&m);

    for (int j= 0; j<m;j++){
        sum= 0;// Resets the sum value

        for (int i= 1;i<=j-1;i++){//Iterates through every number that is 1 less than j
            if (j%i==0){//Checks if i is a factor of j
                sum = sum + i;//Sums every factor of j
            }
        }
        if (sum == j){//Prints if the sum is the same as the input
            if (j!=0){
            printf("The number %d is a perfect number\n", j);
                }
        }
        if (j==m-1){
            break;
    }

}

}
