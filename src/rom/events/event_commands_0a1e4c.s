; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E4C
.include "src/rom/event_command_macros.inc"
event_4B0_command_1E4C:
    event_end 
event_4B1_command_1E4D:
    event_test_flag_range 63, 0, 5
event_4B1_command_1E50:
    event_jump 1202
event_4B1_command_1E52:
    event_test_flag_range 69, 0, 0
event_4B1_command_1E55:
    event_jump 1203
event_4B1_command_1E57:
    event_end 
