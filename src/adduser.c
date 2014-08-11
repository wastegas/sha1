#include <stdio.h>
#include <errno.h>
#include "adduser.h"
#include "account.h"
#include "openfile.h"
#include "getinput.h"

/* adduser - create a new user and save to file
 */
void 
adduser(struct account*)
{
  char          username[25];
  unsigned char password[SHA_DIGEST_LENGTH];
  char          uuid[40];  
  char          input[25];
  char          stringpassword[25];
  char          *saltedpass = malloc(strlen(stringpassword) + 36);

  getinput(username, stringpassword, ADD);
  generateuuid(uuid);
  saltedpass = concatinate(stringpassword, uuid);
  generate_sha1_hash(saltedpassword, password);
}
