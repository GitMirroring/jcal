# Makefile.am - Tools for manipulating Jalali representation of Iranian calendar
# and necessary conversations to Gregorian calendar.
# Copyright (C) 2006, 2007, 2009, 2010, 2011 Ashkan Ghassemi.
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
#------------------------------------------------------------------------------ 
# Process this file with automake to produce Makefile.in.
#------------------------------------------------------------------------------

lib_LTLIBRARIES = libjalali.la

libjalali_la_SOURCES = jalali.c jtime.c

# 0:0:0
# 0 -> interface version, changes whenever you change the API
# 0 -> changes whenever you make a revision of an interface no
#      API changes...
# 0 -> changes whenever you change the API but keep it backwards
#      compatible (have not removed a function from the API, for
#      example...)

libjalali_la_LDFLAGS = -version-info 0:5:0
includedir= $(prefix)/include/jalali
include_HEADERS = jalali.h jtime.h jconfig.h
INCLUDES        =  -I. -I@includedir@
LIBS            = @LIBS@ $(THREAD_LIBS)
AM_CFLAGS          = @CFLAGS@ -D_REENTRANT -W -Wall -O2
