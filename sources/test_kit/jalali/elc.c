/*
 * elc.c - Tools for manipulating Jalali representation of Iranian calendar
 * and necessary conversations to Gregorian calendar.
 * Copyright (C) 2006, 2007, 2009, 2010, 2011 Ashkan Ghassemi.
 *
 * This file is part of libjalali.
 *
 * libjalali is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libjalali is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libjalali.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include "jalali.h"

int main(int argc, char** argv)
{
    if (argc != 3) {
    printf("wrong arguments given\n");
    printf("elc: leap counter from YEAR1 to YEAR2\n");
    printf("usage: elc YEAR1 YEAR2\n");
    exit(1);
    }

    int i, s = atoi(argv[1]), e = atoi(argv[2]), c = 0;

    if (s > e) {
    /* tricky swap */
    s = s+e;
    e = s-e;
    s = s-e;
    }

    printf("leap years from %d to %d... ", s, e);

    for (i=s; i<=e; i++) {
    if (jalali_is_jleap(i))
        c++;
    }

    printf("%d.\n", c);
    exit(0);
}
