import "DPI-C" function int add(input int a, input int b);

module our;
    initial begin
        $display("%x + %x = %x", 1, 2, add(1, 2));
        $finish;
    end
endmodule

