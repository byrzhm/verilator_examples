import "DPI-C" function void halt();

module our(
    input clk
);
    reg [31:0] cnt = 0;

    localparam TIMEOUT = 32'd10;

    always @(posedge clk) begin
        cnt <= cnt + 1;
        $display("cnt = %d", cnt);
        if (cnt == TIMEOUT) begin
            $display("Timeout");
            halt();
        end
    end

endmodule

