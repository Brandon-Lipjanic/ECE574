`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:14:35 09/11/2016 
// Design Name: 
// Module Name:    COMP 
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
module COMP(a,b,gt,lt,eq);

	parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a,b;
	output reg gt,lt,eq;

	always @(a,b) begin
	
		if ( a > b) begin
			gt <= 1;
			lt <= 0;
			eq <= 0;
		end
		
		else if (a < b) begin
			gt <= 0;
			lt <= 1;
			eq <= 0;
		end
		
		else if (a == b) begin
			gt <= 0;
			lt <= 0;
			eq <= 0;
		end
		
		else begin
			gt <= 0;
			lt <= 0;
			eq <= 0;
		end
		
	end

endmodule
