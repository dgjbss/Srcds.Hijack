/*
 * Common.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: FearLose
 */

#include "Stdafx.hpp"

typedef LPVOID (__stdcall* FnAwake)(LPVOID _lpThreadParameter);
FnAwake _Awake = nullptr;

DLL_EXPORT_CPP DWORD __stdcall Awake( LPVOID _lpThreadParameter )
{
    system("ECHO Oh! You calling DTHijack !");
    system("ECHO I will find DTBase return !");

    HMODULE _hModule = 0;
    _hModule = LoadLibraryA( "libDTBase_old.dll" );

    if ( _hModule > 0 )
        std::cout << "[DEBUG] " << "hModule:0x" << std::hex << std::uppercase << (intptr_t)_hModule << std::endl;
    else
        std::cout << "[DEBUG] " << "Get hModule is failed." << std::endl;

    _Awake = (FnAwake)GetProcAddress(_hModule, "Awake");
    _Awake(nullptr);

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
            CloseHandle( CreateThread( nullptr, 0, Awake, _HDllHandle, 0, 0 ) );
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
