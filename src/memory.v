module RAM #(
	parameter integer WORDS = 256
) (
	input clk,
	input en,
	input [3:0] wen,
	input [21:0] addr,
	input [31:0] wdata,
	output reg [31:0] rdata
);
	reg [31:0] mem [0:WORDS-1];

	always @(posedge clk) begin
		if(en)
			if (wen) mem[addr] <= wdata;
	        else rdata <= mem[addr];
	end
endmodule