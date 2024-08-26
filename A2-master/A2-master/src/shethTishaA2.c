#include "../include/shethTishaA2.h"


/**
This is the first function of the assignment. The main purpose of this function is to read the contents of the file!
The parameters of this file consist of the file name the user wants to read.
This function returns the contents of the file as a string. First, I create
three variables that will help me in completing the requirements of the function.
Next, I open the file in read mode. It checks if the file is empty or does not exist. If so, 
it returns 0 back to the function and prints a corresponding statement.
Then, it goes into a while loop that runs till the not end of file. In there
it checks, if the char * variable I have created is null or not. If it is null, 
then it dynamically allocates one space using malloc. Else, it reallocs space
accordingly to the value of count (number of lines). 
**/

char * readFile(char * filename){

  char * ptr = NULL;
  int count = 0;
  char tempChar;

  //Opens file in read mode
  FILE *fptr = fopen(filename, "r");

  if(fptr == NULL){
    printf("File Not Found! \n");
    return 0;
  }

  //While loop that runs till the end of file
  while(!feof(fptr)){

    fscanf(fptr, "%c", &tempChar);

    //Incrementing count after each line
    count++;

    if(ptr == NULL){
      //Mallocs one space
      ptr = malloc(sizeof(char) * 1);
    }

    else{
     //Reallocs space to the count variable value
     ptr = realloc(ptr, sizeof(char) * count);
    }

    //Assigns the tempChar value to the ptr at index of count - 1.
    ptr[count - 1] = tempChar;

  }// end of while

  //Closes the file
  fclose(fptr);
  
  //Returns the contents of the file
  return ptr;
}

/**
This is the second function. The main purpose of this function is to count the 
number of words and sentences in a file. The parameters of this function consist of 
a char * aString. This variable holds the string. Another parameter is the numWords and 
numSentences variables which are both pointers. Since they are pointers, the 
value of both of them will be printed in the main. First I have created some 
variables that will assist me in making sure the function works the way it is supposed to.
Next, it goes through a for loop, that runs till the length of the string. 
To increment the word counter, I check if the char value at that index
is either a space or a new line. I also check if there is a space or newline in the index before.
This is to ensure that even if the user enters multiple spaces or new lines, the word counter does not keep incrementing. 
Next, in another if statement I check if the value at that index is either 
a !, ., ?, :, or ;. I also check the same for the index before it. This is 
to make sure that the user enters multiple of these characters without
incrementing the sentence counter variable. Once the for loop ends, 
I assign the sentenceCounter and the wordCounter to the numSentences and numWords
variables.
**/


void dejaVu(char * aString, int * numWords, int * numSentences){

  //Variables used to print the number of each in the main
  * numWords = 0;
  * numSentences = 0;

  //Variables to count the number of each
  int wordCount = 0;
  int sentenceCount = 0;

  //For loop to check each character to increase the word counter and sentence counter
  //Runs till the length of the string given in the parameters

  for(int i = 0; i < strlen(aString); i++){

    //If the value at the index is a space or newline AND it is not a space or newline
    //for the value at the index prior, the contents in this if statement execute

    if((aString[i] == ' ' || aString[i] == '\n') && (aString[i- 1] != '\n' && aString[i -1] != ' ')){
      wordCount++;
    }

  //Checks to see if the string value is any punctuation and if the string at the prior index is not. If this is true
  //it executes

    else if((aString[i] == '!' || aString[i] == '.' || aString[i] == ':' || aString[i] == ';' || aString[i] == '?')
            && (aString[i -1] != '!' &&  aString[i -1] != '.' && aString[i -1] != ':' && aString[i - 1] != ';' && aString[i - 1] != '?')){
      sentenceCount++;
    }
  }

  //Once for loop ends, the wordCount and sentenceCount values are assigned to
  //appropriate variables.

  *numWords = wordCount;
  *numSentences = sentenceCount;
}


/**
This is the third function. The main purpose of this function is to create a string based
on the number the user enters for each character of the string. It enlarges the string
or keeps it at the same length.The parameter of this function consist of a a string 
that is entered by the user in the main. First, I ahve created variables and 
arrays to help me get the desired output. Next, I go into a for loop that runs
till the length of the string. This for loop will ask the user to enter a number
for each character of the string. I have a while loop inside this function
to make sure that the user does not input any invalid choices. If they do, then
the user is asked again and again until the input is valid values. Each value that they
input is stored into a tempArray which has the size of the length of the string.
Next, I have a nested for loop the outer loop runs until the length of the string
and the inner loop runs until the tempArray index value. In the nested for loop, 
there is a if statement that checks to see if ptr is NULL. If so, it dynamically 
allocates, space for it using calloc. If not, it reallocs space for it based on the value of count. 
In both these statements, ptr[indexValue] is stored with the character, while 
also incrementing count and indexCounter by 1 each time. Finally, ptr is returned
back to the calling program. 
**/

char * goBig(char * aString){

  int tempArray[strlen(aString)];
  int counter = 0;
  char * ptr = NULL;
  int check = 0;


  //Only used to ask the user for input as long as the length of the string
  for(int i = 0; i < strlen(aString); i++){
    tempArray[i] = 0;

  //Makes sure 0 and any value less than 0 is not entered
    while(tempArray[i] == 0 || tempArray[i] < 0){
      printf("Please enter a number: ");
      scanf("%d", &tempArray[i]);
    }
    
    check++;
    counter += tempArray[i];

  }

  int count = 0;
  int indexCounter = 0;

  //Runs for each character (outside) and the inside for loop 
  //runs till the user entered value for each character
  for(int i = 0; i < strlen(aString); i++){
    for(int j = 0; j < tempArray[i]; j++){
      if(ptr == NULL){
        count++;
        ptr=calloc(count, sizeof(char));

       //Assigns the character value to this index of ptr
        ptr[indexCounter] = aString[i];
        indexCounter++;
      }
      else{
        count++;
        ptr = realloc(ptr, sizeof(char) * count);

       //Assigns the character value to this index of ptr
        ptr[indexCounter] = aString[i];
        indexCounter++;
      }
    }

  }

  //Returns ptr back to main or the calling program
  return ptr;
}


/**
This is the fourth function. The main purpose of this function is to split
each word using a 2D array. The paramters of this function consist of 
a string inputted by the uer and the a integer pointer variable 
that holds the number of words returned which is printed in the main. First, 
I have initialized variables that will assist me in getting the required output.
Next, I have a while loop that runs until the string length of the parameter aString.
In this while loop, I have a if statement that checks if the ptr value is NULL. 
It will be in the first case and will calloc 1 space. Else if, the value at that 
index is a space or a newline. If so, it goes into the inner if statement to check 
if there is a space or newline in the index prior or not. If not, it reallocs space 
for the value of wordCount + 1. It also, increments the  wordCount variable by 1 and charCount variable by 1. Next, I have another if statement
that checks if the value at that specific index is a space or a newline. If it is not, 
it checks the value of ptr. If the value of ptr is null, it callocs space, else it reallocs space to charCount + 2.
In both these instance, the word at that specific index is assigned to the 
2D array after both ther conditions are checked.
Finally, the i value is incremented by 1, assigns the value of wordCount to numWordsReturned and finally, ptr is returned to the calling program. 
**/

char ** goAway(char * aString, int * numWordsReturned){

  char ** ptr = NULL;
  int wordCount = 0;
  int i = 0;
  int charCount = 0;
  int stringLength = strlen(aString);

  while(i < stringLength){
    if(ptr == NULL){
      ptr = calloc(1, sizeof(char*));
    }

   //Helps find the value of word count 
    else if((aString[i] == ' ' || aString[i] == '\n')){
      if((aString[i-1] != ' ' && aString[i -1] != '\n')){
        wordCount++;
        ptr = realloc(ptr, sizeof(char*)*(wordCount+1));
        charCount = 0;
      }
    }

    //Runs only if there is not a word there
    if((aString[i] != ' ') && (aString[i] != '\n')){
      if(ptr[wordCount] == NULL){
        ptr[wordCount] = calloc(1, sizeof(char));
      }

      else{
        ptr[wordCount] = realloc(ptr[wordCount], sizeof(char) * (charCount + 2));
      }

     //Assign the word to this 2D array
      ptr[wordCount][charCount] = aString[i];
      charCount++;
    }

  //incrementing the i value by one to run through each word
  i++;
  }

  //Value of wordCount is assigned to this vairable so it can be printed in the main
  *numWordsReturned = wordCount;

  //Returned back to the calling program
  return ptr;
}


/**
This is the fifth function. The main purpose of this function is to take the string
inputted by the user and remove all the punctuation from it and print it back 
for the user. The parameter of this function are a string inputted by the user. 
First, I have created multiple variables that will help run the function the way
it is supposed. Nex, I have a for loop that runs till the length of the string.
In this for loop, I check if the value of ptr is NULL. If it is, 
it checks to see if the value at aString[i] is a punctuation. 
If it is not, then the if statement block executes. First, it callocs one space.
Then, it assigns the value to ptr[count] and increments count by 1.
Next, an else statements executes if the value of ptr is not NULL.
In this else loop, it again checks to see if the value at the index is a punctuation.
If it is not, then, space is realloced of i * 1. Next, the character is assigned
to ptr[count] and increments count by 1. 
Lastly, I have ptr[count] = '\0' as it sometimes added random characters. This 
ensures it does not add random characters once the string ends. Finally,
the ptr is returned back to the calling program. 
**/

char * breathless(char * aString){

  char * ptr = NULL;
  int count = 0;

  //For loop that runs till the length of the string 
  //This is where the punctuation is checked and space is allocated dynamically.
  for(int i = 0; i < strlen(aString); i++){
   //Only runs if ptr is NULL (the first iteration)
    if(ptr == NULL){
      //If the index character is not punctuation, this block executes.
      if(aString[i]  != '.' && aString[i] != '!' && aString[i] != ':' && aString[i] != ';'  && aString[i] != '?'){

       //Calloced space for one character
        ptr = calloc(1, sizeof(char));

        //Character at that index is assigned to ptr[count]
        ptr[count] = aString[i];

        //Count is incremented
        count++;
      }
    }

    //Runs when ptr is not NULL
    else{

      //If the character value at that idex is not punctuation, it executes
      if(aString[i]  != '.' && aString[i] != '!' && aString[i] != ':' && aString[i] != ';'  && aString[i] != '?'){
        //Realloces space for one + the value of i
        ptr = realloc(ptr, sizeof(char) * (i + 1));
        //Character is assigned to ptr[count]
        ptr[count] = aString[i];
        //Count is incremented
        count++;
      }
    }
  }

//Assures random characters are not added in the end of the string
ptr[count] = '\0';

//Returns back to the calling program
return ptr;
}

/**
This is the last function. The main purpose of this function is to add a 
specific chracter to the chosen suffix. These characters are chosen based
on the position chosen by the user. The parameters of this function consist
of a string based on the user input, a integer variable whichWord that 
is chosen by the user and lastly a desired suffix also chosen by the user.
First, I have created various variables that will help me in getting the desired
output. Then, I call the 4th function to get the specific word the user entered.
Next, I call the fifth function to make sure there is no punctuation in the word chosen.
Finally, I go through a for loop that runs till the length og the string.
In this for loop, I print the character of the word at that index with the suffix (no spaces). 
**/

void tail(char * aString, int whichWord, char * desiredSuffix){

  char ** ptr = NULL;
  int numWords = 0;
  char * sptr = NULL;
  int numberChecker = 0;
  int sentenceChecker = 0;

  dejaVu(aString, &numberChecker, &sentenceChecker);

  while(whichWord < 1 || whichWord > numberChecker){
    printf("Sorry, the position you entered does not fit the range!\n");
    printf("Enter your desired position: ");
    scanf("%d", &whichWord);
  }

  ptr = goAway(aString, &numWords);
  sptr = breathless(ptr[whichWord - 1]);

  for(int i = 0; i < strlen(sptr); i++){
    printf("%c%s\n", sptr[i], desiredSuffix);
  }


}

