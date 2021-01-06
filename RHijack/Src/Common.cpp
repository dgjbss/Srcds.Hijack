/*
 * Common.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: FearLose
 */

#include "Stdafx.hpp"

typedef LPVOID (__stdcall* FnAwake)(LPVOID _lpThreadParameter);
FnAwake _Awake = nullptr;

int main( )
{
    HMODULE _hModule = 0;
    _hModule = LoadLibraryA( "libDTBase.dll" );

    if ( _hModule > 0 )
        std::cout << "[DEBUG] " << "hModule:0x" << std::hex << std::uppercase << (intptr_t)_hModule << std::endl;
    else
        std::cout << "[DEBUG] " << "Get hModule is failed." << std::endl;

    _Awake = (FnAwake)GetProcAddress(_hModule, "Awake");
    _Awake(nullptr);

    return TRUE;
}
