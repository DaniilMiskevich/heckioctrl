# You probably don't need this.

> You only do if you're required to include the `hexiosupp.lib` in yout project and you have trouble building with any decent compiler (obviously not talking about MSVC). This is not a direct replacement though and only some basic features will work.

But if you do, make sure that:
- You use a decent compiler.
- You use at least slightly modern C++.
- You include the patched header file [`hexioctrl.h`](hexioctrl.h) instead of the provided one.
- You build the provided C++ wrapper [`heckioctrl.cpp`](heckioctrl.cpp) with yout project.
- The `HexIO.sys` file (provided with the `hexiosupp.lib`) can be found (only searched for in the CWD).
- The provided DLL [`heckiosupp.dll`](heckiosupp.dll) is placed along with the executable.
