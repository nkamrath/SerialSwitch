----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:58:42 02/22/2016 
-- Design Name: 
-- Module Name:    uart_rx - rtl 
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

entity uart_rx is
port
(
  CLK         : in  std_logic;
  RESET       : in  std_logic;
  RX_PIN      : in  std_logic;
  RX_DATA     : out std_logic_vector(7 downto 0);
  VALID       : out std_logic
);
end uart_rx;

architecture rtl of uart_rx is

  constant cSTART_BITS           : natural := 1;
  constant cDATA_BITS            : natural := 8;
  constant cSTOP_BITS            : natural := 1;
  constant cBITS_PER_XFER        : natural := (cSTART_BITS + cDATA_BITS + cSTOP_BITS);
  constant cCLOCKS_PER_BIT       : natural := 16;
  constant cSTART_BIT            : std_logic := '0';
  constant cSTOP_BIT             : std_logic := '1';
  
  signal active_z                : std_logic;
  signal rx_buffer_z             : std_logic_vector((cDATA_BITS - 1) downto 0);
  signal bit_counter_z           : natural range 0 to (cBITS_PER_XFER - 1);
  signal clock_counter_z         : natural range 0 to (cCLOCKS_PER_BIT - 1);
  
  signal rx_m                    : std_logic;
  signal rx_z                    : std_logic;
  signal rx_2z                   : std_logic;
  signal rx_has_fallen_z         : std_logic;
  signal data_bit_polarity       : integer range (-cCLOCKS_PER_BIT+1) to (cCLOCKS_PER_BIT - 1);

begin

update_rx_data : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  rx_m <= '0';
	  rx_z <= '0';
	  rx_z <= '0';
	else
	  rx_m <= RX_PIN;
	  rx_z <= rx_m;
	  rx_2z <= rx_z;
	end if;
  end if;
end process update_rx_data;

update_rx_has_fallen : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  rx_has_fallen_z <= '0';
	else
	  if(rx_2z = '1' and rx_z = '0') then
	    rx_has_fallen_z <= '1';
	  elsif(rx_2z = '0' and rx_z = '1') then
	    rx_has_fallen_z <= '0';
	  end if;
	end if;
  end if;
end process update_rx_has_fallen;

-- update_clock_counter : process(CLK)
-- begin
  -- if(rising_edge(CLK)) then
    -- if(RESET = '1') then
	   -- clock_counter_z <= 0;
	 -- else
	   -- if(clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		  -- clock_counter_z <= 0;
		-- else
		  -- clock_counter_z <= clock_counter_z + 1;
		-- end if;
	 -- else
	   -- clock_counter_z <= 0;
	 -- end if;
  -- end if;
-- end process update_clock_counter;

--
update_data_bit_polarity : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   data_bit_polarity <= 0;
	 else
	   if(clock_counter_z = (cCLOCKS_PER_BIT - 1) or (bit_counter_z = 0 and clock_counter_z = 0)) then
		  data_bit_polarity <= 0;
		else
		  if(rx_z = '0') then
		    data_bit_polarity <= data_bit_polarity - 1;
		  else
		    data_bit_polarity <= data_bit_polarity + 1;
		  end if;
		end if;
	 end if;
  end if;
end process update_data_bit_polarity;

update_bit_counter : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   bit_counter_z <= 0;
	 else
	  if(bit_counter_z = 0) then
	    if(rx_2z = '0' and rx_has_fallen_z = '1') then
		  if(clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		     bit_counter_z <= 1;
	        clock_counter_z <= 0;
		  else
		    clock_counter_z <= clock_counter_z + 1;
		  end if;
		else
		  clock_counter_z <= 0;
		end if;
	  else
	    if(clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		   clock_counter_z <= 0;
		   if(bit_counter_z = (cBITS_PER_XFER - 1)) then
		     bit_counter_z <= 0;
		   else
		     bit_counter_z <= bit_counter_z + 1;
		   end if;
		 else
		   clock_counter_z <= clock_counter_z + 1;
		 end if;
	  end if;
    end if;
  end if;
end process update_bit_counter;

update_rx_buffer : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   rx_buffer_z <= (others => '0');
	 else
		  --if(bit_counter_z > (cSTART_BITS - 1) and bit_counter_z <= (cSTART_BITS + cDATA_BITS - 1) and clock_counter_z = ((cCLOCKS_PER_BIT/2) - 1)) then
		  if(bit_counter_z > (cSTART_BITS - 1) and bit_counter_z <= (cSTART_BITS + cDATA_BITS - 1) and clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
		    --rx_buffer_z <= rx_2z & rx_buffer_z(7 downto 1); --bit shift rx buffer down one towards LSb since LSb first and append RX
			 if(data_bit_polarity >= 0) then
			   rx_buffer_z <= '1' & rx_buffer_z(7 downto 1);
			 else
			   rx_buffer_z <= '0' & rx_buffer_z(7 downto 1);
			 end if;
		  end if;
    end if;
  end if;
end process update_rx_buffer;

update_valid : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   VALID <= '0';
		RX_DATA <= (others => '0');
	 elsif(bit_counter_z = (cSTART_BITS + cDATA_BITS) and clock_counter_z = (cCLOCKS_PER_BIT - 1)) then
	   VALID <= '1';
		RX_DATA <= rx_buffer_z;
	 else
	   VALID <= '0';
	 end if;
  end if;
end process update_valid;

end rtl;

