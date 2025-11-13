/*
 * jyinfo.c - Tools for manipulating Jalali representation of Iranian calendar
 * and necessary conversations to Gregorian calendar.
 * Copyright (C) 2006-2011 Ashkan Ghassemi.
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
 * along with libjalali.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include "jalali.h"

int main(int argc, char** argv)
{
    struct jyinfo a;

    if (argc != 2) {
    printf("wrong arguments given\n");
    printf("usage: jyinfo YEAR\n");
    exit(1);
    }

    a.y = atoi(argv[1]);
    jalali_get_jyear_info(&a);
    fprintf(stdout, "Year %d: lf = %d, apl = %d, pl = %d, rl = %d, p = %d, r = %d.\n", a.y, a.lf,
        a.apl, a.pl, a.rl, a.p, a.r);

    exit(0);
}
