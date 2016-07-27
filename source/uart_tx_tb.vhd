--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:11:49 02/22/2016
-- Design Name:   
-- Module Name:   D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/uart_tx_tb.vhd
-- Project Name:  serial_switch
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: uart_tx
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
 
ENTITY uart_tx_tb IS
END uart_tx_tb;
 
ARCHITECTURE behavior OF uart_tx_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT uart_tx
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         NEW_DATA_PRESENT : IN  std_logic;
         NEW_DATA : IN  std_logic_vector(7 downto 0);
         DATA_TAKEN : OUT  std_logic;
         TX_PIN : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal NEW_DATA_PRESENT : std_logic := '0';
   signal NEW_DATA : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal DATA_TAKEN : std_logic;
   signal TX_PIN : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: uart_tx PORT MAP (
          CLK => CLK,
          RESET => RESET,
          NEW_DATA_PRESENT => '1',
          NEW_DATA => ('1', '0', '1', '0', '1', '0', '1', '0'),
          DATA_TAKEN => DATA_TAKEN,
          TX_PIN => TX_PIN
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
      wait for CLK_period*10;
		RESET <= '0';
		wait for CLK_period*200;
		
		
      -- insert stimulus here 

      wait;
   end process;

END;
