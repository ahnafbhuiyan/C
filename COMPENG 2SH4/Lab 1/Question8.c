int question8a(){

    int n=-1, reversed= 0, temp;

    while(n<0){
    printf("Enter a positive 7 digit number: ");
    scanf("%d", &n);
    }
    int newN = n;//Makes a new variable to store the value of n
    for (int i= 0;i<7;i++){//Runs the loop 7 times, for a 7 digit number
        if (newN>0){
            temp  = newN%10;//The %10 makes it so the last digit in the current newN is the only number left, because it would be the remainder
            reversed = (reversed+ temp)*10;//Adds the temp value to the reversal and *10 in order to make space for the next digit
            newN = newN/10;// /10 so the code can move onto the next digit in the number

            if (newN==0){//Prevents the code from adding an extra 0 to the reversed number when the inputted number has been completely iterated through already
                reversed = reversed/10;
            }
        }
    }
    printf("The number %d reversed is: %d\n", n, reversed);

}

int question8b(){
    int n=-1;
    double reversed= 0, temp;

    while(n<0){
    printf("Enter a positive number: ");
    scanf("%d", &n);
    }
    int newN = n;
    while(newN!=0){//Runs the loop as long as the inputted value is not 0
        if (newN>0){
            temp  = newN%10;
            reversed = (reversed+ temp)*10;
            newN = newN/10;

            if (newN==0){
                reversed = reversed/10;
            }
        }
    }
    int ans = (int)reversed;
    printf("The number %d reversed is: %d\n", n, ans);

}
