`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:39:36 09/11/2016 
// Design Name: 
// Module Name:    Circuit1 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Circuit1(a,b,c,z,x,Clk,Rst);

	input Clk,Rst;
	input [7:0] a,b,c;
	
	output reg [7:0] z;
	output reg [15:0] x;
	
	wire [7:0] d,e;
	wire [15:0] f,g, xwire;
	
	int datawidth = 2;
	
	ADD first_adder(
		.DATAWIDTH(datawidth),
		.a(a),
		.b(b),
		.sum(d)
	);
	
	ADD second_adder(
		.DATAWIDTH(datawidth),
		.a(a),
		.b(c),
		.sum(e),
	);

	COMP first_comp(
		.a(a),
		.b(b),
		.gt(g),
		.lt(),
		.eq(),
	);
	
	MUX2x1 first_mux(
		.a(g),
		.b(d),
		.sel(e),
		.d(z)
	);
	
	MUL first_mul(
		.a(a),
		.b(c),
		.f(prod)
	);
	
	SUB first_sub(
		.a(f),
		.b(d),
		.d(xwire)
	);
	
	REG first_reg(
		.Clk(Clk),
		.Rst(Rst),
		.d(xwire),
		.q(x)
	);

endmodule
