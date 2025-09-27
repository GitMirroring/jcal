#!/usr/bin/env python3
# Copyright 2008 Marcus D. Hanwell <marcus@cryos.org>
# Distributed under the terms of the GNU General Public License v2 or later

import re
import os

# Using 'with' is a standard Python 3 practice for handling files
# and other resources, as it ensures they are properly closed.
try:
    git_log_process = os.popen('git log --summary --stat --no-merges --date=short', 'r')
    changelog_file = open('ChangeLog', 'w')
except OSError as e:
    print(f"Error: Could not execute 'git log' or open 'ChangeLog'. Details: {e}")
    exit(1)

with git_log_process as fin, changelog_file as fout:
    # Set up loop variables to locate the desired blocks in the git log
    authorFound = False
    dateFound = False
    messageFound = False
    filesFound = False
    message = ""
    files = ""
    prevAuthorLine = ""

    # The main loop to process each line from the git log
    for line in fin:
        # A 'commit' line marks the start of a new commit object.
        if line.startswith('commit '):
            # Reset all flags for the new commit entry
            authorFound = False
            dateFound = False
            messageFound = False
            message = ""
            filesFound = False
            files = ""
            continue
        # Match the author line and extract the author's name
        elif re.match('Author:', line):
            authorList = line.split(': ', 1)
            author = authorList[1].strip()
            authorFound = True
        # Match the date line and extract the date
        elif re.match('Date:', line):
            # Note: git log often uses multiple spaces after 'Date:'
            dateList = re.split(r':\s+', line, 1)
            date = dateList[1].strip()
            dateFound = True
        # The git-svn-id lines are ignored
        elif 'git-svn-id:' in line:
            continue
        # The sign-off lines are also ignored
        elif 'Signed-off-by' in line:
            continue
        # Extract the actual commit message
        elif authorFound and dateFound and not messageFound:
            # The message ends when a blank line is found after some message text
            if not line.strip():
                if message:
                    messageFound = True
            else:
                # Concatenate message parts with a space
                message += (" " if message else "") + line.strip()
        # The line with "files changed" marks the end of the file list summary
        elif 'files changed' in line:
            filesFound = True
            continue
        # Collect the file names for this commit
        elif authorFound and dateFound and messageFound:
            # File lines typically look like: ' path/to/file.py | 5 +++--'
            fileList = line.split(' | ', 1)
            if len(fileList) > 1:
                filename = fileList[0].strip()
                files += (", " if files else "") + filename

        # When all parts of a commit are found, write the entry to the ChangeLog
        if authorFound and dateFound and messageFound and filesFound:
            # Write the author/date line, but only if it's new for that day
            authorLine = f"{date}  {author}"
            if not prevAuthorLine:
                fout.write(f"{authorLine}\n")
            elif authorLine != prevAuthorLine:
                fout.write(f"\n{authorLine}\n")

            # Assemble the full commit entry and wrap it to ~78 characters
            commitLine = f"* {files}: {message}"
            i = 0
            commit = ""
            while i < len(commitLine):
                # If the remainder fits on one line, append it and finish
                if len(commitLine) - i <= 78:
                    commit += f"\n  {commitLine[i:]}"
                    break

                # Find the last space within the line length for a clean word break
                index = commitLine.rfind(' ', i, i + 78)

                if index > i:
                    commit += f"\n  {commitLine[i:index]}"
                    i = index + 1
                else:
                    # No space found, so we must break the line mid-word
                    commit += f"\n  {commitLine[i:i+78]}"
                    i += 78

            # Write the formatted commit line(s) to the file
            fout.write(f"{commit}\n")

            # Reset all variables for the next commit block
            # This is redundant (also done at the start) but matches original structure
            authorFound = False
            dateFound = False
            messageFound = False
            message = ""
            filesFound = False
            files = ""
            prevAuthorLine = authorLine

# The 'with' statement automatically handles closing the files.
