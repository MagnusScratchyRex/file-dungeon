#ifndef FSMAP__H
#define FSMAP__H

#include <stddef.h>
#include <stdbool.h>

/**
 * Check if the given file starts with a '.'.
 *
 * @param filepath A null-terminated string containing the path to the file
 * @return True is the file is a dotfile, false otherwise
 */
extern bool fsmap_is_dotfile(const char *filepath);

/**
 * Get the current working directory.
 *
 * @return A null-terminated string containing the absolute path to the current
 *         working directory
 */
extern const char *fsmap_get_curdir(void);

/**
 * Get the name of the given file, without all its parent directories.
 *
 * @param filepath A null-terminated string containing the path to the file
 * @return A null-terminated string containing the name of the file
 */
extern const char *fsmap_get_filename(const char *filepath);

/**
 * Get the extension of the given file, if any.
 *
 * @param filepath A null-terminated string containing the path to the file
 * @return A null-terminated string containing the extension of the file or
 *         null if the file doesn't have any extension.
 */
extern const char *fsmap_get_file_extension(const char *filepath);

// TODO:
extern int fsmap_guess_filetype(const char *filepath);

#endif
