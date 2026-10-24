; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $48B0
.include "src/rom/event_command_macros.inc"
event_151_command_48B0:
    event_jump 1535
event_151_command_48B2:
    event_end 
event_152_command_48B3:
    event_test_flag_range 18, 9, 15
event_152_command_48B6:
    event_jump 349
