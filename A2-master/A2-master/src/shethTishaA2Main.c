/**
I have included my header file so that everything runs smoothly.
**/

#include "../include/shethTishaA2.h"

/**
In my main, instead of the brackets holding "void", I am using int argc and char * argv[1].
This is because, I will be working with files, thus any file that the user enters after a.out will be used to run.
**/

int main(int argc, char * argv[1]){

/**
These are all the variables I am using in my code. I have initialized and declared them 
in the start for easier reading purposes!
**/

  char * func1;
  int numWords = 0;
  int numSentences = 0;
  char * func2;
  char aString[MAX_STR];
  char * func3;
  char ** sptr = NULL;
  int numWordsReturned = 0;
  char aString1[MAX_STR];
  char * func5;
  char aString2[MAX_STR];
  char * func6;
  int whichWord = 0;
  char desiredSuffix[MAX_STR];
 
/**
I am calling my function one in this block of code. First using the variable func1
I am going to be reading the file located at the position 1 when executing.
I will be doing this by calling the function readFile. Everything will be stored
in the func1 variable and printed on to the screen. 
As I am dynamically allocating space, I am freeing my variable once everything executes.
**/


  func1 = readFile(argv[1]);

  printf("%s\n", func1);

  free(func1);

/**
This block of code is for function two. I am first calling the first function
to read all the content from the file itself.
Then I am calling the second function with the arguments func2, this holds the contents of the file,
and pointers to numWords and numSentences. Once the function is called, 
I am printing the number of words and sentences in that file! 
**/

  func2 = readFile(argv[1]);

  dejaVu(func2, &numWords, &numSentences);

  printf("Number of words: %d \n", numWords);

  printf("Number of sentences: %d \n", numSentences);

  printf("\n");

/**
This block of code is for the third function. First it prompts the user to enter a string. 
Then, it adds a null space for one index value less than the length of the string.
Next, it calls the third function using aString as the argument. Finally,
I print all the required information that is obtained from the function itself.
Finally, since I used dynamic allocation, I free the func3 variable to avoid memory leaks.
**/

  printf("Enter a string: ");

  fgets(aString,MAX_STR,stdin);

  aString[strlen(aString) -1] = '\0';

  func3 = goBig(aString);

  printf("Your new string: %s\n", func3);

  free(func3);

  printf("\n");

/**
This block of code is for function 4. First, I ask the user to enter a string,
next using sptr, I call the fourth function with the arguments of the string
inputted by the user and the numWordsReturned pointer variable. Finally, 
I print both the contents of the sptr variable using a for loop and the 
value of the numWordsReturned variable. Like always, since I used 
dynamic memory allocation, I free the space that the variable sptr holds.
**/


  printf("Enter a string: ");

  getchar();

  fgets(aString1,MAX_STR,stdin);

  sptr = goAway(aString1, &numWordsReturned);

  for(int i=0;i<numWordsReturned;i++){
    printf("\n%s",sptr[i]);
  }

  printf("\n");

  printf("Number of words: %d\n", numWordsReturned);
  
  free(sptr);

  printf("\n");

/**
This block of code is for function 5. First, I ask the user to enter a string
and use fgets as the user can enter spaces. Next, I call the function 5 using
the string inputted by the user as the argument. Finally I print the contents
of the func5 variable which holds whatever is returned from the function and print
it onto the screen along with freeing space. 
**/

  printf("Enter a string: ");

  fgets(aString2, MAX_STR, stdin);

  func5 = breathless(aString2);

  printf("Your input without punctuation: %s\n", func5); 

  free(func5);

  printf("\n");

/**
Finally, this block of code is for function 6. First I assign the contents
of the file itself to the func6 variable by calling the readFile function.
Then, I ask the user to enter a suffix of their choice with the position of their choice.
This is so it will combine the suffix with each letter of the word at that position.
Finally, I call the 6th function and pass func6, whichWord and desiredSuffix as the arguments. 
**/

  func6 = readFile(argv[1]);

  printf("Please enter your desired suffix: ");

  scanf("%s", desiredSuffix);

  printf("\n");

  printf("Please enter your position: ");

  scanf("%d", &whichWord);

  tail(func6, whichWord, desiredSuffix);

  printf("\n");

  return 0;
}
