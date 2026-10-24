; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE7C
.include "src/rom/event_command_macros.inc"
event_326_command_CE7C:
    event_jump 817
event_326_command_CE7E:
    event_end 
event_327_command_CE7F:
    event_set_flag 249, 7
event_327_command_CE82:
    event_call 816
