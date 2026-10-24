; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BCFC
.include "src/rom/event_command_macros.inc"
event_2C2_command_BCFC:
    event_test_flag_range 59, 0, 1
event_2C2_command_BCFF:
    event_call 766
event_2C2_command_BD01:
    event_call 83
event_2C2_command_BD03:
    event_wait 0
