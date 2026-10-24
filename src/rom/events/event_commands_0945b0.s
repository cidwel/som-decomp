; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $45B0
.include "src/rom/event_command_macros.inc"
event_146_command_45B0:
    event_test_flag_range 168, 0, 0
event_146_command_45B3:
    event_jump 0
event_146_command_45B5:
    event_set_flag 18, 7
event_146_command_45B8:
    event_refresh_objects 
event_146_command_45B9:
    event_call 1939
