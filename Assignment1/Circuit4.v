`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/16/2016 02:58:23 PM
// Design Name: 
// Module Name: Circuit4
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


module Circuit4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, Clk, Rst, afinal);

input [7:0] a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
input Clk, Rst;

output [31:0] afinal;

wire [31:0] t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14;

ADD #(32) add1(
    .a(a),
    .b(b),
    .sum(t1)
);

ADD #(32) add2(
    .a(t1),
    .b(c),
    .sum(t2)
);

ADD #(32) add3(
    .a(t2),
    .b(d),
    .sum(t3)
);

ADD #(32) add4(
    .a(t3),
    .b(e),
    .sum(t4)
);

ADD #(32) add5(
    .a(t4),
    .b(f),
    .sum(t5)
);

ADD #(32) add6(
    .a(t5),
    .b(g),
    .sum(t6)
);

ADD #(32) add7(
    .a(t6),
    .b(h),
    .sum(t7)
);

ADD #(32) add8(
    .a(t7),
    .b(i),
    .sum(t8)
);

ADD #(32) add9(
    .a(t8),
    .b(j),
    .sum(t9)
);

ADD #(32) add10(
    .a(t9),
    .b(l),
    .sum(t10)
);

ADD #(32) add11(
    .a(t10),
    .b(m),
    .sum(t11)
);

ADD #(32) add12(
    .a(t11),
    .b(n),
    .sum(t12)
);

ADD #(32) add13(
    .a(t12),
    .b(o),
    .sum(t13)
);

ADD #(32) add14(
    .a(t13),
    .b(p),
    .sum(t14)
);

REG #(32) reg1(
    .d(t14),
    .Clk(Clk),
    .Rst(Rst),
    .q(afinal)
);


endmodule
