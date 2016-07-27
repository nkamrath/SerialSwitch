----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:17:54 02/22/2016 
-- Design Name: 
-- Module Name:    uart_tx - rtl 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity uart_tx is
--right now no generics, assumes 1 start bit, 8 data bits, 1 stop bit and 8 clocks per bit to this module
port
(
  CLK                : in  std_logic;
  RESET		 	      : in  std_logic;
  NEW_DATA_PRESENT   : in  std_logic;
  NEW_DATA           : in  std_logic_vector(7 downto 0);
  DATA_TAKEN         : out std_logic;
  TX_PIN             : out std_logic
);
end uart_tx;

architecture rtl of uart_tx is

  constant cSTART_BITS           : natural := 1;
  constant cDATA_BITS            : natural := 8;
  constant cSTOP_BITS            : natural := 1;
  constant cBITS_PER_XFER        : natural := (cSTART_BITS + cDATA_BITS + cSTOP_BITS);
  constant cCLOCKS_PER_BIT       : natural := 8;
  constant cSTART_BIT            : std_logic := '0';
  constant cSTOP_BIT             : std_logic := '1';
  
  signal active_z                : std_logic;
  signal tx_buffer_z             : std_logic_vector((cDATA_BITS - 1) downto 0);
  signal bit_counter_z           : natural range 0 to (cBITS_PER_XFER - 1);
  signal clock_counter_z         : natural range 0 to (cCLOCKS_PER_BIT - 1);
  

begin

update_active : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   active_z <= '0';
	 elsif(active_z = '1' and bit_counter_z = (cBITS_PER_XFER - 1) and clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
	   if(NEW_DATA_PRESENT = '1') then
		  active_z <= '1';
		else
		  active_z <= '0';
		end if;
    elsif(active_z = '0' and NEW_DATA_PRESENT = '1') then
	   active_z <= '1';
	 end if;
  end if;
end process update_active;

update_clock_counter : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   clock_counter_z <= 0;
	 elsif(active_z = '1') then
	   if(clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		  clock_counter_z <= 0;
		else
		  clock_counter_z <= clock_counter_z + 1;
		end if;
	 else
	   clock_counter_z <= 0;
	 end if;
  end if;
end process update_clock_counter;

update_bit_counter : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   bit_counter_z <= 0;
	 elsif(active_z = '1') then
	   if(clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		  if(bit_counter_z = (cBITS_PER_XFER - 1)) then
		    bit_counter_z <= 0;
		  else
		    bit_counter_z <= bit_counter_z + 1;
	     end if;
		end if;
	 else
	   bit_counter_z <= 0;
	 end if;
  end if;
end process update_bit_counter;

update_tx_pin : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   TX_PIN <= '1'; -- idle state for tx pin
	 elsif(active_z = '1' or NEW_DATA_PRESENT = '1') then
	   if((bit_counter_z < cSTART_BITS and clock_counter_z /= (cCLOCKS_PER_BIT - 1))) then-- or
		   --(bit_counter_z = (cBITS_PER_XFER - 1) and clock_counter_z = (cCLOCKS_PER_BIT - 1))) then
		  TX_PIN <= cSTART_BIT;
		elsif(bit_counter_z >= (cSTART_BITS + cDATA_BITS - 1) and clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		  TX_PIN <= cSTOP_BIT;  --otherwise we are at end of transmit, so send stop bit
		elsif(bit_counter_z < (cSTART_BITS + cDATA_BITS)) then
		  TX_PIN <= tx_buffer_z(0);  --LSb first for uart
		end if;
	 else
	   TX_PIN <= '1';  --idle state for tx pin
	 end if;
  end if;
end process update_tx_pin;

update_tx_buffer : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   tx_buffer_z <= (others => '0');
		DATA_TAKEN <= '0';
	 elsif(active_z = '1') then
	   if(bit_counter_z = 0 and clock_counter_z = 0) then
	   --elsif(NEW_DATA_PRESENT = '1' and clock_counter_z = 0 and bit_counter_z = 0) then
		  tx_buffer_z <= NEW_DATA;
		  DATA_TAKEN <= '1';  --indicate that we have flopped in the new data
		else
		  DATA_TAKEN <= '0';
		  if(bit_counter_z > (cSTART_BITS - 1) and clock_counter_z = (cCLOCKS_PER_BIT - 2)) then
		    tx_buffer_z <= '0' & tx_buffer_z(7 downto 1); --bit shift tx buffer down one towards LSb since LSb first
		  end if;
		end if;
	 else
	   tx_buffer_z <= (others => '0');
		DATA_TAKEN <= '0';
	 end if;
  end if;
end process update_tx_buffer;

end rtl;

