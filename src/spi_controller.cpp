#include "spi_controller.h"

void spi_controller::spi_process()
{
    counter = 0;
    wait();
    while(true) {
        wait();
        counter = counter.read() + 1;
    }
}
