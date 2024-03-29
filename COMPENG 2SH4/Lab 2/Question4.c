void letter_freq(const char word[], int freq []);

letter_freq(const char word[], int freq[]){
    int size  = sizeof(word)+1;
    int asc,letter;

    for (int i=0; i<size; i++){
        asc = word[i];

        if (asc>=97 && asc<=122){//Checks if lowercase using the ASCII values
                letter = asc- 97;//Subtracts 97 because that is the ASCII value of 'a', and therefore returns a value which is between 1-26
                freq[letter]++;//Increases the number of the current indexed letter by 1

        }
        else if (asc>=65 && asc<=90){//Checks if uppercase using the ASCII values
                letter = asc-65;//Subtracts 65 because that is the ASCII value of 'A', and therefore returns a value which is between 1-26
                freq[letter]++;//Increases the number of the current indexed letter by 1
            }

        }

    int size2 = sizeof(freq);
    int low = 97;
    int up = 65;
    for (int i =0; i< 26; i++){
            printf("The count of '%c' and '%c' is: %d\n", low, up, freq[i]);
            //Counts the ASCII values to print them
            low++;
            up++;

    }

    }
