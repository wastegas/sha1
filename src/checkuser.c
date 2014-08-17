#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "checkuser.h"
#include "account.h"
#include "openfile.h"

bool
checkuser(char *username)
{
  int found = 0;
  account *_a = malloc(sizeof(*_a));
  if (_a = NULL)
    {
      fprintf(stderr,"%s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  FILE *fp = openFile("user.dat", READING);

  while (fread(_a, sizeof(account), 1, fp))
    {
      if (strcmp(_a->username, username) == 0)
        {
          found = 1;
          break;
        }
    }

  fclose(fp);
  free(_a);

  if (found)
    return true;
  else
    return false;
}
