; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A625
.include "src/rom/event_command_macros.inc"
event_273_command_A625:
    event_jump 1535
event_273_command_A627:
    event_end 
