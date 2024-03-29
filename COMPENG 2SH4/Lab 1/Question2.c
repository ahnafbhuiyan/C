int question2(){
    int n = -1, input;
    int check = 1000;

    //Asks for a positive integer n until a positive number is given
    while (n<0){
        printf("Input a positive number: ");
        scanf("%d",&n);
    }

    for (int i=0;i<n;i++){
        int remainder = n-i;//Counts down how many more times to ask for an input number

        if (remainder!= 1){//If the number remainder is greater than 1 it prints "numbers" instead of "1 more number"
        printf("Input %d numbers: ", remainder);
        scanf("%d", &input);
        }
        else {//Only for when there is only one more number to input
        printf("Input %d more number: ", remainder);
        scanf("%d",&input);
        }

        //Checks if the new input is smaller than any of the previous inputs
        check = check>input ? input:check;
    }
    printf("The smallest number is: %d\n", check);
}

