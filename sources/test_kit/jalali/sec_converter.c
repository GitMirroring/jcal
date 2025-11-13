/*
 * sec_converter.c - Tools for manipulating Jalali representation of Iranian calendar
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
    if (argc != 2) {
    printf("wrong arguments given\n");
    printf("usage: sec_converter SECONDS\n");
    exit(1);
    }

    struct ab_jtm a;
    int s;
    s = atoi(argv[1]);
    jalali_create_time_from_secs(s, &a);
    printf("%d secs passed, time created: %d days, %02d:%02d:%02d.\n", s, a.ab_days, a.ab_hour, a.ab_min, a.ab_sec);

    exit(0);
}
