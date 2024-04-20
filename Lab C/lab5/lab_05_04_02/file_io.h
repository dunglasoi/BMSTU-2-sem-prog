#ifndef __FILE_IO_H__
#define __FILE_IO_H__

#include <stdio.h>

#include "result.h"

result_t get_file_size(FILE *const file, size_t *const size);

result_t copy_file(char const *const src_filename, char const *const dst_filename, FILE **const dst_out);

#endif
