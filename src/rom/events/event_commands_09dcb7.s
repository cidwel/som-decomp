; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DCB7
.include "src/rom/event_command_macros.inc"
event_391_command_DCB7:
    event_jump 1535
event_391_command_DCB9:
    event_end 
