`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:39:14 09/16/2016 
// Design Name: 
// Module Name:    Circuit7 
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
module Circuit7(a,b,c,d,zero,z,Clk,Rst);

input Clk,Rst;
input [63:0] a,b,c,d,zero;
output [63:0] z;

wire [63:0] e,f,g,zwire;
wire gEQz;



	MUL #(64) first_mul(
		
		.a(a),
		.b(1/b),
		.prod(e)
	);
	
	MUL #(64) second_mul(
		
		.a(c),
		.b(1/d),
		.prod(f)
	);	

	ADD #(64) first_add(
		.a(0),
		.b(a%b),
		.sum(g)
	);
	
	COMP #(64) first_comp(
		
		.a(g),
		.b(zero),
		.gt(),
		.lt(),
		.eq(gEQz)
	);
	
	MUX2x1 #(64) first_mux(
		
		.a(e),
		.b(f),
		.sel(gEQz),
		.d(zwire)
	);
	
	REG #(64) sixth_reg(
	
		.Clk(Clk),
		.Rst(Rst),
		.d(zwire),
		.q(z)
	);
	
endmodule
