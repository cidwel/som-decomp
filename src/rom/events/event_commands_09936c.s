; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $936C
.include "src/rom/event_command_macros.inc"
event_210_command_936C:
    event_jump 1535
event_210_command_936E:
    event_end 
