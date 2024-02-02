#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Chars = c, Arrow = a) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      printf("You selected chars.\n");
      printf("Choose which font you want 11x16(e) or 5x7 (f).\n");
      char c2;
      scanf(" %c",&c2);
      if(c2 == 'e'){
	for (char c = 'A'; c < 'D'; c++)
	  print_char_11x16(c);
      }
      if(c2 == 'f'){
	for(char c = 'A';c<'D';c++)
	  print_char_5x7(c);
      }
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    case 'a':
      puts("You selected arrow:");
      print_triangle(5,7);
      print_square(10,5);
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
