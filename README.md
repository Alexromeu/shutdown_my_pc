# Windows Shutdown Timer (C)

A simple countdown timer written in C that shuts down a Windows machine after a user‑defined number of hours and minutes.

## Features
- User input for hours and minutes
- Live countdown display
- Millisecond‑accurate decrement logic
- Calls Windows shutdown command when finished

## How It Works
The program:
1. Prompts the user for hours and minutes  
2. Runs a countdown loop using `sleep()`  
3. Updates hours, minutes, and seconds using a safe decrement cascade  
4. Executes `shutdown /s` when the timer reaches zero

## Build
Compile with any C compiler:


## Run
download shutdown_1.1.exe and execute on Windows
## Notes
- Uses `system("cls")` and Windows shutdown command, so it is intended for Windows.
- Countdown logic uses `nanosleep()`‑style structure for correctness.

## License
MIT License
