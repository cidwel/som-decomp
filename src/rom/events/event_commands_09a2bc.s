; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A2BC
.include "src/rom/event_command_macros.inc"
event_262_command_A2BC:
    event_jump 1535
event_262_command_A2BE:
    event_end 
