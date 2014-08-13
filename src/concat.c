#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "concat.h"

/*
 * concatinate - helper function for concatenating strings
 * @s1 - first string
 * @s2 - second string
 *
 * returns result from concatenated s1 + s2. returns NULL if malloc
 * fails
 */
char *
concatinate(const char *s1, const char *s2)
{
	size_t		len1 = strlen(s1) - 1; // don't include '\0'
	size_t		len2 = strlen(s2) + 1;
	char           *result = malloc(len1 + len2 + 1);
	if (result == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
		  return NULL;
    }
	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);
	return result;
}
