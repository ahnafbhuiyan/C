int question1a (){
    //Finding the sum using a for loop
    int sumfor = 0;
    for (int i=30; i<=1000; i++){
        if (i%4==0){//Checks for multiples of 4
            sumfor= sumfor+i;
        }
    }
     printf ("The sum for: %d \n", sumfor);
}

int question1b(){
    //Finding the sum using a while loop
    int i =30;
    int sumWhile=0;
    while(i<=1000){
        if (i%4==0){

            sumWhile = sumWhile +i;
        }
        i++;
    }

    printf ("The sum for: %d \n", sumWhile);
}

int question1c(){
    //Finding the sum using a do while loop
    int i = 30, sumDoWhile = 0;
    do{
        if (i%4==0){
            sumDoWhile = sumDoWhile + i;
        }
        i++;
    }
    while(i<=1000);

    printf ("The sum for: %d \n", sumDoWhile);
}
