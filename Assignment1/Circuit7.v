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



	DIV #(64) first_div(
		
		.a(a),
		.b(b),
		.prod(e)
	);
	
	DIV #(64) second_div(
		
		.a(c),
		.b(d),
		.prod(f)
	);	

	MOD #(64) first_mod(
		.a(a),
		.b(b),
		.rem(g)
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
