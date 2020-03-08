@echo off

:start
set /p choice="Do you want to compile ? [y/n]"

if %choice% == y (
  make
  goto run
)

if %choice% == n (
  goto run
)

echo.
echo ERROR : Enter valid argument
pause
goto start

:run
cd build
a.exe
cd ..
