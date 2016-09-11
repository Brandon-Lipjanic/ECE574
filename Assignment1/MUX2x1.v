`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:17:37 09/11/2016 
// Design Name: 
// Module Name:    MUX2x1 
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
module MUX2x1(a,b,sel,d);

	parameter DATAWIDTH = 2;
	input  [DATAWIDTH-1 : 0] a, b;
	input sel;

	output reg [DATAWIDTH-1 :0] d;

	always@(a, b,sel) begin
		if(sel == 1) begin
			d <= b;
		end
		
		if(sel == 0) begin
			d <= a;
		end
	end


endmodule
