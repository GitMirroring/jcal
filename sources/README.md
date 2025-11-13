jcal is a UNIX cal-like tool to display calendar
based on jalali calendar system.

jdate is UNIX date-like tool to display date and time
based on jalali calendar system

jcal switches in brief:
+ `-y`  Display a calendar for the current year.
+ `-p`  Display Farsi names and numbers.
+ `-P`  Display year based on Pahlavi epoch.
+ `-e`  Display English names for weekdays.
+ `-j`  Display Julian dates (days one-based, numbered from Farvardin 1).
+ `-1`  Display single month output. (This is the default.)
+ `-3`  Display prev/current/next months output.
+ `-V`  Display calendar version.

See `man jcal` for more information.

jdate switches in brief:
+ `-a`  Display the last access time for a file.
+ `-r`  Display the last modification time for a file.
+ `-d`  Interpret date according to date-string instead of `now`.
+ `-R`  Ouput in RFC2822 format.
+ `-u`  Display Coordinated Universal Time.
+ `-h`  Display help.
+ `-V`  Display version.

If you're experiencing troubles, compiling the package with GNU's
build system then keep reading.


Installation
============
Run `./autogen.sh` to make `configure` script for you.  Then follow common
package installation routine as described in INSTALL.

If you want pyjalali package too, you can either pass `--enable-pyjalali`
option to `./configure` script or after installing libjalali use provided
`setup.py` directly:

``` sh
cd jcal/sources
python setup.py install
```


# Copyright of README.md

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty
provided the copyright notice and this notice are preserved.  This file is offered as-is, without any warranty.
