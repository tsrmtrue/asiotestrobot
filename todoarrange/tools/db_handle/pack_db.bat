SET SOURCE=lj_ts_1
set BACKPATH="%SOURCE%_back_%date:~0,4%_%date:~5,2%_%date:~8,2%_%time:~0,2%_%time:~3,2%_%time:~6,5%"
echo %BACKPATH%
md %BACKPATH%
xcopy %SOURCE%\*.*  %BACKPATH%
7z a %BACKPATH%.7z %BACKPATH%