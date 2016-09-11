`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:59:07 09/11/2016 
// Design Name: 
// Module Name:    REG 
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
module REG(d,Clk,Rst,q);

	parameter DATAWIDTH = 2;
	input [DATAWIDTH-1:0] d;
	input Clk, Rst;
	output [DATAWIDTH-1:0] q;

	reg [DATAWIDTH-1:0] RegData;

	initial begin

		RegData = 0;
		
	end
	
	assign q = RegData;
	
	always@(posedge Clk) begin
	
		RegData <= d;
	
	end

endmodule
