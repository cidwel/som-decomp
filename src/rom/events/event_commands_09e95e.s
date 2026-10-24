; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E95E
.include "src/rom/event_command_macros.inc"
event_3CE_command_E95E:
    event_test_flag_range 58, 3, 15
event_3CE_command_E961:
    event_jump 1535
event_3CE_command_E963:
    event_wait 0
