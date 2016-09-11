`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:31:10 09/11/2016 
// Design Name: 
// Module Name:    SHL 
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
module SHL(a,sh_amt, d);

	parameter DATAWIDTH = 2;
	
	input [DATAWIDTH-1:0] a, sh_amt;
	output reg [DATAWIDTH-1:0] d;
	
	always @(a,sh_amt) begin
	
		d <= (a << sh_amt);
	
	end
	
endmodule
