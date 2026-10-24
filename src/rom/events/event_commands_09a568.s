; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A568
.include "src/rom/event_command_macros.inc"
event_26E_command_A568:
    event_jump 1535
event_26E_command_A56A:
    event_end 
