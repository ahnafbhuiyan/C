int question6(){
    int count = 0;

    for (int side1 = 1;side1 <= 400;side1++){//The loop for side 1
        for (int side2 = 1;side2 <= 400;side2++){//The loop for side 2
            for(int hyp = 1;hyp <= 400;hyp++){//The loop for the hypotenuse
                int hypTest = hyp * hyp;//Finds the hypotenuse

                //Finds the hypotenuse using the sides
                int side1Squared = side1 * side1;
                int side2Squared = side2 * side2;
                int squaredSum = side2Squared + side1Squared;

                //Checks if the two hypotenuses are equal and adds to the counter if it is
                if (side1<=side2 && squaredSum == hypTest){//Checks if the previously calculated hypotenuse are equal
                    printf("Side 1: %d\nSide 2: %d\nHypotenuse: %d\n", side1, side2, hypTest);
                    count++;//Counts how many triples there are in total
                }


            }

        }
    }
    printf("The total number of Pythagorean Triples are: %d\n",count);

}
