`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:40:54 09/16/2016 
// Design Name: 
// Module Name:    Circuit6 
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
module Circuit6(a,b,c,d,e,f,g,h,num,avg,Clk,Rst);

input [15:0] a,b,c,d,e,f,g,h,num;
input Clk,Rst;
output [15:0] avg;
wire [15:0] r1,r2,r3,r4,r5,r6,r7;

wire [15:0] avgwire;
wire [31:0] t1,t2,t3,t4,t5,t6,t7;


	
	ADD #(16) first_adder(
		
		.a(a),
		.b(b),
		.sum(t1)
	);
	
	REG #(16) first_reg(
	
		.Clk(Clk),
		.Rst(Rst),
		.d(xwire),
		.q(x)
	);
	
	ADD #(16) second_adder(
		
		.a(r1),
		.b(c),
		.sum(t2)
	);
	
	REG #(16) second_reg(
		
		.Clk(Clk),
		.Rst(Rst),
		.d(t2),
		.q(r2)
	);	
	
	ADD #(16) third_adder(
		
		.a(r2),
		.b(d),
		.sum(t3)
	);

	REG #(16) third_reg(
	
		.Clk(Clk),
		.Rst(Rst),
		.d(t3),
		.q(r3)
	);	
	
	ADD #(16) fourth_adder(
	
		.a(r3),
		.b(e),
		.sum(t4)
	);
	
	REG #(16) fourth_reg(
		
		.Clk(Clk),
		.Rst(Rst),
		.d(t4),
		.q(r4)
	);	
	
	ADD #(16) fifth_adder(
		
		.a(r4),
		.b(f),
		.sum(t5)
	);
	
	REG #(16) fifth_reg(
		
		.Clk(Clk),
		.Rst(Rst),
		.d(t5),
		.q(r5)
	);	
	
	ADD #(16) sixth_adder(

		.a(r5),
		.b(g),
		.sum(t6)
	);
	
	REG #(16) sixth_reg(
	
		.Clk(Clk),
		.Rst(Rst),
		.d(t6),
		.q(r6)
	);
	
	ADD #(16) seventh_adder(
		
		.a(r7),
		.b(h),
		.sum(t7)
	);
	
	REG #(16) seventh_reg(
		
		.Clk(Clk),
		.Rst(Rst),
		.d(t7),
		.q(r7)
	);
	
	MUL #(16) first_mul(
	
		.a(r7),
		.b(1/num),
		.prod(avgwire)
	);
	
	REG #(16) eigth_reg(

		.Clk(Clk),
		.Rst(Rst),
		.d(avgwire),
		.q(avg)
	);
	
	
	
	
	
	
	
	

	
	



endmodule
