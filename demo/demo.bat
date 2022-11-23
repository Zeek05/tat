@echo off

Pushd "..\build"

echo The following attributes are supported on the Windows Console:
echo.
echo - Bold text (Default attribute on the console. Use it to undo dim)
echo - Underline
echo - Blinking text
echo - Negative image
echo - Dimmed text
echo - Double underline (bigunderline)
echo - Strikethrough
echo - Overline
echo - Italic Text
echo.
pause

tat underline & echo This text has an underline on it!
tat reset & echo.
pause
tat blink & echo This text is blinking!
tat reset & echo.
pause
tat negative & echo This text has foreground/background reversed!
tat reset & echo.
pause
tat dim & echo This text is a dimmer shade of the foreground color!
tat reset & echo.
pause
tat bigunderline & echo This text has an even larger underline!
tat reset & echo.
pause
tat strike & echo This text is striked through.
tat reset & echo.
pause
tat overline & echo This text has a line on top of it.
tat reset & echo.
pause
tat italic & echo This text is slanted (results depend on font.)
tat reset & echo.
pause
tat reset & echo Text is now reset.
echo.
echo End demonstration.
pause
