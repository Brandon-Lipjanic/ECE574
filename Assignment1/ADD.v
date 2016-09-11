`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:08:08 09/11/2016 
// Design Name: 
// Module Name:    ADD 
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
module ADD(a,b,sum);

	parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a,b;
	output reg [DATAWIDTH-1:0] sum;

	always @(a,b) begin
	
		sum <= a + b;
		
	end


endmodule
