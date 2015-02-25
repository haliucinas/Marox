# The C and C++ rules are already setup by default.

SOURCES += $(patsubst %.s, %.o, $(wildcard src/*.s))
SOURCES += $(patsubst %.c, %.o, $(wildcard src/*.c))
SOURCES += $(patsubst %.c, %.o, $(wildcard src/include/*.c))
SOURCES += $(patsubst %.c, %.o, $(wildcard src/lib/*.c))

CFLAGS = -nostdlib -nostdinc -fno-builtin -fno-stack-protector -std=c11 -m32 -O2
CFLAGS += -I. -I./include -I./lib
LDFLAGS = -TLink.ld -melf_i386
ASFLAGS = -felf

all: $(SOURCES) link 

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	yasm $(ASFLAGS) $< -o $@

clean:
	find . -name '*.o' | xargs rm -f
	rm -f kernel