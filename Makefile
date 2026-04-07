# Compiler and Flags
CC = gcc
CFLAGS = -Wall -g

# Target Executable
TARGET = apc

# Source and Object Files
SRCS = main.c function.c
OBJS = $(SRCS:.c=.o)

# Default Rule
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compiling Source Files into Object Files
%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Up command
clean:
	rm -f $(OBJS) $(TARGET)
