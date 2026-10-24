; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B57C
.include "src/rom/event_command_macros.inc"
event_2A6_command_B57C:
    event_jump 1535
event_2A6_command_B57E:
    event_end 
