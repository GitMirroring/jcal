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

ACLOCAL_AMFLAGS = -I m4
SUBDIRS         = libjalali src man test_kit

if WANT_PYJALALI
install-exec-hook:
	@echo -e "\n###########################\n"\
"##  Installing Pyjalali  ##\n"\
"###########################\n"
	test -d pyjalali || mkdir pyjalali
	@$(CP) $(srcdir)/pyjalali/*.py pyjalali
	@$(CP) $(srcdir)/setup.py .
	LIBJALALI_DIR=$(DESTDIR)$(libdir) \
	$(PYTHON) setup.py install --prefix=$(DESTDIR)$(exec_prefix) --record=pyinstalled.txt

uninstall-hook:
	while read -r fn; do $(RM) -rf "$$fn"; done <pyinstalled.txt
	-$(RMDIR) $(DESTDIR)$(pythondir)/pyjalali && $(RM) pyinstalled.txt
endif
