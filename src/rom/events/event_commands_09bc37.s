; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BC37
.include "src/rom/event_command_macros.inc"
event_2BE_command_BC37:
    event_jump 1535
event_2BE_command_BC39:
    event_end 
