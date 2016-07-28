--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   19:05:44 05/03/2015
-- Design Name:   
-- Module Name:   D:/Nate/dev/FPGA stuff/fpgaProjects/fifo/fifo_tb.vhd
-- Project Name:  fifo
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: fifo
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
 
ENTITY fifo_tb IS
END fifo_tb;
 
ARCHITECTURE behavior OF fifo_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT fifo
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         DATA_IN : IN  std_logic_vector(7 downto 0);
         ADD_DATA : IN  std_logic;
         REMOVE_DATA : IN  std_logic;
         DATA_OUT : OUT  std_logic_vector(7 downto 0);
         HAS_DATA : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal DATA_IN : std_logic_vector(7 downto 0) := (others => '0');
   signal ADD_DATA : std_logic := '0';
   signal REMOVE_DATA : std_logic := '0';
	
	constant test_data : std_logic_vector(7 downto 0) := ('1', '0', '1', '0', '1', '0', '1', '0');
	constant test_data2 : std_logic_vector(7 downto 0) := ('1', '1', '1', '1', '1', '0', '1', '0');

 	--Outputs
   signal DATA_OUT : std_logic_vector(7 downto 0);
   signal HAS_DATA : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: fifo PORT MAP (
          CLK => CLK,
          RESET => RESET,
          DATA_IN => DATA_IN,
          ADD_DATA => ADD_DATA,
          REMOVE_DATA => REMOVE_DATA,
          DATA_OUT => DATA_OUT,
          HAS_DATA => HAS_DATA
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
      RESET <= '1';
		wait for CLK_period;
		RESET <= '0';
		wait for CLK_period;
		
		  DATA_IN <= test_data;
		  ADD_DATA <= '1';
		  wait for CLK_period;
		  DATA_IN <= test_data2;
		  ADD_DATA <= '0';
		  wait for CLK_period;
		  DATA_IN <= test_data;
		  ADD_DATA <= '1';
		  wait for CLK_period;
		  DATA_IN <= test_data2;
		  ADD_DATA <= '1';
		  wait for CLK_period;

      for I in 0 to 15 loop
		  DATA_IN <= test_data;
		  ADD_DATA <= '1';
		  wait for CLK_period;
		  DATA_IN <= test_data2;
		  ADD_DATA <= '1';
		  wait for CLK_period;
		end loop;
		ADD_DATA <= '0';
		for I in 0 to 15 loop
		  --DATA_IN <= test_data;
		  REMOVE_DATA <= '1';
		  wait for CLK_period;
		end loop;

      -- insert stimulus here 

      wait;
   end process;

END;
