`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:17:38 09/16/2016 
// Design Name: 
// Module Name:    DIV 
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
module DIV(a,b,quot);

parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a,b;
	output reg [DATAWIDTH-1:0] quot;

	always @(a,b) begin
	
		quot <= a / b;
		
	end

endmodule
