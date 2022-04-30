#ifndef RGB_MATRIX_CTRL_H
#define RGB_MATRIX_CTRL_H

#include "sct_static_log.h"
#include "sct_assert.h"
#include "systemc.h"

class rgb_matrix_ctrl : public sc_module
{
public:
    sc_in_clk clk;
    sc_in<bool> nrst;
    sc_out<sc_uint<4> > counter{"counter"};
    SC_CTOR(rgb_matrix_ctrl) {
        SC_CTHREAD(output_process, clk.pos());
        async_reset_signal_is(nrst, false);
    };
    void output_process();
};
#endif
