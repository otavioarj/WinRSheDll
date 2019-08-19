# WinRSheDll
Windows Reverse Shell DLL

A simple Reverse Shell as a Dynamic-link library, it's based in [this Gist](https://gist.github.com/otavioarj/218ad828b6909345c15bfcf6072b4eb4).
<br>
<br>GCC:<br>
* Don't forget to link using "-shared -lws2_32" and compile with "-DBUILD_DLL"; use "-DDEBUG" for getting a "debug" output :P
