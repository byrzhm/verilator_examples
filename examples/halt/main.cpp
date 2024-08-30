#include "svdpi.h"
#include "Vour__Dpi.h"
#include "Vour.h"
#include "verilated.h"

#include <iostream>

bool running = true;

void halt() {
  running = false;
}

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vour* top = new Vour{contextp};
    while (running) { 
      std::cout << "mark 1" << std::endl;
      top->clk = 0;
      std::cout << "mark 2" << std::endl;
      top->eval();
      std::cout << "mark 3" << std::endl;
      top->clk = 1;
      std::cout << "mark 4" << std::endl; // rising edge
      top->eval();
      std::cout << "mark 5" << std::endl;
    }
    delete top;
    delete contextp;
    return 0;
}