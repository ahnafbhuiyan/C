double question5(){
    double n = -1.0;
    double piT = 4.00;
    double negative = (-1);

    while (n<1){//Repeats until the input is greater than 1
        printf("Enter a number that is greater to or equal to 1: ");
        scanf("%lf", &n);
    }

    for (double i = 0;i<n;i++){
        if (n==1){//If the input is '1' the output will just be 4, the first term
            return piT;
        }
        else {
            //Creates the fraction portions of pi
            double decimals = negative*(4.00/(3+2*i));
            piT = piT + decimals;
            negative = negative*(-1);//Keeps the alternating series switching between negative and postive
        }

}
    int disp = n/1;
    printf ("The approximation of pi to the %d terms is: %lf\n",disp,piT);
}
