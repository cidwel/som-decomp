; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $48E2
.include "src/rom/event_command_macros.inc"
event_152_command_48E2:
    event_jump 1535
event_152_command_48E4:
    event_end 
event_153_command_48E5:
    event_test_flag_range 18, 9, 15
event_153_command_48E8:
    event_jump 349
