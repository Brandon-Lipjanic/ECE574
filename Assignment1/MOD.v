`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:19:08 09/16/2016 
// Design Name: 
// Module Name:    MOD 
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
module MOD(a,b,rem);

parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a,b;
	output reg [DATAWIDTH-1:0] rem;

	always @(a,b) begin
	
		rem <= a % b;
		
	end



endmodule
