#pragma comment(lib, "hexiosupp.lib")

#include <hexioctrl.h>
#include <intrin.h>
#include <stdio.h>

#define EXPORT extern "C" __declspec(dllexport) 

HexIOWrapper hwr;

EXPORT void freaking_hack() { ALLOW_IO_OPERATIONS; }

EXPORT BYTE read_byte(WORD port) { return _inp(port); }
EXPORT BYTE write_byte(WORD port, BYTE val) { return _outp(port, val); }

EXPORT WORD read_word(WORD port) { return _inpw(port); }
EXPORT WORD write_word(WORD port, WORD val) { return _outpw(port, val); }

EXPORT DWORD read_dword(WORD port) { return _inpd(port); }
EXPORT DWORD write_dword(WORD port, DWORD val) { return _outpd(port, val); }
