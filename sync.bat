@echo off
xcopy /E /Y /I "%~dp0keyboards" "%QMK_HOME%\keyboards"
echo Done!