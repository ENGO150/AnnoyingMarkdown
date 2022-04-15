all: main

# Output file
output = out/AnnoyingMarkdown

# Main file
files = src/main.c

main:
	cc $(files) -o $(output)