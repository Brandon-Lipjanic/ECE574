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
	
	output [7:0] z;
	output [15:0] x;
	
	wire [7:0] d,e;
	wire [15:0] f,g, xwire;
	
	
	
	
	ADD #(8) first_adder(
	
		.a(a),
		.b(b),
		.sum(d)
	);
	
	ADD #(8) second_adder(
		
		.a(a),
		.b(c),
		.sum(e)
	);

	COMP #(8) first_comp(
		
		.a(a),
		.b(b),
		.gt(g),
		.lt(),
		.eq()
	);
	
	MUX2x1 #(8) first_mux(
		
		.a(g),
		.b(d),
		.sel(e),
		.d(z)
	);
	
	MUL #(8) first_mul(
		
		.a(a),
		.b(c),
		.prod(f)
	);
	
	SUB #(8) first_sub(

		.a(f),
		.b(d),
		.diff(xwire)
	);
	
	REG #(8) first_reg(
	
		.Clk(Clk),
		.Rst(Rst),
		.d(xwire),
		.q(x)
	);

endmodule
