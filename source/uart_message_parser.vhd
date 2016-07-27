
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.ALL;

entity uart_message_parser is
generic
(
--these are all in bytes
  gADDRESS_WIDTH           : natural := 1;
  gLEN_SUM_FIELD_WIDTH     : natural := 1;
  gPAYLOAD_WIDTH           : natural := 4
);
port
(
  CLK          : in  std_logic;
  RESET        : in  std_logic;
  NEW_BYTE_READY : in std_logic;
  NEW_BYTE       : in std_logic_vector(7 downto 0);
  --these have the *8 behind all of them to get the vector sizes in bytes because the generics are in bytes
  TO_ADDRESS     : out std_logic_vector(((gADDRESS_WIDTH * 8) - 1) downto 0);
  FROM_ADDRESS   : out std_logic_vector(((gADDRESS_WIDTH * 8) - 1) downto 0);
  LEN_SUM_FIELD  : out std_logic_vector(((gLEN_SUM_FIELD_WIDTH * 8) - 1) downto 0);
  PAYLOAD        : out std_logic_vector(((gPAYLOAD_WIDTH * 8) - 1) downto 0);
  VALID          : out std_logic
);
end uart_message_parser;
architecture rtl of uart_message_parser is

  type state_t is (STATE_IDLE, STATE_TO_ADDRESS, STATE_FROM_ADDRESS, STATE_LEN_SUM_FIELD, STATE_PAYLOAD);
  
  signal state           : state_t;
  signal valid_z         : std_logic;
  signal payload_length  : natural range 0 to ((2 ** gPAYLOAD_WIDTH) - 1);
  signal payload_counter : natural range 0 to ((2 ** gPAYLOAD_WIDTH) - 1);
  
  --signal new_byte_ready  : std_logic;
  -- input from uart interface that lets us know a new byte has arrived
  --signal new_byte        : std_logic_vector(7 downto 0);
  -- input signal from uart interface that holds the new byte when it is available

begin

update_state : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
      state <= STATE_IDLE;
	  VALID <= '0';
	  payload_counter <= 0;
	  payload_length <= 0;
    elsif(new_byte_ready = '1') then
      CASE state is
	    when STATE_IDLE =>
		  state <= STATE_TO_ADDRESS;
		  TO_ADDRESS <= new_byte;
		  
		when STATE_TO_ADDRESS =>
		  STATE <= STATE_FROM_ADDRESS;
		  FROM_ADDRESS <= new_byte;
		  
		when STATE_FROM_ADDRESS =>
		  STATE <= STATE_LEN_SUM_FIELD;
		  LEN_SUM_FIELD <= new_byte;
		  payload_length <= to_integer(unsigned(new_byte(7 downto 6)));  -- only top 2 bits here are payload length in bytes
		  payload_counter <= 0;
		  
		when STATE_LEN_SUM_FIELD =>
		  PAYLOAD(7 downto 0) <= new_byte;
		  if(payload_length = 1) then
		    state <= STATE_IDLE;
			VALID <= '1';
		  else
		    payload_counter <= 1;
			state <= STATE_PAYLOAD;
		  end if;
		  
		when STATE_PAYLOAD =>
		  PAYLOAD((((payload_counter + 1) * 8) - 1) downto ((payload_counter) * 8)) <= new_byte;
		  if(payload_counter = payload_length - 1) then
		    state <= STATE_IDLE;
			payload_counter <= 0;
			VALID <= '1';
		  else
		    state <= STATE_PAYLOAD;
			payload_counter <= payload_counter + 1;
			
		  end if;
		  
	  end case;
	else
	  VALID <= '0';
    end if;
  end if;
end process;

end rtl;