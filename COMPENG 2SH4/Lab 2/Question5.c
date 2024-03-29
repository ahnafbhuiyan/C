void string_copy(const char source[], char destination[], int n);
int stringLength(char source[]);
int size;
int sizeChar;


stringLength(char source[]){//Finds the length of the source array by counting until the '\0' is reached
    int i=0;
    while (source[i]!= '\0'){
        i++;
    }
    return i;
}
string_copy(const char source[], char destination[], int n){//Copies the string 'source' on to 'destination'
    size = n-1;//Sets the size as n-1 so to include the null value
    sizeChar = stringLength(source);//Calls the 'stringLength'

    for (int i=0; i<n; i++){//Copies the characters from 'source' onto new array 'destination'
        destination[i] = source[i];
       }
    //Compares the sizes of the two arrays in order to decide where to put the null value
    if (sizeChar<= size){
       destination[sizeChar+1] = '\0';
    }
    else if (sizeChar>n){
        destination[n+1] = '\0';
    }

    //Prints the characters stored within the 'destination' array
    for (int i=0; i<n; i++){
        printf("%c",destination[i]);
    }
}
