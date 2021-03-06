#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "openfile.h"

/*
 * openFile - Helper function for opening files. Returns
 *            FILE if successful otherwise NULL;
 * @file - filename to open
 * @option - enum value for file opening mode
 */
FILE           *
openFile(const char *file, int option)
{
	FILE           *inFile;
	char           *mode = " ";

	switch (option) {
	case APPENDING:
		mode = malloc(strlen("ab") + 1);
		strcpy(mode, "ab");
		break;
	case READING:
		mode = malloc(strlen("rb") + 1);
		strcpy(mode, "rb");
		break;
	case WRITING:
		mode = malloc(strlen("r+b") + 1);
		strcpy(mode, "r+b");
		break;
	default:
		fprintf(stderr, "Invalid file mode operation\n");
		free(mode);
    return NULL;
		break;
	}

	if ((inFile = fopen(file, mode)) == NULL) {
		fprintf(stderr, "Con't open %s; %s.\n", file,
			strerror(errno));
		free(mode);
		return NULL;
	}
	free(mode);
	return inFile;
}
