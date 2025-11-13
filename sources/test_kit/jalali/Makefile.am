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

bin_PROGRAMS = elc get_date get_diff jalali_update jyinfo leap sec_converter leap_range

INCLUDES = -I../../libjalali

AM_CFLAGS = @CFLAGS@ -fno-inline -D_REENTRANT -Wall \
	-O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

elc_SOURCES = elc.c
get_date_SOURCES = get_date.c
get_diff_SOURCES = get_diff.c
jalali_update_SOURCES = jalali_update.c
jyinfo_SOURCES = jyinfo.c
leap_SOURCES = leap.c
leap_range_SOURCES = leap_range.c
sec_converter_SOURCES = sec_converter.c

LDADD           = ../../libjalali/libjalali.la
