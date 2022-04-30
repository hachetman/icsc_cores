#include "rgb_matrix_ctrl.h"

void rgb_matrix_ctrl::output_process()
{
    counter = 0;
    wait();
    while(true) {
        wait();
        counter = counter.read() + 1;
    }
}
