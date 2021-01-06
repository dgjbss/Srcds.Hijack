@ECHO OFF & PUSHD "%~DP0" && CD /D "%~DP0"
@REM @ECHO OFF & PUSHD %~DP0 & TITLE
IF EXIST "%Public%" >NUL 2>&1 REG QUERY "HKU\S-1-5-19\Environment"
IF NOT %errorlevel% EQU 0 (
    IF EXIST "%Public%" powershell.exe -windowstyle hidden -noprofile "Start-Process '%~dpnx0' -Verb RunAs"
    EXIT
)

>NUL 2>&1 REG.exe query "HKU\S-1-5-19" || (
    ECHO SET UAC = CreateObject^("Shell.Application"^) > "%TEMP%\Getadmin.vbs"
    ECHO UAC.ShellExecute "%~f0", "%1", "", "runas", 1 >> "%TEMP%\Getadmin.vbs"
    "%TEMP%\Getadmin.vbs"
    DEL /f /q "%TEMP%\Getadmin.vbs" 2>NUL
    Exit /b
)

@REM Delete the item cache.
FOR /R /D %%i in ("*.*") DO (
    ECHO "%%i"
	
	ECHO "%%i" | findstr ".vs"                     >NUL && ( RD /S /Q "%%i" )
	ECHO "%%i" | findstr "Debug"                     >NUL && ( RD /S /Q "%%i" )
	ECHO "%%i" | findstr "Release"                     >NUL && ( RD /S /Q "%%i" )
)

@REM Delete some not used file.
RD /S /Q ".VS"
RD /S /Q "X64"
RD /S /Q "DEBUG"
RD /S /Q "RELEASE"

@REM If the path is true,  is false will exit bat.
SET OPENDIR=.metadata
SET LASTDIR=%CD%
CD /D "%OPENDIR%"
IF "%CD%"=="%LASTDIR%" (
    CLS
    ECHO Cannot switch this Dir: "%CD%\%OPENDIR%"
	Ping -n 3 -l 0 127.0.0.1>NUL && EXIT
) && REM ELSE ( ECHO Switch this directory in success: "%CD%\%OPENDIR%" )

@REM Delete some not used file.
DEL /S /Q "*.log"
DEL /S /Q "*.lock"
DEL /S /Q "*.pdom"
DEL /S /Q "*.language.settings.xml"
DEL /S /Q "org.eclipse.cdt.core.prj*.prefs"
RD  /S /Q ".mylyn"

@REM If the path is true,  is false will exit bat.
SET OPENDIR=.plugins
SET LASTDIR=%CD%
CD /D "%OPENDIR%"
IF "%CD%"=="%LASTDIR%" (
    CLS
    ECHO Cannot switch this Dir: "%CD%\%OPENDIR%"
	Ping -n 3 -l 0 127.0.0.1>NUL && EXIT
) && REM ELSE ( ECHO Switch this directory in success: "%CD%\%OPENDIR%" )

@REM Delete the item cache.
FOR /R /D %%i in ("*.*") DO (
    ECHO "%%i"

	ECHO "%%i" | findstr ".history"                     >NUL && ( RD /S /Q "%%i" )
	ECHO "%%i" | findstr ".indexes"                     >NUL && ( RD /S /Q "%%i" )
	
         ECHO "%%i" | findstr "org.eclipse.core.runtime"     >NUL && ( REM Do something Code.
	) || ECHO "%%i" | findstr "org.eclipse.core.resources"   >NUL && ( REM Do something Code.
	) || ECHO "%%i" | findstr "org.eclipse.e4.workbench"     >NUL && ( REM Do something Code.
	) || ( RD /S /Q "%%i" ) 
	
)

@REM Come back root Dir
CD /D "%LASTDIR%"
