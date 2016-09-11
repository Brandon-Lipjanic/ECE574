`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:13:29 09/11/2016 
// Design Name: 
// Module Name:    MUL 
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
module MUL(a,b,prod);

	parameter DATAWIDTH = 2;

	input [DATAWIDTH-1:0] a,b;
	output reg [DATAWIDTH-1:0] prod;

	always @(a,b) begin
	
		prod <= a * b;
		
	end

endmodule
