Ashkan, the original maintainer of this project passed away in 2017. He was the initiator of this beautiful project. We honor his memory and contributions to the free software community of Iran and the Iranosphere. Rest in peace, Ashkan.

# jcal 0.6.0 (2025-11-14)

*   **Leap Year Algorithm Refactoring**: The Jalali leap year algorithm has been refactored for simplicity and better range support.
*   **License**: Some improvement has been done in terms of clearing up licencing. For example libjalali is explicitly nder the GNU Lesser General Public License version 3 (LGPLv3) as Ashkan intended. The tools (jcal, jdate) are under GPLv3.
*   **New API Functions**: Added `compute_jdn`, `is_valid_jalali`, `is_valid_gregorian`, and `gregorian_is_gleap` to libjalali.
*   **Code Style**: We now follow GNU C style.
*   **Bug Fixes**: Fixed several issues in `jdate` and improved input validation in `jstrptime`.
*   **Build System Improvements**: Refined Autotools configuration for better portability and dependency management.

Please see ChangeLog for seeing the changes in the project.

# Copyright of NEWS 

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty
provided the copyright notice and this notice are preserved.  This file is offered as-is, without any warranty.
