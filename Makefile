all: main

# Output file
output = out/AnnoyingMarkdown
outputWin = out/AnnoyingMarkdown.exe

# Main file
files = src/main.c

main:
	cc $(files) -o $(output)

windows:
	gcc $(files) -o $(outputWin)