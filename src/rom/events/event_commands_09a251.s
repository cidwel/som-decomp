; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A251
.include "src/rom/event_command_macros.inc"
event_25E_command_A251:
    event_jump 1535
event_25E_command_A253:
    event_end 
