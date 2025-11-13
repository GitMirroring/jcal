/*
 * jalali_update.c - Tools for manipulating Jalali representation of Iranian calendar
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
 * along with libjalali.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <time.h>
#include "jalali.h"
#include "jtime.h"

int main(int argc, char** argv) {
    time_t t;
    struct jtm j;
    int mday_diff = 60;

    time(&t);
    jlocaltime_r(&t, &j);
    puts("Current time jtm:");
    jalali_show_time(&j);

    char ans;
    int* mem_ref;
    char* mem_name;
    do {
        printf(">> Reset tm_year [y], tm_mon [M], tm_mday [d], tm_hour [h], tm_min [m], tm_sec[s] to: ([e] for end) ");
        scanf("%c", &ans);
        switch (ans) {
            case 'y': mem_ref = &j.tm_year; mem_name = "tm_year"; break;
            case 'M': mem_ref = &j.tm_mon; mem_name = "tm_mon"; break;
            case 'd': mem_ref = &j.tm_mday; mem_name = "tm_mday"; break;
            case 'h': mem_ref = &j.tm_hour; mem_name = "tm_hour"; break;
            case 'm': mem_ref = &j.tm_min; mem_name = "tm_min"; break;
            case 's': mem_ref = &j.tm_sec; mem_name = "tm_sec"; break;
            case 'e': break;
            default:
                printf("Unrecognized field `%c'. select from [yMdhmse] and provide a value.\n", ans);
                ans = 0;
                break;
        }
        if(ans && ans != 'e') {
            scanf("%d%*c", mem_ref);
            printf ("%s = %d\n", mem_name, *mem_ref);
        } else getchar();
    } while (ans != 'e');

    puts("Before update: ");
    jalali_show_time(&j);

    jalali_update(&j);
    puts("After update: ");
    jalali_show_time(&j);
    return 0;
}
