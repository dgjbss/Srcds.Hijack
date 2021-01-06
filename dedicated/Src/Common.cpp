/*
 * Common.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: FearLose
 */

#include "Stdafx.hpp"

// Target handle
HMODULE _hModule = 0;

DLL_EXPORT_CPP __declspec(naked) DWORD __stdcall CreateInterface(  )
{
    GetProcAddress(_hModule, "CreateInterface");
    __asm__ ("jmp *%eax");
    return TRUE;
}

DLL_EXPORT_CPP __declspec(naked) DWORD __stdcall DedicatedMain(  )
{
    GetProcAddress(_hModule, "DedicatedMain");
    __asm__ ("jmp *%eax");
    return TRUE;
}

DLL_EXPORT_CPP __declspec(naked) DWORD __stdcall cvar(  )
{
    GetProcAddress(_hModule, "cvar");
    __asm__ ("jmp *%eax");
    return TRUE;
}

DLL_EXPORT_CPP __declspec(naked) DWORD __stdcall g_pCVar(  )
{
    GetProcAddress(_hModule, "g_pCVar");
    __asm__ ("jmp *%eax");
    return TRUE;
}


DLL_EXPORT_CPP DWORD __stdcall Awake( LPVOID _lpThreadParameter )
{

    for(int i = 0; i < 10; i++)
    {
        SetConsoleOutputCP(CP_UTF8);
        Sleep(1000);
    }

    if( GetConsoleOutputCP() == CP_UTF8)
    {
        system("@ECHO =====================================================");
        system("@ECHO Author: FearLose");
        system("@ECHO Version: v0.01");
        system("@ECHO TODO: Set active code page is down.");
        system("@ECHO =====================================================");
    }
    return TRUE;
}

DLL_EXPORT_CPP DWORD __stdcall Dexit( LPVOID _lpParameter )
{

    if ( !FreeLibrary( ( HMODULE ) _lpParameter ) )
        FreeLibraryAndExitThread( ( HINSTANCE ) _lpParameter, FALSE );

    return TRUE;
}


WINBOOL __stdcall DllMain( HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved )
{
    switch ( _Reason )
    {
        case DLL_PROCESS_ATTACH:

            _hModule = LoadLibraryA( "dedicated.old.dll" );

            if ( _hModule > 0 )
                CloseHandle( CreateThread( nullptr, 0, Awake, _HDllHandle, 0, 0 ) );
            else
                MessageBoxA(0, "[ERROR] Can't not get dedicated.old.dll file!", "Dedicated Pathed", MB_OK);

            break;
        case DLL_PROCESS_DETACH:
            Dexit( _HDllHandle );
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
        default:
            break;
    }

    return TRUE;
}
