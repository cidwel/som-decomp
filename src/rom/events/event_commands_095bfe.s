; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5BFE
.include "src/rom/event_command_macros.inc"
event_18B_command_5BFE:
    event_jump 1535
event_18B_command_5C00:
    event_end 
event_18C_command_5C01:
    event_test_flag_range 18, 6, 8
event_18C_command_5C04:
    event_jump 406
