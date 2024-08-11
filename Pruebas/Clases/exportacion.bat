@echo off
setlocal

REM Configura los nombres de los archivos
set SOURCE_FILES=main.cpp ProcesadorDeFacturas.cpp
set OUTPUT_EXE=main.exe
set COMPILE_COMMAND=g++ -o %OUTPUT_EXE% %SOURCE_FILES%

REM Eliminar archivos antiguos si existen
if exist %OUTPUT_EXE% del %OUTPUT_EXE%

REM Compilar el código
echo Compilando...
%COMPILE_COMMAND%

REM Verificar si la compilación fue exitosa
if %ERRORLEVEL% NEQ 0 (
    echo Error durante la compilacion.
    pause
    exit /b %ERRORLEVEL%
)

REM Opcional: Mover el ejecutable a una carpeta específica (descomentar si es necesario)
REM set DEST_FOLDER=C:\Ruta\A\Tu\Carpeta
REM if not exist %DEST_FOLDER% mkdir %DEST_FOLDER%
REM move %OUTPUT_EXE% %DEST_FOLDER%

echo Compilación y exportación completadas exitosamente.
pause
