void print_vector(double array[], int size);
void add_vectors( double vector1[],double vector2[],double vector3[], int n);
double scalar_prod(double vector1[], double vector2[], int n);
double norm2(double vector1[], int n);



print_vector(double array[], int size){

    for (int i=0; i<size; i++){
        printf("Component %d: %lf\n", i, array[i]);//Prints the components of the inputted vector
    }
}

add_vectors( double vector1[],double vector2[],double vector3[], int n){

    for (int i=0; i<n; i++){
        vector3[i] = vector1[i]+ vector2[i];//Adds the ith component of the vector
    }
    printf("Add_vectors\n");
    print_vector(vector3,n);
}

double scalar_prod(double vector1[], double vector2[], int n){// Multiplies each element of the vectors together and adds them
    double sum=0;

    for (int i= 0; i<n; i++){
        sum = sum + vector1[i]*vector2[i];// Sums the products of the ith value of each vector
    }

    return sum;
}

double norm2(double vector1[],int n){// Uses the scalar_prod function to multiply and add each element of the same vector and the find the norm by square rooting

    double prod  = scalar_prod(vector1,vector1, n);//Calls the scalar_prod function and stores it into a variable
    double norm = sqrt(prod);// square root

    return norm;
}
