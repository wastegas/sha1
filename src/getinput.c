#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include "getinput.h"

static void getuser(char*, size_t);
static size_t getpassword(char**, size_t *);

void
getinput (char *username, char *password)
{
  size_t size = 25;
  printf("Username: ");
  getuser(username, size);
  printf("Password: ");
  getpassword(&password, &size);

}

void 
getuser(char *username, size_t size)
{
  char input[25];
  while (1)
    {
      fgets(input, size, stdin);
      if (strlen(input) < 1)
        {
          fprintf(stderr, "input cannot be blank\n");
          getchar();
        }
      else
        {
          input[strlen(input) -1] = '\0';
          strcpy(username, input);
          return;
        }
    }
}

size_t
getpassword(char **password, size_t *size)
{
  struct termios old, new;
  size_t nread = 0;

  /* turn echoing off */
  if (tcgetattr (fileno(stdin), &old) != 0)
    return -1;
  new = old;
  new.c_lflag &= ~ECHO;
  if (tcsetattr (fileno(stdin), TCSAFLUSH, &new) != 0)
    return -1;
  /* read the password */
  nread = getline(password, size, stdin);
  /* restore terminal */
  (void) tcsetattr(fileno(stdin), TCSAFLUSH, &old);
  return nread;
}
