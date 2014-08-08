#ifndef _OPENFILE_H_
#define _OPENFILE_H_

enum {
    APPENDING,
    READING,
    WRITING
};

FILE *openFile(const char*, int);

#endif
