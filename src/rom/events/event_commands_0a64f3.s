; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $64F3
.include "src/rom/event_command_macros.inc"
event_556_command_64F3:
    event_jump 1535
event_556_command_64F5:
    event_end 
