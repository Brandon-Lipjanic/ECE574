`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:19:44 09/16/2016 
// Design Name: 
// Module Name:    INC 
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
module INC(a,d);

parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a;
	output reg [DATAWIDTH-1:0] d;

	always @(a) begin
	
		d <= a + 1;
		
	end



endmodule
