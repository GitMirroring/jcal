/*
 * get_diff.c - Tools for manipulating Jalali representation of Iranian calendar
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
    if (argc != 4) {
    printf("wrong arguments given\n");
    printf("usage: get_diff DAY MONTH YEAR\n");
    exit(1);
    }

    int d = atoi(argv[1]);
    int m = atoi(argv[2]);
    int y = atoi(argv[3]);

    struct jtm j;
    j.tm_mday = d;
    j.tm_mon = m - 1;
    j.tm_year = y;
    j.tm_hour = 0;
    j.tm_min = 0;
    j.tm_sec = 0;

    jalali_create_days_from_date(&j);
    jalali_update(&j);
    jalali_show_time(&j);
    printf("diff = %d\n", jalali_get_diff(&j));

    exit(0);
}
