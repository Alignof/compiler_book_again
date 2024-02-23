CFLAGS=-std=c11 -g -static -Wall

SOURCES := $(wildcard ./src/*.c)
INCLUDE = -I./include/
TARGET  := ./cc_sakura2
SRCDIR  := ./src
OBJDIR  := ./src/obj
OBJECTS := $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	@[ -d $(OBJDIR) ]
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

install: $(OBJECTS)
	$(CC) -O2 -o $(TARGET) $^ $(LDFLAGS)

test: $(TARGET)
	./test.sh $(TARGET_ARCH)

clean:
	rm -f cc_sakura *.o *.s *~ tmp* *.txt *.out child* gen*
	rm -f $(OBJECTS) $(TARGET)

fmt:
	clang-format -i src/*.c

.PHONY: test clean install fmt
