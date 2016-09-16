`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/16/2016 02:58:37 PM
// Design Name: 
// Module Name: Circuit5
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Circuit5(a, b, c, Clk, Rst, z, x);

input [63:0] a, b, c;
input Clk, Rst;

output [31:0] z, x;

wire [63:0] d, e, f, g, h, greg, hreg;
wire  dLTe, dEQe;
wire [63:0] xrin, zrin;

ADD #(64) add1(
    .a(a),
    .b(b),
    .sum(d)
);

ADD #(64) add2(
    .a(a),
    .b(c),
    .sum(e)
);

SUB #(64) sub1(
    .a(a),
    .b(b),
    .diff(f)
);

COMP #(64) comp1(
    .a(d),
    .b(e),
    .lt(dLTe),
    .eq(dEQe)
);

MUX2x1 #(64) mux1(
    .a(d),
    .b(e),
    .sel(dLTe),
    .d(g)
);

MUX2x1 #(64) mux2(
    .a(g),
    .b(f),
    .sel(dEQe),
    .d(h)
);

REG #(64) reg1(
    .d(g),
    .Clk(Clk),
    .Rst(Rst),
    .q(greg)
);

REG #(64) reg2(
    .d(h),
    .Clk(Clk),
    .Rst(Rst),
    .q(hreg)
);

SHL #(64) shl1(
    .a(greg),
    .sh_amt(dLTe),
    .d(xrin)
);

SHR #(64) shr1(
    .a(hreg),
    .sh_amt(dEQe),
    .d(zrin)
);

REG #(64) reg3(
    .d(xrin),
    .Clk(Clk),
    .Rst(Rst),
    .q(x)
);

REG #(64) reg4(
    .d(zrin),
    .Clk(Clk),
    .Rst(Rst),
    .q(z)
);

endmodule
