--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:27:04 02/29/2016
-- Design Name:   
-- Module Name:   D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/top_tb.vhd
-- Project Name:  serial_switch
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: top
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

use work.common.all;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY top_tb IS
END top_tb;
 
ARCHITECTURE behavior OF top_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT top
    PORT(
         CLK : IN  std_logic;
         nRESET : IN  std_logic;
         UART_RX_PINS : IN  std_logic_vector(1 downto 0);
         UART_TX_PINS : OUT  std_logic_vector(1 downto 0);
         LED : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal nRESET : std_logic := '0';
   signal UART_RX_PINS : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal UART_TX_PINS : std_logic_vector(1 downto 0);
   signal LED : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
	
	signal rx_in_data   : slv2d8(3 downto 0) := ( ('0', '0', '0', '0', '0', '0', '0', '0'), ('0', '0', '0', '0', '0', '0', '0', '1'),
	                                              ('0', '0', '0', '0', '0', '0', '1', '0'), ('0', '0', '0', '0', '0', '0', '1', '1'));
																 
	signal rx_bit_counter : natural range 0 to 9 := 0;
	signal rx_byte_counter : natural range 0 to 3 := 3;
	
	signal rx_bit_in : std_logic := '0';
	signal start     : std_logic := '0';
	
	constant clocks_per_uart_bit : natural := 416;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: top PORT MAP (
          CLK => CLK,
          nRESET => nRESET,
          UART_RX_PINS => UART_RX_PINS,
          UART_TX_PINS => UART_TX_PINS,
          LED => LED
        );
		  
   UART_RX_PINS(0) <= rx_bit_in;

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   gen_counts : process
	begin
	  if(nRESET = '0') then
	    rx_bit_counter <= 0;
		 rx_byte_counter <= 3;
		 wait for CLK_period;
	 else
	  if(rx_bit_counter = 9) then
	    rx_bit_counter <= 0;
		 if(rx_byte_counter = 0) then
		   rx_byte_counter <= 3;
		 else
		   rx_byte_counter <= rx_byte_counter - 1;
		 end if;
	  else
	    rx_bit_counter <= rx_bit_counter + 1;
	  end if;
	  wait for CLK_period * clocks_per_uart_bit;
	 end if;
	end process;

	gen_rx_bit_in : process
	begin
	  if(nRESET = '0') then
	    rx_bit_in <= '1';
	  elsif(rx_bit_counter = 0) then
	    rx_bit_in <= '0'; --start bit
	  elsif(rx_bit_counter = 9) then
	    rx_bit_in <= '1'; --stop bit
	  else
	    rx_bit_in <= rx_in_data(rx_byte_counter)(rx_bit_counter-1); -- data bit
	  end if;
	  wait for CLK_period;
	end process;

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		nRESET <= '0';
		--UART_RX_PINS(1) <= '1';
      wait for CLK_period * 52;
		nRESET <= '1';
		start <= '1';
		wait for CLK_period * clocks_per_uart_bit * 4 * 8;
		

		
      wait for CLK_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
