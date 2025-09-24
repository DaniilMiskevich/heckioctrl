# You probably don't need this.

> You only do if you're required to include the `hexiosupp.lib` in yout project and you have trouble building with any decent compiler (obviously not talking about MSVC). This is not a direct replacement though and only some basic features will work.

But if you do, make sure that:
- You use a decent compiler.
- You use at least slightly modern C++.
- You include the patched header file [`hexioctrl.h`](hexioctrl.h) instead of the provided one.
- You build the provided C++ wrapper [`heckioctrl.cpp`](heckioctrl.cpp) with yout project.
- The `HexIO.sys` file (provided with the `hexiosupp.lib`) can be found (only searched for in the CWD).
- The provided DLL [`heckiosupp.dll`](heckiosupp.dll) is placed along with the executable.
- You're running it on **Windows XP** or lower. It relies on `_inp` and friends that were deprecated at some point and will crash on any modern Windows version. 
- You have either Visual Studio 2008 or [redistributables](https://download.microsoft.com/download/5/d/8/5d8c65cb-c849-4025-8e95-c3966cafd8ae/vcredist_x86.exe) installed.

Everything works on my machine (latest at the time `i686-w64-mingw32-gcc` compiler, Windows XP x86 on VirtualBox).


## Build it yourself (really?)

If you actually want it, you can. Just get the [vs_project](vs_project) and build it with the Visual Studio 2008. You'll need to add the patched [`hexioctrl.h`](hexioctrl.h) and add the provided `hexiosupp.lib` into the project.
