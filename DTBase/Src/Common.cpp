/*
 * Common.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: FearLose
 */

#include "Stdafx.hpp"

DLL_EXPORT_CPP DWORD __stdcall Awake( LPVOID _lpThreadParameter )
{
    system("ECHO You call me ?");

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
            break;
        case DLL_PROCESS_DETACH:
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
