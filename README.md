# stdin logger for Windows

Simple Windows tool that writes what comes in from the stdin to a log file.

Can be used for example to debug and reverse engineer programs that launch other binaries and hand out the configurations and settings through standard stream.


## Example use case

Say you have an application that uses openvpn. The app launches the openvpn with `--config stdin` options and then feeds the openvpn configuration through the standard stream. Using the ordinary Windows tools it is rather challenging to find out the configuration openvpn will be using.

To extract the configs, you simply rename the stdinLogger.exe to openvpn.exe, and replace the original openvpn.exe with the renamed logger. When the application launches the openvpn all the configs sent through stdin are stored into `openvpn.exe.stdinLog.txt`.


## Building

If you're using GNU GCC Compiler then this should do the trick:
```
mingw32-gcc.exe -Wall -O2 -c main.c -o main.o
mingw32-g++.exe -o stdinLogger.exe main.o -s  
```



