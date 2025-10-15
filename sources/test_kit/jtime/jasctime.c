/*
 * jasctime.c - Tools for manipulating Jalali representation of Iranian calendar
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
#include <time.h>
#include "jalali.h"
#include "jtime.h"

int main() {
    time_t ltime;
    time(&ltime);
    struct ab_jtm a;
    struct jtm j;
    jalali_create_time_from_secs(ltime, &a);
    jalali_get_date(a.ab_days, &j);
    j.tm_sec = a.ab_sec;
    j.tm_min = a.ab_min;
    j.tm_hour = a.ab_hour;
    jalali_create_date_from_days(&j);
    printf("%s", jasctime(&j));
    return 0;
}
