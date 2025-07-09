cd C:\Users\student\Desktop\ConsoleApplication1\x64\Debug
task1.exe < 1-input.txt > actual.txt 2>NUL
fc actual.txt 1-output.txt
task1.exe < 2-input.txt > 2actual.txt 2>NUL
fc 2actual.txt 2-output.txt 
pause