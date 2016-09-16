`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:23:47 09/16/2016 
// Design Name: 
// Module Name:    Circuit8 
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
module Circuit8(a,b,c,zero,z,Clk,Rst);

input [63:0] a,b,c,zero;
input Clk,Rst;

output [63:0] z;

wire [63:0] e,f,g,zwire;
wire gEQz;

	SUB #(64) first_sub(
	
		.a(a),
		.b(1),
		.diff(e)
	);

	ADD #(64) first_adder(
	
		.a(c),
		.b(1),
		.sum(f)
	);
	
	ADD #(8) second_adder(
	
		.a(0),
		.b(a%c),
		.sum(g)
	);
	
	COMP #(64) first_comp(
		
		.a(g),
		.b(zero),
		.gt(gEQz),
		.lt(),
		.eq()
	);
	
	MUX2x1 #(64) first_mux(
		
		.a(e),
		.b(f),
		.sel(gEQz),
		.d(zwire)
	);
	
	REG #(64) first_reg(
	
		.Clk(Clk),
		.Rst(Rst),
		.d(zwire),
		.q(z)
	);
	

endmodule
