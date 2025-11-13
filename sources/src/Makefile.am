#Makefile.am - Unix date-like interface to libjalali.
#Copyright (C) 2006-2011 Ashkan Ghassemi.

#This file is part of jcal.

#jcal is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.

#jcal is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.      See the
#GNU General Public License for more details.

#You should have received a copy of the GNU General Public License
#along with jcal.      If not, see <http://www.gnu.org/licenses/>.
bin_PROGRAMS = jcal jdate

INCLUDES = -I. -I.. -I../libjalali -I@includedir@

AM_CFLAGS = @CFLAGS@ -fno-inline -D_REENTRANT -Wall\
	-O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

jcal_SOURCES = jcal.c
jdate_SOURCES = jdate.c
LDADD           = ../libjalali/libjalali.la -L@libdir@
LIBS            = @LIBS@ $(THREAD_LIBS)
