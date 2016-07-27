--switch engine core module

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.ALL;

use work.common.all;

entity switch_engine is
generic
(
  gNUM_PORTS               : natural := 2;
  gADDRESS_WIDTH           : natural := 8;
  gLEN_SUM_FIELD_WIDTH     : natural := 8;
  gMAX_PAYLOAD_LENGTH      : natural := 4 --this is in bytes
  --number of ports that are being switch over
);
port
(
  CLK             : in  std_logic;
  RESET           : in  std_logic;
  
  PACKET_READY              : in std_logic_vector((gNUM_PORTS - 1) downto 0);
  PORT_IN_DATA              : in  slv2d8((gNUM_PORTS - 1) downto 0);
  PORT_IN_DATA_TAKEN        : out std_logic_vector((gNUM_PORTS - 1) downto 0);
  PORT_IN_PACKET_REMOVED    : out std_logic_vector((gNUM_PORTS - 1) downto 0);
  PORT_OUT_DATA             : out slv2d8((gNUM_PORTS - 1) downto 0);
  PORT_OUT_VALID            : out std_logic_vector((gNUM_PORTS - 1) downto 0);
  LED                       : out std_logic_vector(7 downto 0)
  
);
end switch_engine;
architecture rtl of switch_engine is

  type state_t is (STATE_IDLE, STATE_TO_ADDRESS_IN, STATE_FROM_ADDRESS_IN,
                   STATE_LEN_SUM_IN, STATE_PAYLOAD_IN, STATE_TO_ADDRESS_OUT,
				       STATE_FROM_ADDRESS_OUT, STATE_LEN_SUM_OUT, STATE_PAYLOAD_OUT, STATE_NEXT_PORT);
  
  signal state              : state_t;
  --these are for looking up the address in the address table
  signal to_address         : std_logic_vector((gADDRESS_WIDTH - 1) downto 0);
  signal to_port            : natural range 0 to (gNUM_PORTS - 1);
  --need to implement address table module inside the switch engine for look ups
  
  
  signal port_select        : natural range 0 to (gNUM_PORTS - 1);
  signal port_lookup_out    : natural range 0 to (gNUM_PORTS - 1);

  signal from_address       : std_logic_vector((gADDRESS_WIDTH - 1) downto 0);
  signal len_sum_field      : std_logic_vector((gLEN_SUM_FIELD_WIDTH - 1) downto 0);
  signal payload            : slv2d8((gMAX_PAYLOAD_LENGTH - 1) downto 0);
  signal payload_length     : natural range 0 to 4;
  signal payload_counter    : natural range 0 to 4;
  
  constant cCLOCKS_PER_STATE : natural := 5;
  signal state_clock_counter : natural range 0 to (cCLOCKS_PER_STATE - 1);
  
begin

--update the state variable that helps keep the look up of an address in sync with the action
--of switch by ensuring it is a two clock process since the lookup is in BRAM and takes a clock
update_state : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  state <= STATE_IDLE;
	--elsif(PACKET_READY(port_select) = '1') then
	else
	  case state is
	    when STATE_IDLE =>
		  if(PACKET_READY(port_select) = '1') then
		    state <= STATE_TO_ADDRESS_IN;
		  else
		    state <= STATE_NEXT_PORT;
		  end if;
		  
		when STATE_TO_ADDRESS_IN =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    state <= STATE_FROM_ADDRESS_IN;
		  end if;
		  
		when STATE_FROM_ADDRESS_IN =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    state <= STATE_LEN_SUM_IN;
		  end if;
		  
		when STATE_LEN_SUM_IN =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    state <= STATE_PAYLOAD_IN;
		  end if;

		when STATE_PAYLOAD_IN =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    if(payload_counter >= payload_length - 1) then
		      state <= STATE_TO_ADDRESS_OUT;
		    else
		      state <= STATE_PAYLOAD_IN;
          end if;
		  end if;
		  
		when STATE_TO_ADDRESS_OUT =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    state <= STATE_FROM_ADDRESS_OUT;
		  end if;
		  
		when STATE_FROM_ADDRESS_OUT =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    state <= STATE_LEN_SUM_OUT;
		  end if;
		  
		when STATE_LEN_SUM_OUT =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    state <= STATE_PAYLOAD_OUT;
		  end if;

		when STATE_PAYLOAD_OUT =>
		  if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		    if(payload_counter >= payload_length - 1) then
		      state <= STATE_NEXT_PORT;
		    else
            state <= STATE_PAYLOAD_OUT;
          end if;			 
		  end if;
		 
		when STATE_NEXT_PORT =>
		  state <= STATE_IDLE;
      end case;
	end if;
  end if;
end process update_state;

update_state_clock_counter : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   state_clock_counter <= 0;
	 elsif(state = STATE_IDLE or state = STATE_NEXT_PORT) then
	   state_clock_counter <= 0;
	 else
	   if(state_clock_counter = cCLOCKS_PER_STATE - 1) then
		  state_clock_counter <= 0;
		else
		  state_clock_counter <= state_clock_counter + 1;
		end if;
	 end if;
  end if;
end process;

update_port_select : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  port_select <= 0;
	elsif(state = STATE_NEXT_PORT) then
	  if(port_select = (gNUM_PORTS - 1)) then
	    port_select <= 0;
	  else
	    port_select <= port_select + 1;
	  end if;
	end if;
  end if;
end process update_port_select;

update_payload_counter : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  payload_counter <= 0;
	elsif(state_clock_counter = cCLOCKS_PER_STATE - 1 and (state = STATE_PAYLOAD_IN or state = STATE_PAYLOAD_OUT)) then
	  payload_counter <= payload_counter + 1;
	elsif((state /= STATE_PAYLOAD_IN and state /= STATE_PAYLOAD_OUT)) then
	  payload_counter <= 0;
	end if;
  end if;
end process update_payload_counter;

update_data_taken : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  PORT_IN_DATA_TAKEN <= (others => '0');
	else
	 PORT_IN_DATA_TAKEN <= (others => '0');
	 --(state = STATE_IDLE and PACKET_READY(port_select) = '1') or 
	 if((state = STATE_TO_ADDRESS_IN or state = STATE_FROM_ADDRESS_IN or
	    state = STATE_LEN_SUM_IN or state = STATE_PAYLOAD_IN) and state_clock_counter = 0) then
		PORT_IN_DATA_TAKEN(port_select) <= '1';
      end if;
	end if;
  end if;
end process update_data_taken;

update_packet_removed : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	   PORT_IN_PACKET_REMOVED <= (others => '0');
	 elsif(state = STATE_PAYLOAD_OUT and payload_counter = payload_length - 1 and state_clock_counter = (cCLOCKS_PER_STATE - 1)) then
      PORT_IN_PACKET_REMOVED(port_select) <= '1';
	 else
	   PORT_IN_PACKET_REMOVED <= (others => '0');
    end if;
  end if;
end process update_packet_removed;

update_to_address : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  to_address <= (others => '0');
	elsif(state = STATE_TO_ADDRESS_IN and state_clock_counter = 0) then
	  to_address <= PORT_IN_DATA(port_select);
	end if;
  end if;
end process update_to_address;

update_from_address : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  from_address <= (others => '0');
	  --LED <= (others => '0');
	elsif(state = STATE_FROM_ADDRESS_IN and state_clock_counter = 0) then
	  from_address <= PORT_IN_DATA(port_select);
	  --LED <= PORT_IN_DATA(port_select);
	end if;
  end if;
end process update_from_address;

update_len_sum_field : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  len_sum_field <= (others => '0');
	  payload_length <= 0;
	elsif(state = STATE_LEN_SUM_IN and state_clock_counter = 0) then
	  
	  len_sum_field <= PORT_IN_DATA(port_select);
	  payload_length <= (to_integer(unsigned(PORT_IN_DATA(port_select)(7 downto 6))) + 1);
	  --LED(2 downto 1) <= PORT_IN_DATA(port_select)(7 downto 6);
	end if;
  end if;
end process update_len_sum_field;

update_payload : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  payload <= (others => (others => '0'));
	  LED <= (others => '0');
	elsif(state = STATE_PAYLOAD_IN and state_clock_counter = 0) then
	  payload(payload_counter) <= PORT_IN_DATA(port_select);
	  LED <= PORT_IN_DATA(port_select);
	end if;
  end if;
end process update_payload;

update_data_out : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  PORT_OUT_DATA <= (others => (others => '0'));
	  --LED <= (others => '0');
	elsif(state = STATE_TO_ADDRESS_OUT and state_clock_counter = 0) then
	  PORT_OUT_DATA(port_lookup_out) <= to_address;
	  --LED <= to_address;
	elsif(state = STATE_FROM_ADDRESS_OUT  and state_clock_counter = 0) then
	  PORT_OUT_DATA(port_lookup_out) <= from_address;
	  --LED <= from_address;
	elsif(state = STATE_LEN_SUM_OUT  and state_clock_counter = 0) then
	  PORT_OUT_DATA(port_lookup_out) <= len_sum_field;
	  --LED <= len_sum_field;
	elsif(state = STATE_PAYLOAD_OUT  and state_clock_counter = 0) then
	  PORT_OUT_DATA(port_lookup_out) <= payload(payload_counter);
	  --LED <= payload(payload_counter);
	end if;
  end if;
end process update_data_out;

update_data_out_valid : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  --LED <= (others => '0');
	  PORT_OUT_VALID <= (others => '0');
	--elsif(state_clock_counter = 0 and (state = STATE_TO_ADDRESS_OUT or state = STATE_FROM_ADDRESS_OUT or
	  --    state = STATE_LEN_SUM_OUT or state = STATE_PAYLOAD_OUT)) then
	  --PORT_OUT_VALID(port_lookup_out) <= '1';
	elsif(state = STATE_TO_ADDRESS_OUT and state_clock_counter = 0) then
	  PORT_OUT_VALID(port_lookup_out) <= '1';
	  --LED(0) <= '1';
	elsif(state = STATE_FROM_ADDRESS_OUT  and state_clock_counter = 0) then
	  PORT_OUT_VALID(port_lookup_out) <= '1';
	  --LED(1) <= '1';
	elsif(state = STATE_LEN_SUM_OUT  and state_clock_counter = 0) then
	  PORT_OUT_VALID(port_lookup_out) <= '1';
	  --LED(2) <= '1';
	elsif(state = STATE_PAYLOAD_OUT  and state_clock_counter = 1) then
	  PORT_OUT_VALID(port_lookup_out) <= '1';
	  --LED(3) <= '1';
	else
	  PORT_OUT_VALID(port_lookup_out) <= '0';
	end if;
  end if;
end process update_data_out_valid;

address_lookup : process(CLK)
begin
  if(rising_edge(CLK)) then
    if(RESET = '1') then
	  port_lookup_out <= 0;
	else
	 if(state = STATE_FROM_ADDRESS_IN  and state_clock_counter = 0) then
	   if(to_integer(unsigned(to_address)) > -1 and to_integer(unsigned(to_address)) < gNUM_PORTS) then
		  port_lookup_out <= to_integer(unsigned(to_address));
		else
		  port_lookup_out <= 0;
		end if;
	 end if;
  end if;
  end if;
end process address_lookup;

--switch_packet : process(CLK)
--begin
--  if(rising_edge(CLK)) then
--    if(RESET = '0') then
--	  DATA_TAKENS <= (others => '0');  -- mark all data takens as inactive so it doesn't stay high
--	  VALIDS <= (others => '0');       -- mark all data valids as inactive so it doesn't stay high
--	else
--	  DATA_TAKENS <= (others => '0');  -- mark all data takens as inactive so it doesn't stay high
--	  VALIDS <= (others => '0');       -- mark all data valids as inactive so it doesn't stay high
--	  if(state = STATE_SWITCH and DATA_AVAILABLE_IN(port_select) = '1') then
--	    --switch the packet
--	    TO_ADDRESSES_OUT(port_lookup_out) <= TO_ADDRESSES_IN(port_select);
--	    FROM_ADDRESSES_OUT(port_lookup_out) <= FROM_ADDRESSES_IN(port_select);
--	    LEN_SUM_FIELDS_OUT(port_lookup_out) <= LEN_SUM_FIELDS_IN(port_select);
--	    PAYLOADS_OUT(port_lookup_out) <= PAYLOADS_IN(port_select);
--		DATA_TAKENS(port_select) <= '1';  -- pop the switched data off the input fifo
--		VALIDS(port_lookup_out) <= '1';  -- add the switched data onto the correct output fifo
--	  end if;
--    end if;
--  end if;
--end process switch_packet;

--LED(0) <= PACKET_READY(0);
--LED(7 downto 3) <= (others => '0');

end rtl;