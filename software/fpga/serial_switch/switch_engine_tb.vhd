--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:33:27 02/28/2016
-- Design Name:   
-- Module Name:   D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/switch_engine_tb.vhd
-- Project Name:  serial_switch
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: switch_engine
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
 
ENTITY switch_engine_tb IS
END switch_engine_tb;
 
ARCHITECTURE behavior OF switch_engine_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT switch_engine
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         PACKET_READY : IN  std_logic_vector(1 downto 0);
         PORT_IN_DATA : IN  slv2d8(1 downto 0);
         PORT_IN_DATA_TAKEN : OUT  std_logic_vector(1 downto 0);
         PORT_IN_PACKET_REMOVED : OUT  std_logic_vector(1 downto 0);
         PORT_OUT_DATA : OUT  slv2d8(1 downto 0);
         PORT_OUT_VALID : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal PACKET_READY : std_logic_vector(1 downto 0) := (others => '0');
   signal PORT_IN_DATA : slv2d8(1 downto 0) := (others => (others => '0'));

 	--Outputs
   signal PORT_IN_DATA_TAKEN : std_logic_vector(1 downto 0);
   signal PORT_IN_PACKET_REMOVED : std_logic_vector(1 downto 0);
   signal PORT_OUT_DATA : slv2d8(1 downto 0);
   signal PORT_OUT_VALID : std_logic_vector(1 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: switch_engine PORT MAP (
          CLK => CLK,
          RESET => RESET,
          PACKET_READY => ('0', '1'),
          PORT_IN_DATA => (('1', '0', '1', '0', '1', '0', '1', '0'), ('1', '0', '1', '0', '1', '0', '1', '0')),
          PORT_IN_DATA_TAKEN => PORT_IN_DATA_TAKEN,
          PORT_IN_PACKET_REMOVED => PORT_IN_PACKET_REMOVED,
          PORT_OUT_DATA => PORT_OUT_DATA,
          PORT_OUT_VALID => PORT_OUT_VALID
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
      wait for CLK_period;
		RESET <= '1';
		wait for CLK_period;
		RESET <= '0';
      wait for CLK_period*20;

      -- insert stimulus here 

      wait;
   end process;

END;
