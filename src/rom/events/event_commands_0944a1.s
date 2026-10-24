; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44A1
.include "src/rom/event_command_macros.inc"
event_140_command_44A1:
    event_jump 1535
event_140_command_44A3:
    event_end 
event_141_command_44A4:
    event_test_flag_range 18, 0, 8
event_141_command_44A7:
    event_jump 334
