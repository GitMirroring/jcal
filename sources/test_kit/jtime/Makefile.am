# Makefile.am - Tools for manipulating Jalali representation of Iranian calendar
# and necessary conversations to Gregorian calendar.
# Copyright (C) 2006-2011 Ashkan Ghassemi.
#
# This file is part of libjalali.
#
# libjalali is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libjalali is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with libjalali.  If not, see <https://www.gnu.org/licenses/>.

bin_PROGRAMS = jasctime jctime jgmtime jstrftime jstrptime jlocaltime jmktime

INCLUDES = -I../../libjalali

AM_CFLAGS = @CFLAGS@ -fno-inline -D_REENTRANT -Wall \
	-O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

jasctime_SOURCES = jasctime.c
jctime_SOURCES = jctime.c
jgmtime_SOURCES = jgmtime.c
jstrftime_SOURCES = jstrftime.c
jstrptime_SOURCES = jstrptime.c
jlocaltime_SOURCES = jlocaltime.c
jmktime_SOURCES = jmktime.c

LDADD           = ../../libjalali/libjalali.la -lreadline
