--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:22:08 02/23/2016
-- Design Name:   
-- Module Name:   D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/uart_rx_tb.vhd
-- Project Name:  serial_switch
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: uart_rx
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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY uart_rx_tb IS
END uart_rx_tb;
 
ARCHITECTURE behavior OF uart_rx_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT uart_rx
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         RX_PIN : IN  std_logic;
         RX_DATA : OUT  std_logic_vector(7 downto 0);
         VALID : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal RX_PIN : std_logic := '0';

 	--Outputs
   signal RX_DATA : std_logic_vector(7 downto 0);
   signal VALID : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: uart_rx PORT MAP (
          CLK => CLK,
          RESET => RESET,
          RX_PIN => RX_PIN,
          RX_DATA => RX_DATA,
          VALID => VALID
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		
		RESET <= '1';
		wait for CLK_period;
		RESET <= '0';
		wait for CLK_period;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		
		wait for CLK_period * 8;		
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
      wait for CLK_period*3;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
		wait for CLK_period * 8;
		RX_PIN <= '0';
		wait for CLK_period * 8;
		RX_PIN <= '1';
      wait for CLK_period*3;

      -- insert stimulus here 

      wait;
   end process;

END;
