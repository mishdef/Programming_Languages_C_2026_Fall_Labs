
#include <stdio.h>

int main(int argc, char *argv[]) {
  // check if provided enough arguments (name and age)
  if (argc < 3) {
    printf("Usage: %s <name> <age>\n", argv[0]);
    return 1;
  }


  // EXPLANATION: Outputing arguments in right format (dont touch argv[0] its filepath)
  // BTW, arguments come in 'string' format, so when i first added %d to age, i got confused.
  // For now (for this lab) it's not nessesary to convert string to actual number so i didn't do it :)
  printf("Hello, %s! And your age is %s.\n", argv[1], argv[2]);
  
  
  //read char  before exit. to prevent closing before seeing the result
  char dummy;
  scanf("%c", &dummy);
  return 0;
}
