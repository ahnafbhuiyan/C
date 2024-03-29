#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

double array[5] = {1,2,3,4,5};
double array2[5] = {1,2,3,4,5};
double array3[5];
int d_3array[4][4] = {
    {10,1,3,2},
    {1,30,1,1},
    {1,8,40,0},
    {1,1,30,1900}
    };
char word[] = "hE,lLo";
char dest[] = "hi";
int freq[26];
int vector [] = {0,0,23,0,-7,0,0,48, 2,9};
int source[];
int val[] = {0};
int pos[]={0};
int val1[] = {23, -7, 48,2,9};
int pos1[] = {2,4,7,8,9};

int main()
{
    int on=1;
    while (on==1){
        int question;
        printf("\nWhich question would you like?");
        scanf("%d", &question);

        if (question==1){
            printf("Array components\n");
            print_vector(array,5);
            printf("Array2 components\n");
            print_vector(array2,5);

            add_vectors(array,array2,array3,5);

            double prod = scalar_prod(array,array2,5);
            printf("The product is: %lf\n", prod);

            double norm = norm2(array,5);
            printf("The norm is: %lf\n",norm);
        }
        else if(question==2){
            printf("Question 2\n");
            int question2 = is_diag_dom(d_3array);
            printf("Check: %d\n",question2);
        }
        else if(question==3){
            printf("Question 3\n");
            question3(d_3array);
        }
        else if(question==4){
            printf("Question 4\n");
            letter_freq(word, freq);
        }
        else if(question==5){
            printf("Question 5\n");
            string_copy(word, dest,2);
        }
        else if (question==6){
            printf("Question 6\n");
            efficient(vector,val, pos, 10);
            reconstruct(source,10, val1, pos1,5);
        }
        else if (question==0){
            on=0;
        }
    }
return 0;
}
