/*
 * jstrftime.c - Tools for manipulating Jalali representation of Iranian calendar
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
#include <time.h>
#include "jalali.h"
#include "jtime.h"

int main(int argc, char** argv) {
    if (argc != 2) {
    printf("wrong arguments given\n");
    printf("usage jstrftime FORMAT\n");
    exit(1);
    }

    const char* fmt = argv[1];
    char buf[32];
    time_t t;
    size_t s;
    time(&t);
    struct jtm j;
    jlocaltime_r(&t, &j);
    jalali_show_time(&j);
    s = jstrftime(buf, 32, fmt, &j);
    printf("%s:%d\n", buf, (int)s);

    exit(0);
}
