#include <stdio.h>

int main() {

  // Variables used in Chapter 1
  // Variable n stores the input integer from standard input
  int n = 0;

  // Variable c stores potential character following the input integer used for
  // validation
  char c = '\0';

  // Macro EOF is a safe way to test end of file
  int return_value = EOF;

  // Variables used in Chapter 2
  // char* s = "\0"; // s cannot be modified
  char s[] = "\0"; // s can be modified

  // Chapter 1 causes infinite loop
  printf("\n\n");
  printf("=======================================\n");
  printf("Chapter 1  scanf() causes infinite loop\n");
  printf("=======================================\n\n");

  printf("This program can test if your input integer is valid.\n");
  while ('\n' != c) {
    printf("Try input an integer: ");
    return_value = scanf("%d%c", &n, &c);

    // scanf("%d%c", &n, &c); returns
    //   .  0 on getting no integer input nor character input
    //   .  1 on getting an integer input
    //   .  2 on getting an integer and a character input
    if (0 == return_value) {
      printf("I'm afraid that your input is not valid :-(\n");
      printf("You can try again~\n");

      // Consume the standard input buffer modified by scanf()
      printf("Now we're gonna clean up the stdin buffer...\n");
      while ('\n' != getchar()) {
      }
      printf("Alright, now the stdin buffer has been cleaned up...\n\n");

    } else if (1 == return_value) {
      // Return value would never be 1 though

    } else if (2 == return_value) {
      if ('\n' != c) { // c is not new line character
        printf("I'm afraid that your input is not valid :-(\n");
        printf("You can try again~\n");

        // Consume the standard input buffer modified by scanf()
        printf("Now we're gonna clean up the stdin buffer...\n");
        while ('\n' != getchar()) {
        }
        printf("Alright, now the stdin buffer has been cleaned up...\n\n");
      } else { // c is new line character
      }
    }
  }

  printf("Roger that, your input integer is valid and its value is %d.\n", n);
  printf("End of Chapter 1 :-)\n\n");

  // Chapter 2 char* s or char s[]
  //   .  char* s = "Hello"; and s cannot be modified;
  //   .  char s[] = "Hello"; and s can be modified.
  printf("==============================\n");
  printf("Chapter 2  char* s or char s[]\n");
  printf("==============================\n\n");
  printf("Oh wait a minute...\n\n");
  printf("Please input a character string: ");
  scanf("%s", s);
  printf("Alright, your input char string is \"%s\"\n\n", s);
  printf("End of Chapter 2 :-)\n\n");
  printf("Now we're gonna terminating the program...\n");
  printf("Goodbye~~\n\n");
  return 0;
}
