OUTPUT = guide
SRC = main.c

# --------------------------------------------------------------------------------------------------

CC := gcc

# --------------------------------------------------------------------------------------------------

all:
	$(CC) $(SRC) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

.PHONY: all
