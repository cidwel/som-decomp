; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C3B4
.include "src/rom/event_command_macros.inc"
event_2D9_command_C3B4:
    event_jump 1535
event_2D9_command_C3B6:
    event_end 
