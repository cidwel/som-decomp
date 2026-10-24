; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C38C
.include "src/rom/event_command_macros.inc"
event_2D8_command_C38C:
    event_jump 1535
event_2D8_command_C38E:
    event_end 
