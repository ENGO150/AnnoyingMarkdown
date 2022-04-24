Remove-Item out/* -Recurse

echo "Using 'gcc' as default compiler."
echo "Compiling..."

gcc src/main.c -o out/annoyingmarkdown_windows.exe
