`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:21:30 09/16/2016 
// Design Name: 
// Module Name:    DEC 
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
module DEC(a,d);

parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a;
	output reg [DATAWIDTH-1:0] d;

	always @(a) begin
	
		d <= a - 1;
		
	end


endmodule
