# cookie-clicker-ce
Cookie Clicker for the TI-84 CE!

### Building instructions (Windows)
- Download the repository
- Make sure you have the current CE C Toolchain (https://github.com/CE-Programming/toolchain/releases/latest)
- Make sure you have the latest TI Connect CE software (or alternative)
- Make sure the latest libraries are installed on the calculator (https://github.com/CE-Programming/libraries/releases/latest)
- Open ```"cedev.bat"``` from the CE C Toolchain
- Direct it to the directory of Cookie Clicker CE
- Type ```"cd src/gfx"``` and then type "convimg"
- Wait until complete, then type ```"cd ../.."```
- Finally, type ```"make"```
- Once it's done building the 8xp, copy the file ```"CookClik.8xp"``` from ```/bin/``` to the calculator
- Copy ```"ccspr.8xv"``` from ```/src/gfx/``` to the calculator
