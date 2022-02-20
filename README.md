# loggr

> by smv

Extra layer on top of printf to make logging easier!  
With loggr you can set logging levels to make things easier.

## Contents.
- [Installation.](#installation)
- [Compile commands.](#compile-commands)
- [Usage.](#usage)
- [Help me.](#help-me)

## Installation.
Install on Linux by running:  
`sudo make install` or  
`make install DIR=/path/to/directory`  
For any other OS just generate files with `make install DIR=/path/to/directory` and place `libloggr.so` and `loggr.h` in your working directory.

### Compile commands.
`gcc main.c -lloggr -o main`  
or maybe `gcc main.c -L /path/to/library -lloggr -o main`

## Usage.
### Actually logging stuff. :P
- `Debug(text, ...)` - for logging debugging info
- `Log(text, ...)` - for logging normal messages
- `Warning(text, ...)` - _warns_
- `Error(text, ...)` - displays an error

### Options.
- `SetLogLevel(level)` - sets the level of severity for messages to be shown so logs can be filtered
- `SetColors(yes)` - sets if text should be _coloured_
- `SetLabels(yes)` - sets if _labels_ should be used or not

### Example.
```c
#include <loggr.h>

int main() {
  SetLabels(1);  // enables labels
  SetColors(0);  // disables colours
  SetLogLevel(WARN);  // now only warnings/errors will be displayed
  Log("Hello!");
  Warn("Warning. :o");
  Error("The example ended.");
  return 0;
}
```
Outputs:
```
(WARN)  Warning. :o
(ERROR) The example ended.
```

A more detailed example is located at [example.c](example.c). Run `make test && ./loggr` to see the output.

## Help me.
By suggesting what I could add to this library!