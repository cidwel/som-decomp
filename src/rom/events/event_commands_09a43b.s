; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A43B
.include "src/rom/event_command_macros.inc"
event_265_command_A43B:
    event_end 
event_266_command_A43C:
    event_call 1947
event_266_command_A43E:
    event_end 
