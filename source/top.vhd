----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:16:18 02/22/2016 
-- Design Name: 
-- Module Name:    top - rtl 
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
use work.common.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity top is
generic
(
  gADDRESS_WIDTH             : natural := 8;
  gLEN_SUM_FIELD_WIDTH       : natural := 8;
  gMAX_PAYLOAD_BYTES         : natural := 4;
  gNUM_PORTS                 : natural := 2;
  gFIFO_WIDTH                : natural := 8;
  gFIFO_LENGTH               : natural := 100
);
port
(
  CLK             : in  std_logic;
  nRESET          : in  std_logic;
  
  UART_RX_PINS    : in  std_logic_vector((gNUM_PORTS - 1) downto 0);
  UART_TX_PINS    : out std_logic_vector((gNUM_PORTS - 1) downto 0);
  LED             : out std_logic_vector(7 downto 0)
);
end top;

architecture rtl of top is

  component uart_controller
  generic
  (
    gFIFO_WIDTH         : natural;  -- data width of one more than actual data.  1 in lsb signfies continuation of packet, 0 means last byte of a packet
    gFIFO_LENGTH        : natural;
    gMAX_PAYLOAD_LENGTH : natural
  );
  port
  (
    CLK               : in  std_logic;
    RESET             : in  std_logic;
    TX_DATA           : in  std_logic_vector((gFIFO_WIDTH - 1) downto 0);
    TX_DATA_VALID     : in  std_logic;
    RX_DATA_READ      : in  std_logic;
    PACKET_REMOVED    : in  std_logic;
    UART_RX_PIN       : in  std_logic;
    PACKET_READY      : out std_logic;
    UART_TX_PIN       : out std_logic;
    RX_DATA           : out std_logic_vector((gFIFO_WIDTH - 1) downto 0);
    RX_DATA_VALID     : out std_logic;
	 LED               : out std_logic_vector(7 downto 0)
  );
  end component;
  
  component switch_engine
  generic
  (
    gNUM_PORTS               : natural;
    gADDRESS_WIDTH           : natural;
    gLEN_SUM_FIELD_WIDTH     : natural;
    gMAX_PAYLOAD_LENGTH      : natural
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
  end component;
  
  signal uart_tx_data        : std_logic_vector((gFIFO_WIDTH - 1) downto 0);
  signal uart_tx_data_valid  : std_logic;
  signal uart_rx_data_read   : std_logic;
  signal uart_rx_data        : std_logic_vector((gFIFO_WIDTH - 1) downto 0);
  signal uart_rx_data_valid  : std_logic_vector((gNUM_PORTS -1) downto 0);
  
  signal uart_packet_ready   : std_logic_vector((gNUM_PORTS - 1) downto 0);
  signal uart_port_in_data   : slv2d8((gNUM_PORTS - 1) downto 0);
  signal uart_port_in_data_taken : std_logic_vector((gNUM_PORTS - 1) downto 0);
  signal uart_port_in_packet_removed : std_logic_vector((gNUM_PORTS - 1) downto 0);
  signal uart_port_out_data : slv2d8 ((gNUM_PORTS - 1) downto 0);
  signal uart_port_out_valid : std_logic_vector((gNUM_PORTS - 1) downto 0);
  
  signal reset               : std_logic;
  
begin

reset <= not nRESET;

--uart_controller_1 : uart_controller 
--generic map
--(
--  gFIFO_WIDTH         => gFIFO_WIDTH,
--  gFIFO_LENGTH        => gFIFO_LENGTH,
--  gMAX_PAYLOAD_LENGTH => gMAX_PAYLOAD_BYTES
--)
--port map
--(
--  CLK => CLK,
--  RESET => reset,
--  TX_DATA => uart_port_out_data(0),
--  TX_DATA_VALID => uart_port_out_valid(0),
--  RX_DATA_READ => uart_port_in_data_taken(0),
--  PACKET_REMOVED => uart_port_in_packet_removed(0),
--  UART_RX_PIN => UART_RX_PINS(0),
--  PACKET_READY => uart_packet_ready(0),
--  UART_TX_PIN => UART_TX_PINS(0),
--  RX_DATA => uart_port_in_data(0),
--  RX_DATA_VALID => uart_rx_data_valid(0)
--  --LED => LED
--);
--
--uart_controller_2 : uart_controller 
--generic map
--(
--  gFIFO_WIDTH         => gFIFO_WIDTH,
--  gFIFO_LENGTH        => gFIFO_LENGTH,
--  gMAX_PAYLOAD_LENGTH => gMAX_PAYLOAD_BYTES
--)
--port map
--(
--  CLK => CLK,
--  RESET => reset,
--  TX_DATA => uart_port_out_data(1),
--  TX_DATA_VALID => uart_port_out_valid(1),
--  RX_DATA_READ => uart_port_in_data_taken(1),
--  PACKET_REMOVED => uart_port_in_packet_removed(1),
--  UART_RX_PIN => UART_RX_PINS(1),
--  PACKET_READY => uart_packet_ready(1),
--  UART_TX_PIN => UART_TX_PINS(1),
--  RX_DATA => uart_port_in_data(1),
--  RX_DATA_VALID => uart_rx_data_valid(1)
--  --LED => LED
--);

--begin 
GEN_UARTS: 
   for I in 0 to (gNUM_PORTS - 1) generate
      UART_CONTROLLERS : uart_controller 
		generic map
		(
		  gFIFO_WIDTH         => gFIFO_WIDTH,
		  gFIFO_LENGTH        => gFIFO_LENGTH,
		  gMAX_PAYLOAD_LENGTH => gMAX_PAYLOAD_BYTES
		)
		port map
		(
		  CLK => CLK,
		  RESET => reset,
		  TX_DATA => uart_port_out_data(I),
		  TX_DATA_VALID => uart_port_out_valid(I),
		  RX_DATA_READ => uart_port_in_data_taken(I),
		  PACKET_REMOVED => uart_port_in_packet_removed(I),
		  UART_RX_PIN => UART_RX_PINS(I),
		  PACKET_READY => uart_packet_ready(I),
		  UART_TX_PIN => UART_TX_PINS(I),
		  RX_DATA => uart_port_in_data(I),
		  RX_DATA_VALID => uart_rx_data_valid(I)
		);
   end generate GEN_UARTS;
--end GEN_UARTS;

--uart_controller_3 : uart_controller port map
--(
--  CLK => CLK,
--  RESET => reset,
--  TX_DATA => uart_port_out_data(2),
--  TX_DATA_VALID => uart_port_out_valid(2),
--  RX_DATA_READ => uart_port_in_data_taken(2),
--  PACKET_REMOVED => uart_port_in_packet_removed(2),
--  UART_RX_PIN => UART_RX_PINS(2),
--  PACKET_READY => uart_packet_ready(2),
--  UART_TX_PIN => UART_TX_PINS(2),
--  RX_DATA => uart_port_in_data(2),
--  RX_DATA_VALID => uart_rx_data_valid(2)
--  --LED => LED
--);
--
--uart_controller_4 : uart_controller port map
--(
--  CLK => CLK,
--  RESET => reset,
--  TX_DATA => uart_port_out_data(3),
--  TX_DATA_VALID => uart_port_out_valid(3),
--  RX_DATA_READ => uart_port_in_data_taken(3),
--  PACKET_REMOVED => uart_port_in_packet_removed(3),
--  UART_RX_PIN => UART_RX_PINS(3),
--  PACKET_READY => uart_packet_ready(3),
--  UART_TX_PIN => UART_TX_PINS(3),
--  RX_DATA => uart_port_in_data(3),
--  RX_DATA_VALID => uart_rx_data_valid(3)
--  --LED => LED
--);

switch_engine_inst : switch_engine
generic map
(
  gNUM_PORTS => gNUM_PORTS,
  gADDRESS_WIDTH => gADDRESS_WIDTH,
  gLEN_SUM_FIELD_WIDTH => gLEN_SUM_FIELD_WIDTH,
  gMAX_PAYLOAD_LENGTH => gMAX_PAYLOAD_BYTES
)
port map
(
  CLK => CLK,
  RESET => reset,
  PACKET_READY => uart_packet_ready,
  PORT_IN_DATA => uart_port_in_data,
  PORT_IN_DATA_TAKEN => uart_port_in_data_taken,
  PORT_IN_PACKET_REMOVED => uart_port_in_packet_removed,
  PORT_OUT_DATA => uart_port_out_data,
  PORT_OUT_VALID => uart_port_out_valid,
  LED => LED
);



--LED <= (others => '1');

end rtl;

