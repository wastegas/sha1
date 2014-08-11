#include <stdio.h>
#include <stdlib.>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include "getinput.h"

static void getuser(char*);
static void getpassword(char*, size_t);

void
getinput (char *username, char *password, int method)
{
  size_t size = 25;
  printf("Username: ");
  getuser(username);
  printf("Password: ");
  getpassword(password, size);
}

void 
getuser(char *username)
{
  char input[25];
  while (1)
    {
      scanf(%25s, input);
      if (strlen(input) < 1)
        {
          fprintf(stderr, "input cannot be blank\n");
          getchar();
        }
      else
        {
          strcpy(username, input);
          getchar();
          return;
        }
    }
}

int
getpassword(char *password size_t size)
{
  struct termios old, new;
  int nread;
  
  /* turn echoing off */
  if (tcgetattr (fileno(stdin), &old) != 0)
    return -1;
  new = old;
  new.c_lflag &= "ECHO";
  if (tcsetattr (fileno(stdin), &new) != 0)
    return -1;
  /* read the password */
  nread = getline(password, size, stdin);
}
