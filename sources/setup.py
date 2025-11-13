#!/usr/bin/env python

# setup.py - Tools for manipulating Jalali representation of Iranian calendar
# and necessary conversations to Gregorian calendar.
# Copyright (C) 2006-2011 Ashkan Ghassemi.
#
# This file is part of pyjalali.
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

import os
import sys
from distutils.core import setup
src_p = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, src_p)
import pyjalali

version = '.'.join(map(str, pyjalali.__version__))

setup(
        name='pyjalali',
        description='Jalali calendar tools based on libjalali',
        long_description=pyjalali.__doc__.replace(' '*4, ''),
        url='https://github.com/ashkang/jcal',
        license='LGPLv3',
        version=version,

        packages=['pyjalali'],

        classifiers = [
            'Development Status :: 3 - Alpha',
            'Intended Audience :: Developers',
            'License :: OSI Approved :: GNU Lesser General Public License v3 (LGPLv3)',
            'Topic :: Software Development :: Libraries :: Python Modules',
            'Topic :: Software Development :: Localization'
        ]
)
