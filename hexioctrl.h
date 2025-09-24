#ifndef HEXIOCTRL_H
#define HEXIOCTRL_H

#include <string>

#include <tchar.h>
#include <windows.h>
#include <winsvc.h>

using namespace std;

#define ALLOW_IO_OPERATIONS                                                    \
    hwr.StartUp();                                                             \
    hwr.AllowExclusiveAccess();                                                \
    hwr.ShutDown();

#ifndef _MSC_VER
BYTE _inp(WORD port);
BYTE _outp(WORD port, BYTE val);
WORD _inpw(WORD port);
WORD _outpw(WORD port, WORD val);
DWORD _inpd(WORD port);
DWORD _outpd(WORD port, DWORD val);
#endif

class HexIOWrapper {
   public:
    HexIOWrapper();
    virtual ~HexIOWrapper();

    bool StartUp();
    bool ShutDown();
    string GetStatus();

    UCHAR ReadPortUCHAR(USHORT port);
    USHORT ReadPortUSHORT(USHORT port);
    ULONG ReadPortULONG(USHORT port);

    void WritePortUCHAR(USHORT port, UCHAR value);
    void WritePortUSHORT(USHORT port, USHORT value);
    void WritePortULONG(USHORT port, ULONG value);

    bool AllowExclusiveAccess();

   protected:
    HANDLE m_hdriver;
    string m_status;
    TCHAR m_szDriverName[50];
    TCHAR m_szDriverPath[MAX_PATH];

    void CatchError();

    BOOLEAN InstallDriver(SC_HANDLE SchSCManager);

    BOOLEAN
    RemoveDriver(SC_HANDLE SchSCManager);

    BOOLEAN
    StartDriver(SC_HANDLE SchSCManager);

    BOOLEAN
    StopDriver(SC_HANDLE SchSCManager);
};

extern HexIOWrapper hwr;

#endif
