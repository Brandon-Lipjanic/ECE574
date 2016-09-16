`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/16/2016 02:16:11 PM
// Design Name: 
// Module Name: Circuit2
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


module Circuit2(a, b, c, Clk, Rst, z, x);

input [31:0] a, b, c;
input Clk, Rst;

output [31:0] z, x;

wire [31:0] d, e, f, g, h, zwire, xwire;
wire dLTe, dEQe;

ADD #(32) add1(
    .a(a),
    .b(b),
    .sum(d)
);

ADD #(32) add2(
    .a(a),
    .b(c),
    .sum(e)
);

SUB #(32) sub1(
    .a(a),
    .b(b),
    .diff(f)
);

COMP #(32) comp1(
    .a(d),
    .b(e),
    .lt(dLTe),
    .eq(dEQe)
);

MUX2x1 #(32) mux1(
    .a(d),
    .b(e),
    .sel(dLTe),
    .d(g)
);

MUX2x1 #(32) mux2(
    .a(g),
    .b(f),
    .sel(dEQe),
    .d(h)
);

SHL #(32) shl1(
    .a(g),
    .sh_amt(dLTe),
    .d(xwire)
);

SHR #(32) shr1(
    .a(h),
    .sh_amt(dEQe),
    .d(zwire)
);

REG #(32) reg1(
    .d(xwire),
    .Clk(Clk),
    .Rst(Rst),
    .q(x)
);

REG #(32) reg2(
    .d(zwire),
    .Clk(Clk),
    .Rst(Rst),
    .q(z)
);

endmodule
