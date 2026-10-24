; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A6CA
.include "src/rom/event_command_macros.inc"
event_277_command_A6CA:
    event_jump 1535
event_277_command_A6CC:
    event_end 
