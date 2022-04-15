all: main

# Output file
output = out/AnnoyingMarkdown

ifeq (windows, $(firstword $(MAKECMDGOALS)))
	output = out/AnnoyingMarkdown.exe
endif

# Main file
files = src/main.c

main:
	cc $(files) -o $(output)