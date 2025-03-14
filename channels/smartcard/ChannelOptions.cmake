set(OPTION_DEFAULT ON)
set(OPTION_CLIENT_DEFAULT ON)
set(OPTION_SERVER_DEFAULT OFF)

define_channel_options(
  NAME
  "smartcard"
  TYPE
  "device"
  DESCRIPTION
  "Smart Card Virtual Channel Extension"
  SPECIFICATIONS
  "[MS-RDPESC]"
  DEFAULT
  ${OPTION_DEFAULT}
  CLIENT_DEFAULT
  ${OPTION_CLIENT_DEFAULT}
  SERVER_DEFAULT
  ${OPTION_SERVER_DEFAULT}
)
