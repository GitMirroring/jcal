# jstr.py - Python bindings of libjalali
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
# along with pyjalali.  If not, see <https://www.gnu.org/licenses/>.

"""
    pyjalali.jstr
    ~~~~~~~~~~~~~

    String formatting and deformatting
"""

from pyjalali import _libj
from pyjalali.types import struct_jtm
from ctypes import POINTER, byref
from ctypes import c_char_p, c_int, create_string_buffer

__all__ = ['jstrftime', 'jstrptime']

_jstrptime = _libj.jstrptime
_jstrptime.argtypes = (c_char_p, c_char_p, POINTER(struct_jtm))
_jstrptime.restype = c_char_p
def jstrptime(format, date_str):
    """Return :class:`.types.struct_jtm` from date_str according to format.

    :param string format: format of string representation
    :param string date_str: string representation
    """
    date = struct_jtm()
    res = c_char_p()
    res = _jstrptime(date_str, format, byref(date))
    return date, res


_jstrftime = _libj.jstrftime
_jstrftime.argtypes = (c_char_p, c_int, c_char_p, POINTER(struct_jtm))
def jstrftime(format, jtm):
    """Return string representation of given time according to format.

    :param string format: format of date representation
    :param `pyjalali.types.struct_jtm` jtm: broken-down jalali time
    """
    n = len(format) << 8
    res = create_string_buffer(n)
    _jstrftime(res, n, format, byref(jtm))
    return res.value
