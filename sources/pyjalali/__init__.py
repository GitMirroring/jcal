# pyjalali - Python bindings of libjalali
# Copyright (C) 2013, 2014 Amir Ghassemi Nasr.
#
# This file is part of pyjalali.
# pyjalai is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# pyjalali is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
# You should have received a copy of the GNU Lesser General Public License
# along with pyjalali.  If not, see <http://www.gnu.org/licenses/>.

"""
    pyjalali
    ~~~~~~~~

    Python bindings for libjalali.

    Low level API could be accessed through :mod:`.jstr`, :mod:`.jtime` and
    :mod:`.jalali` modules.  Core libjalali data structures resides in
    :mod:`.types` module.
    
    An implementation of standard :class:`python:datetime.date` and
    :class:`python:datetime.datetime` provided in module :mod:`.datetime`
    using libjalali tools.
"""

import os
import sys
import ctypes.util
from ctypes import cdll

# hardcoded libjalali version, binding revision
__version__ = (0, 5, 0, 2)

if sys.platform.startswith('win'):
    libname = 'libjalali.dll'
else:
    libname = 'libjalali.so'
_libj = cdll.LoadLibrary(os.path.join(os.environ.get('LIBJALALI_DIR', ''),
                                      libname))
del cdll, ctypes, sys, libname, os
