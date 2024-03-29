int question3(){
    int x;
    while(x!=0){
        int points = 0;
        printf("Input a number or input 0 to end: ");
        scanf("%d",&x);
        if (x==0){//If x=0 then the loop is broken and the code stops running
            printf("Goodbye \n");
            break;
        }
        int used = x;//Different value of x to keep things organized
        if (used<0){//Makes sure the input value is positive
            used = used*(-1);
        }
        //For every multiple of 10 which the number x has, the number 'points' adds one, which therefore counts the number of digits
        while (used>0){
           used = used/10;
           points++;
        }
        //Prints whether or not the digit is 5 digits
        if (points==5){
            printf("The number has 5 digits\n");
        }
        else{
            printf("The number does not have 5 digits\n");
        }
    }

}

