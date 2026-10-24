; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE3E
.include "src/rom/event_command_macros.inc"
event_320_command_CE3E:
    event_jump 817
event_320_command_CE40:
    event_end 
event_321_command_CE41:
    event_set_flag 249, 1
event_321_command_CE44:
    event_call 816
