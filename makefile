CC	= gcc
X86	= $(patsubst MINGW%,%,$(MSYSTEM))
CFLAGS	= -g -I../include
LDLIBS	= -lrx$(X86)	
LDFLAGS = -L../lib
DMAIN	= -D__MAIN__
SOURCES	= $(wildcard *.c)
TARGETS	= $(SOURCES:.c=)
OBJS	= $(SOURCES:.c=.o)

LIBRARY	= libext$(X86).a
HEADER	= extlib.h

%-main.o: %.c
	$(CC) -c $(CFLAGS) $(DMAIN) $< -o $@

lib: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar r $@ $(OBJS)

install: $(LIBRARY) $(HEADER)
	cp $(LIBRARY) ../lib
	cp $(HEADER)  ../include

atoc-main: atoc-main.o extract.o
ctoa-main: ctoa-main.o
split-main: split-main.o slist.o count.o
compact-main: compact-main.o 

.PHONY: clean cleanall all

clean:
	$(RM) *.o *~ *.exe

cleanall: clean
	$(RM) *.i *.tm *.out *.shar *.a


