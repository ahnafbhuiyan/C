int question4(){
    double average;

    //Asks for the user's average
    printf("Enter your average: ");
    scanf("%lf",&average);

    //The following set of lines checks the average and finds which range it is in
    if (average<100 && average>90){
        printf("Your average is a 4\n");
    }
    else if (average<89 && average>80){
        printf("Your average is a 3\n");
    }
    else if (average<79 && average>70){
        printf("Your average is a 2\n");
    }
    else if (average<69 && average>60){
        printf("Your average is a 1\n");
    }
    else if (average<59 && average>0){
        printf("Your average is a 0\n");
    }
    else {//If the user inputted percentages which do not create a proper average within the given ranges, the following line will be outputted
        printf("You inputted something wrong\n");
    }
}
