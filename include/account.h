#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

typedef struct
{
    char username[25];
    unsigned char password[SHA_DIGEST_LENGTH];
    char uuid[40];
} account;


#endif
