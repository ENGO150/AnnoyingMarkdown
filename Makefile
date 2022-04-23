all: main

# Output file
output = out/annoyingmarkdown
outputWin = out/AnnoyingMarkdown.exe
outputMac = out/AnnoyingMarkdown_MacOS

# Main file
files = src/main.c

main:
	cc $(files) -o $(output)

windows:
	gcc $(files) -o $(outputWin)

mac:
	gcc $(files) -o $(outputMac)
