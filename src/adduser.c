#include <stdio.h>
#include <errno.h>
#include "adduser.h"
#include "account.h"
#include "openfile.h"

void 
adduser(struct account*)
{
  char          username[25];
  unsigned char password[SHA_DIGEST_LENGTH];
  char          uuid[40];  

}
