#Make file adapted from https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
#


CC := gcc 
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
TESTDIR := test
BUILDDIR := build
BINDIR := bin
TESTRUNNER := bin/test_runner
TARGET := bin/runner
WFIND := C:\cygwin64\bin\find

SRCEXT := c
ifeq ($(OS),Windows_NT)
	SOURCES := $(shell $(WFIND) $(SRCDIR) -type f -name *.$(SRCEXT))
else
	SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
endif

OBJECTS := $(patsubst ,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
#LIB := 
INC := -I include
$(TESTRUNNER): $(OBJECTS)
	@echo " Linking...";
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(TESTDIR)/%.$(SRCEXT) clean
	@mkdir -p $(BUILDDIR);
	@echo "compiling the source files"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

run:
	./$(TARGET)
	
clean:
	@echo " Cleaning..."; 
	$(RM) -r $(BUILDDIR) $(TARGET) $(BINDIR)

.PHONY: clean