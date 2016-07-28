----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:13:11 02/27/2016 
-- Design Name: 
-- Module Name:    tes_led - Behavioral 
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

entity tes_led is
port
(
  CLK             : in  std_logic;
  nRESET          : in  std_logic;
  LED             : out std_logic_vector(7 downto 0)
);
end tes_led;

architecture Behavioral of tes_led is

begin

update_led : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(nRESET = '1') then
	   LED <= (others => '1');
	 else
	   LED <= (others => '0');
	 end if;
  end if;
end process update_led;

end Behavioral;

