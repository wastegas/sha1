#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "adduser.h"
#include "account.h"
#include "openfile.h"
#include "getinput.h"
#include "generateuuid.h"
#include "generatesha.h"

static void writerecord(account*);

/* adduser - create a new user and save to file
 */
void 
adduser()
{
  char          username[25];
  unsigned char password[SHA_DIGEST_LENGTH];
  char          uuid[40];  
  char          input[25];
  char          stringpassword[25];
  char          *saltedpass = malloc(strlen(stringpassword) + 36);
  account *_a   = malloc(sizeof(*_a));


  getinput(username, stringpassword);
  generate_uuid(uuid);
  saltedpass = concatinate(stringpassword, uuid);
  generate_sha1_hash(saltedpass, password);
  
  strncpy(_a->username, username, 25);
  strncpy(_a->password, password, SHA_DIGEST_LENGTH);
  strncpy(_a->uuid,  uuid, 36);
  _a->uuid[36] = '\0';

  writerecord(_a);
}

void
writerecord(account *_a)
{
  FILE *fp = openFile("user.dat", APPENDING);

  if ((fwrite(_a, sizeof(account), 1, fp)) < 1 )
    {
      fprintf(stderr, "error appending record");
      free(_a);
      fclose(fp);
      exit(EXIT_FAILURE);
    }
  fclose(fp);
}
