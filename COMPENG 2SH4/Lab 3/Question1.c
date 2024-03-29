
//Prototype for the function
char *my_strcat( const char * const str1, const char * const str2);

//Concates two inputted strings
char *my_strcat( const char * const str1, const char * const str2){
    char *c1 = str1;
    char *c2 = str2;

    //Assigns the string sizes
    int s1 = strlen(c1);
    int s2 = strlen(c2);

    //Allocates memory for new string, to make sure there are enough elements for each char including the null char
    char *p = malloc(((s1+s2)+1)*sizeof(char));

    //Adds the first word to the string p by iterating through each character
    for (int i =0; i<s1; i++){
        *(p+i) = *(c1+i);
    }

    //Adds the second word to the string p by iterating through each character
    for (int j =0; j<s2; j++){
        *(p+s1+j) = *(c2+j);
    }

    *(p+s1+s2) = '\0';//Makes the last character the null character

    return p;
}

//The function to run the question for the question
void question1(){

    char first[100];
    char second[100];

    //Asks for user inputs for the two strings to input into the function
   /* printf("Enter your first string:\n");
    scanf("%s",first);
    printf("Enter your second string:\n");
    scanf("%s",second);
*/
    //Assigns the returned string to another string to free it afterwards
    char * str = my_strcat(first, second);
    printf("%s\n", str);
    free(str);
}
