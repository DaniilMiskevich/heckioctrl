#include <stdexcept>

#include <hexioctrl.h>

static FARPROC heckiosupp_fn(char const *const name) {
    static auto const hInst = LoadLibraryA("heckiosupp.dll");
    if (!hInst)
        throw std::runtime_error(
            "Could not open DLL (" + std::to_string(GetLastError()) + ")."
        );
    auto const fn = GetProcAddress(hInst, name);
    if (!fn)
        throw std::runtime_error(
            "There's no `" + std::string(name) + "` function in the DLL!!!"
        );
    return fn;
}

BYTE _inp(WORD port) {
    static auto const fn = (BYTE (*)(WORD))heckiosupp_fn("read_byte");
    return fn(port);
}
BYTE _outp(WORD port, BYTE val) {
    static auto const fn = (BYTE (*)(WORD, BYTE))heckiosupp_fn("write_byte");
    return fn(port, val);
}
WORD _inpw(WORD port) {
    static auto const fn = (WORD (*)(WORD))heckiosupp_fn("read_word");
    return fn(port);
}
WORD _outpw(WORD port, WORD val) {
    static auto const fn = (WORD (*)(WORD, WORD))heckiosupp_fn("write_word");
    return fn(port, val);
}
DWORD _inpd(WORD port) {
    static auto const fn = (DWORD (*)(WORD))heckiosupp_fn("read_dword");
    return fn(port);
}
DWORD _outpd(WORD port, DWORD val) {
    static auto const fn = (DWORD (*)(WORD, DWORD))heckiosupp_fn("write_dword");
    return fn(port, val);
}

HexIOWrapper::HexIOWrapper() {}
HexIOWrapper::~HexIOWrapper() {}

bool HexIOWrapper::StartUp() { return true; }
bool HexIOWrapper::ShutDown() { return true; }

bool HexIOWrapper::AllowExclusiveAccess() {
    static auto const fn = heckiosupp_fn("freaking_hack");
    return fn(), true;
}

BYTE HexIOWrapper::ReadPortUCHAR(WORD port) { return _inp(port); }
void HexIOWrapper::WritePortUCHAR(WORD port, BYTE val) { _outp(port, val); }
WORD HexIOWrapper::ReadPortUSHORT(WORD port) { return _inpw(port); }
void HexIOWrapper::WritePortUSHORT(WORD port, WORD val) { _outpw(port, val); }
DWORD HexIOWrapper::ReadPortULONG(WORD port) { return _inpd(port); }
void HexIOWrapper::WritePortULONG(WORD port, DWORD val) { _outpd(port, val); }

HexIOWrapper hwr;
