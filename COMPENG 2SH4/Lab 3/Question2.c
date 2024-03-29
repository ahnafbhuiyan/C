#include <stdio.h> for file I/O

//Defines the structure and all its members
typedef struct student {
    int id;
    char firstName [15];
    char lastName [15];
    int proj1;
    int proj2;
    float finalGrade;

}student;

//Prototypes for all the functions
int find (int idNo, student **list, int size );
void input_grades ( char *filename, student **list, int size );
void comput_final_course_grades (student **list, int size);
void output_final_course_grades (char *filename, student **list, int size);
void print_list( student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);


//Creates the class list which is an array of pointers to the student structures
student **create_class_list( char *filename, int *sizePtr ){

    fscanf(filename,"%d", sizePtr);//Scans for the class size and assigns it to 'sizePtr'

    student **room = malloc (sizeof(student**));//Allocates memory for the array of pointers 'room'

    //Scans the information from the inputted textfile and assigns the appropriate values to the members
    for (int i=0; i<*sizePtr; i++){
        room[i] = calloc(*sizePtr,sizeof(student));//Allocates the memory for the 'student' for each element
        fscanf(filename,"%d", (&room[i]->id));
        fscanf(filename,"%s", (&room[i]->firstName));
        fscanf(filename,"%s", (&room[i]->lastName));
     }

    student **end = room;//Makes sure the beginning of the class list is returned, and not the end

    return end;

}

//Finds the index of the student with the inputted ID number
int find (int idNo, student **list, int size ){
    //Iterates through the classlist to find a matching ID number to the one inputted
    for (int i=0; i<size;i++){
        if (idNo==list[i]->id){
            return i;
        }
    }
    return -1;//Returns -1 if there are no matching ID numbers
}

//Inputs the grades from the inputted file to the project 1 and 2 memebrs of the corresponding student
void input_grades( char *filename, student **list, int size ){
    int temp = 0;
    int place;

    for (int i=0; i<size;i++){
        fscanf(filename,"%d",&temp);//Reads the ID so it can assign the correct grade to the right person
        place = find(temp,list,size);

        //Scans from the input file for the project marks
        int mk1;
        int mk2;
        fscanf(filename,"%d", (&mk1));
        fscanf(filename,"%d", (&mk2));
        if ((mk1<0)){
            mk1=0;
            list[i]->proj1 = mk1;
        }
        else if(mk2<0){
            mk2=0;
            list[i]->proj2 = mk2;
        }
        else{
            list[i]->proj1 = mk1;
            list[i]->proj2 = mk2;
        }

        }
    }


//Finds the average between the two marks for each student
void compute_final_course_grades(student **list, int size){
    int mk1, mk2;
    float final_mk;

    //Iterates through the class list and finds the average for each student
    for(int i =0; i<size;i++){
        mk1 = list[i]->proj1;
        mk2 = list[i]->proj2;
        final_mk = (mk1+ mk2)/ 2.0;
        list[i]->finalGrade = final_mk;//Assigns the computed final grade to the corresponding student
    }
}

//Prints the computed final grades to the inputted text file
void output_final_course_grades (char *filename, student **list, int size){
    fprintf(filename, "%d\n",size);

    for (int i =0; i<size;i++){
        fprintf(filename, "%d %.2f\n", list[i]->id, list[i]->finalGrade);//Rounds the average to two decimal places and prints it into the file
    }
}

//Prints the current student list
void print_list( student **list, int size){

    for (int i=0; i<size; i++){
        printf("ID: %d, name: %s %s, project 1 mark: %d, project 2 mark: %d, final grade: %.2f\n", list[i]->id, list[i] ->firstName, list[i]->lastName, list[i]->proj1, list[i]->proj2, list[i]->finalGrade);
    }
}

//Takes out the student with the inputted ID number from the class list
void withdraw(int idNo, student **list, int *sizePtr){
    int place  = find(idNo,list,*sizePtr);
    int i=0,j=0;

    if(place!=-1){//Makes sure the inputted ID number is on the list
        //Begins at the indexed ID number and shifts all the students after it into the element before that student
        for (place; place<*sizePtr-1;place++){
            //Assigns all the place+1 students members into the previous (place) students members
            list[place]->id = list[place+1]->id;
            //Copies the strings of the first and last names
            strcpy (list[place]->firstName, list[place+1]->firstName);
            strcpy (list[place]->lastName, list[place+1]->lastName);
            list[place]->proj1 = list[place+1]->proj1;
            list[place]->proj2 = list[place+1]->proj2;
            list[place]->finalGrade = list[place+1]->finalGrade;
        }
        free(list[(*sizePtr)-1]);//Frees the allocated memory of the empty student element
        *sizePtr= (*sizePtr)-1;//Changes the number of students left in the class
    }
    else {//If the student is not on the list, it will print this
        printf("That student has already withdrawn or does not exist\n");
    }
}

//Destroys the current list by withdrawing each student
void destroy_list(student **list, int *sizePtr){
    int tempID;

    for (int i=0; i<*sizePtr;i++){
        tempID = list[i] ->id;
        withdraw(tempID,list,sizePtr);
    }

    //Frees the memory of the list and sets the class size to 0
    free(list);
    (*sizePtr)=0;
}

//The function to run the program for the question
void question2(){

    int listSize =0;
    int *sizePtr = &listSize;

    //Opens all the necessary files and sets wether it is for reading or for writing
    char input_File1[] = ("D:\\Desktop\\Coding\\School\\COMPENG2SH4\\Lab 3\\input_file.txt");
    char input_File2[] = ("D:\\Desktop\\Coding\\School\\COMPENG2SH4\\Lab 3\\marks.txt");
    char input_File3[] = ("D:\\Desktop\\Coding\\School\\COMPENG2SH4\\Lab 3\\finalMarks.txt");
    FILE *filename = fopen(input_File1, "r");
    FILE *marks_input = fopen(input_File2, "r");
    FILE *final_out = fopen(input_File3, "w");

    //Creates the class list
    student **part1 = create_class_list(filename, sizePtr);
    //Inputs the grades for each student
    input_grades(marks_input, part1,*sizePtr);
    //Computes the final grades
    compute_final_course_grades(part1,*sizePtr);
    //Prints the final grades into a text file
    output_final_course_grades (final_out, part1, *sizePtr);
    //Prints the current class list
    print_list(part1,*sizePtr);

    //Withdraws with failure
    withdraw(7,part1,sizePtr);
    //Withdraws two students successfully
    withdraw(-5,part1,sizePtr);
    //withdraw(5678,part1,sizePtr);
    //Prints the new class list
    print_list(part1,*sizePtr);


    //Destroys the class list
    printf("Destroyed List: ");
    destroy_list(part1,sizePtr);
    //Prints the empty list to show it is empty
    print_list(part1,*sizePtr);



    //Closes all the files which were opened
    fclose(final_out);
    fclose(marks_input);
    fclose(filename);

}

