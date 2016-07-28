----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:17:23 02/22/2016 
-- Design Name: 
-- Module Name:    uart_interface - rtl 
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

entity uart_interface is
port
(
  CLK                 : in  std_logic;
  RESET               : in  std_logic;
  NEW_DATA_AVAILABLE  : in  std_logic;
  NEW_DATA            : in  std_logic_vector(7 downto 0);
  UART_RX_PIN         : in  std_logic;
  VALID               : out std_logic;
  NEW_DATA_TAKEN      : out std_logic;
  UART_DATA_OUT       : out std_logic_vector(7 downto 0);
  UART_TX_PIN         : out std_logic
  --LED                 : out std_logic_vector(7 downto 0)
);
end uart_interface;

architecture rtl of uart_interface is

  component uart_tx
  port
  (
    CLK                : in  std_logic;
    RESET		 	   : in  std_logic;
    NEW_DATA_PRESENT   : in  std_logic;
    NEW_DATA           : in  std_logic_vector(7 downto 0);
    DATA_TAKEN         : out std_logic;
    TX_PIN             : out std_logic
  );
  end component;
  
  component uart_rx
  port
  (
    CLK         : in  std_logic;
    RESET       : in  std_logic;
    RX_PIN      : in  std_logic;
    RX_DATA     : out std_logic_vector(7 downto 0);
    VALID       : out std_logic
  );
  end component;

	constant cUART_CLOCK_DIV    : natural := 27;--325 for 9600 baud; --27 for 115200 3 for 1 Mhz
	constant cCLOCK_DELAY       : natural := 100;
	--signal delay_counter        : natural range 0 to (cCLOCK_DELAY - 1);
	signal uart_clock           : std_logic;
	signal clock_counter        : natural range 0 to (cUART_CLOCK_DIV - 1);
	
	signal uart_tx_reset        : std_logic;
	
	signal uart_rx_data         : std_logic_vector(7 downto 0);
	signal uart_tx_data         : std_logic_vector(7 downto 0);
	signal uart_rx_valid        : std_logic;
	signal uart_rx_valid2       : std_logic;
   signal uart_data_taken      : std_logic;
	signal uart_data_taken2     : std_logic;	
	
	signal led_data             : std_logic_vector(7 downto 0);
	
begin

uart_tx_component : uart_tx port map
(
  CLK => uart_clock,
  RESET => RESET,
  NEW_DATA_PRESENT => NEW_DATA_AVAILABLE,
  NEW_DATA => NEW_DATA,
  DATA_TAKEN => uart_data_taken,
  TX_PIN => UART_TX_PIN
);

uart_rx_component : uart_rx port map
(
  CLK => uart_clock,
  RESET => RESET,
  RX_PIN => UART_RX_PIN,
  RX_DATA => UART_DATA_OUT,
  VALID => uart_rx_valid--VALID
);

update_rx_valid : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   uart_rx_valid2 <= '0';
		VALID <= '0';
	 else
	   uart_rx_valid2 <= uart_rx_valid;
		if(uart_rx_valid = '1' and uart_rx_valid2 = '0') then --detect rising edge
		  VALID <= '1';
		else
		  VALID <= '0';
		end if;
	 end if;
  end if;
end process update_rx_valid;

update_uart_data_taken : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   uart_data_taken2 <= '0';
		NEW_DATA_TAKEN <= '0';
	 else
	   uart_data_taken2 <= uart_data_taken;
		if(uart_data_taken = '1' and uart_data_taken2 = '0') then --detect rising edge
		  NEW_DATA_TAKEN <= '1';
		else
		  NEW_DATA_TAKEN <= '0';
		end if;
	 end if;
  end if;
end process update_uart_data_taken;

gen_uart_clock : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   uart_clock <= '0';
		clock_counter <= 0;
    elsif(clock_counter = (cUART_CLOCK_DIV - 1)) then
	   clock_counter <= 0;
		uart_clock <= not uart_clock;
	 else
	   clock_counter <= clock_counter + 1;
	 end if;
  end if;
end process gen_uart_clock;

update_leds : process(uart_clock)
begin
  if(rising_edge(uart_clock)) then
    if(uart_rx_valid = '1') then
	   led_data <= uart_rx_data;
	 end if;
  end if;
end process;

--LED <= led_data;


end rtl;

