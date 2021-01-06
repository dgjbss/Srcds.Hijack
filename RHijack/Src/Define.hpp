/*
 * Define.hpp
 *
 *  Created on: Jan 5, 2021
 *      Author: FearLose
 */


#pragma once

#ifndef DEFINE_HPP_
#define DEFINE_HPP_

//---------------------------------------------------------------//
//                     Register build symbol                     //

// Register to header file symbol Force wide characters ?
// @TODO: wchar   WinAPIA/W();
//

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

// Window default using ?
// @TODO: default nothing.
//

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif

// MinGW / MSVC -> Build Export dynamic link library will need ?
// @TODO: export DLL
//        [MinGW] Linker: -Xlinker --kill-at
//

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

#ifndef DLL_IMPORT
#define DLL_IMPORT __declspec(dllimport)
#endif

#ifndef DLL_EXPORT_CPP
#define DLL_EXPORT_CPP extern "C" __declspec(dllexport)
#endif

#ifndef DLL_IMPORT_CPP
#define DLL_IMPORT_CPP extern "C" __declspec(dllimport)
#endif


//---------------------------------------------------------------//
//                   Register type declaration                   //


// Register to default type declaration ?
// @TODO: char, byte, short, int, long, float, double...
//

#ifndef LPVOID
typedef void* LPVOID;
#endif

#endif /* DEFINE_HPP_ */
