#include "../inc/uls.h"

void mx_print_files(t_fileinfo files[], int size, int flags) {
    int max = mx_max_name_length(files, size);
    int cols = mx_count_cols(max);

    int rows = size / cols;
    if(size % cols != 0) {
        rows += 1;
    }

    if(!isatty(STDOUT_FILENO) || flags & FLAG_1){
       for(int i = 0; i < size; i++){
            mx_printstr(files[i].name);
            mx_printchar('\n');
       }
    }
    else if(flags & FLAG_l) {
        mx_long_output(files, size);
    }
    else {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int index = i + j * rows;
                if(index < size ) {
                    mx_printstr(files[index].name);
                    mx_printnchar(' ', max - mx_strlen(files[index].name));
                }
                if(j != cols - 1) {
                    mx_printchar('\t');
                }
            }
            mx_printchar('\n');
        }
    }
}
