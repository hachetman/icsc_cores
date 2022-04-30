#include <systemc.h>
#include "spi_controller.h"
#include "sct_assert.h"

struct Dut : public sc_module
{
    sc_in_clk       clk{"clk"};
    sc_in<bool>     nrst{"nrst"};
    sc_out<sc_uint<4> > counter{"counter"};

    spi_controller controller{"controller"};
    SC_CTOR(Dut) {

        controller.clk(clk);
        controller.nrst(nrst);
        controller.counter(counter);
    }
};


SC_MODULE(Tb) {
    sc_in_clk clk{"clk"};
    sc_signal<bool> nrst{"nrst"};
    sc_signal<sc_uint<4> > counter{"counter"};

    Dut  dut{"dut"};

    SC_CTOR(Tb) {
        dut.clk(clk);
        dut.nrst(nrst);
        dut.counter(counter);

        SC_CTHREAD(tests, clk.pos());
    }

    const unsigned N = 4000;

    void tests() {
        nrst = 0;
        wait(10);
        nrst = 1;
        for (int i = 0; i < N; i++) {
            wait();
            cout << "counter: " << counter.read() << "\n";
        }
        sc_stop();
    }
};

int sc_main(int argc, char **argv)
{
    sc_clock clk("clk", sc_time(1, SC_NS));
    Tb tb{"tb"};
    tb.clk(clk);

    sc_start();

    return 0;
}
