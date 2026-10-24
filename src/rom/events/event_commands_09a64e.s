; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A64E
.include "src/rom/event_command_macros.inc"
event_274_command_A64E:
    event_jump 1535
event_274_command_A650:
    event_end 
