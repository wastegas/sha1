CC=	gcc
INCLUDES=	-I./include
CFLAGS=	-std=c11	`pkg-config --cflags glib-2.0`	\
			-Wall	-O3	-g	$(INCLUDES)
LDFLAGS=	-dynamiclib	`pkg-config --libs glib-2.0`	-lcrypto
LFLAGS=	-L./build/lib
LIBS=	-lacct	
OBJDIR=./obj
SDIR=./src
BUILDDIR=./build/bin
TARGET=$(BUILDDIR)/account
LTARGET=./build/lib/libacct
vpath	%.c	./src
vpath	%.h	./include

$(TARGET):	$(SDIR)/main.c	$(LTARGET).dylib
	$(CC)	$(CFLAGS)	$(OBJS)	-o	$@	$^	$(INCLUDES)	$(LFLAGS)	$(LIBS)

_LOBJ=	\
		adduser.o	\
		concat.o	\
		getinput.o	\
		openfile.o	\
		generatesha.o	\
		generateuuid.o

LOBJ=	$(patsubst	%,$(OBJDIR)/%,$(_LOBJ))

$(OBJDIR)/%.o: $(SDIR)/%.c
	$(CC)	$(CFLAGS)	-c	-fPIC	-o	$@	$<	$(INCLUDES)

$(LTARGET).dylib:	$(LOBJ)
	$(CC)	$(CFLAGS)	$(LDFLAGS)	-o	$@	$^	$(INCLUDES)	-lm

clean:
	rm	-rf	$(OBJDIR)/*	$(BUILDDIR)/*
