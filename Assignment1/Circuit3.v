`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/16/2016 02:58:08 PM
// Design Name: 
// Module Name: Circuit3
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


module Circuit3(a, b, c, d, e, f, g, h, sa, Clk, Rst, avg);

input [15:0] a, b, c, d, e, f, g, h;
input [7:0] sa;
input Clk, Rst;

output [15:0] avg;

wire [31:0] a100, a101, a102, a103, a110, a111, a12, a12div2, a12div4, a12div8;

ADD #(32) add1(
    .a(a),
    .b(b),
    .sum(a100)
);

ADD #(32) add2(
    .a(c),
    .b(d),
    .sum(a101)
);

ADD #(32) add3(
    .a(e),
    .b(f),
    .sum(a102)
);

ADD #(32) add4(
    .a(g),
    .b(h),
    .sum(a103)
);

ADD #(32) add5(
    .a(a100),
    .b(a101),
    .sum(a110)
);

ADD #(32) add6(
    .a(a102),
    .b(a103),
    .sum(a111)
);

ADD #(32) add7(
    .a(a110),
    .b(a111),
    .sum(a12)
);

SHR #(32) shr1(
    .a(a12),
    .sh_amt(sa),
    .d(a12div2)
);

SHR #(32) shr2(
    .a(a12div2),
    .sh_amt(sa),
    .d(a12div4)
);

SHR #(32) shr3(
    .a(a12div4),
    .sh_amt(sa),
    .d(a12div8)
);

REG #(32) reg1(
    .d(a12div8),
    .Clk(Clk),
    .Rst(Rst),
    .q(avg)
);

endmodule
