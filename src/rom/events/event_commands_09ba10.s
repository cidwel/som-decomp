; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BA10
.include "src/rom/event_command_macros.inc"
event_2B5_command_BA10:
    event_jump 1535
event_2B5_command_BA12:
    event_end 
