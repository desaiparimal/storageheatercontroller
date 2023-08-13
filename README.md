# storageheatercontroller
How to build

Used vscode to write,build,run and test the c code
Used pthread library available with GNU gcc posix standarad toolchain with 
c11 library.

Used below command to build

/usr/bin/gcc -fdiagnostics-color=always -g -Wall -std=c11 
    /Users/pdesai/Downloads/SectionC/threads/*.c -o 
    /Users/pdesai/Downloads/SectionC/threads/main

tested with below gcc version
pdesai@Parimals-MacBook-Pro cotronix % gcc -v
Apple clang version 14.0.3 (clang-1403.0.22.14.1)
Target: x86_64-apple-darwin22.5.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

Program:
When running code main thred will spawn first pollstdin thread
    asking to either enter 48characters having only 0's and 1's
    and then press enter,if any mistake in entering program will ask to enter
    it correct string.
Upon correct string will spawn timer thread and spawn new pollstdin thread
    and poll for new string to be entered at the same time timer thread start
    displaying either heater is ON or OFF and count for 30 minutes to leave in
    either state.

If user enters another string then tRunning will be set , stops and exit the
    timer thread alredy running by setting tRunning = 1. Spawning another 
    timer thread with updated string data.

Pressing ctrl+d will exit the program safely.

Assumming string is reading from left to write.

Can be extended by user enterning how many minutes needed for the heater to be
    on or off.
