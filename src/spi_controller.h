#ifndef SPI_CONTROLLER_H
#define SPI_CONTROLLER_H

#include "sct_static_log.h"
#include "sct_assert.h"
#include "systemc.h"

class spi_controller : public sc_module
{
public:
    sc_in_clk clk;
    sc_in<bool> nrst;
    sc_out<sc_uint<4> > counter{"counter"};
    SC_CTOR(spi_controller) {
        SC_CTHREAD(spi_process, clk.pos());
        async_reset_signal_is(nrst, false);
    };
    void spi_process();
};
#endif
